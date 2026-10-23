#!/bin/bash
# ---------------------------------------------------------------------------------------------------------------
#  preparar_dreamcast.sh -- deja listo lo que build_dreamcast.sh necesita FUERA del proyecto (en ~/dc, o DC_RAIZ):
#
#    1. KallistiOS compilado (necesita su toolchain SH-4 ya armada: ~/dc/toolchains/dc/sh-elf; se arma una vez con
#       kos/utils/kos-chain, ver su documentacion. Tarda: compila gcc).
#    2. GLdc (kos-ports/libGL, el OpenGL 1.x de la PVR) con parches/gldc.patch:
#         - el literal 127.5 en doble precision de _glPackNormal (el SH-4 terminaba con el FPU en modo doble antes de
#           la instruccion FTRV: en la consola real es una instruccion ilegal)
#         - las normales GL_BYTE leidas CON signo (se leian como sin signo: la luz salia mal)
#         - la luz direccional: la direccion HACIA la luz (estaba negada) y rotada con la modelview, como GL
#         - las lineas: el ancho medido en pantalla (no punteadas de lejos), recortadas contra el plano cercano antes
#           de ensancharlas (un eje que pasa por detras de la camara salia como una franja enorme) y apenas hacia la
#           camara (sin glPolygonOffset las aristas peleaban con sus caras)
#         - los puntos con la textura entera (UV de 0 a 1 en las esquinas: point sprites)
#         - el scissor: sin recortar lo que cae entero adentro (era la mitad del cuadro), sin pisar la entrada y
#           tambien para lineas y puntos (la PVR sola recorta por bloques de 32x32)
#         - el fin de cuadro sin esperar a la PVR (dibuja un cuadro mientras la CPU arma el siguiente)
#         - glTexSubImage2D con conversion: ya no borra el resto de la textura (el trazado de rayos sube de a tiles)
#    3. SDL2 de Dreamcast (github.com/GPF/SDL, rama dreamcastSDL2) con parches/sdl2-dreamcast.patch: el teclado por
#       SDL_SendKeyboardKey (modificadores y estado de SDL bien) y el texto con la distribucion del teclado (ñ).
#    4. mkdcdisc (gitlab.com/simulant/mkdcdisc), para el disco .cdi. Opcional.
#
#  Cada paso se saltea si ya esta hecho. Uso: bash platform/dreamcast/preparar_dreamcast.sh
# ---------------------------------------------------------------------------------------------------------------
set -e
AQUI="$(cd "$(dirname "$0")" && pwd)"
DC="${DC_RAIZ:-$HOME/dc}"
JOBS="${W3D_JOBS:-6}"
SDL2_COMMIT=10f41e6820708efc74fb194db7d49bcc07a0b7e7
MKDCDISC_COMMIT=2b98b0d9480e364e3517355648fbc3b49fb19882

# ---- 1. KallistiOS ----
[ -x "$DC/toolchains/dc/sh-elf/bin/sh-elf-gcc" ] || { echo "falta la toolchain SH-4 en $DC/toolchains/dc/sh-elf (armarla con $DC/kos/utils/kos-chain)"; exit 1; }
[ -d "$DC/kos" ] || { echo "falta KallistiOS en $DC/kos (git clone https://github.com/KallistiOS/KallistiOS.git $DC/kos)"; exit 1; }
if [ ! -f "$DC/kos/environ.sh" ]; then
    echo "== KallistiOS: environ.sh"
    sed -e "s|^export KOS_BASE=.*|export KOS_BASE=\"$DC/kos\"|" \
        -e "s|^export KOS_CC_BASE=.*|export KOS_CC_BASE=\"$DC/toolchains/dc/sh-elf\"|" \
        -e "s|^export DC_ARM_BASE=.*|export DC_ARM_BASE=\"$DC/toolchains/dc/arm-eabi\"|" \
        -e "s|^export DC_TOOLS_BASE=.*|export DC_TOOLS_BASE=\"$DC/toolchains/dc/bin\"|" \
        "$DC/kos/doc/environ.sh.sample" > "$DC/kos/environ.sh"
fi
source "$DC/kos/environ.sh"
if [ ! -f "$KOS_BASE/lib/dreamcast/libkallisti.a" ]; then
    echo "== KallistiOS: compilando"
    (cd "$KOS_BASE" && make -j"$JOBS") > "$DC/kos_build.log" 2>&1 || { echo "fallo (ver $DC/kos_build.log)"; exit 1; }
fi

# ---- 2. GLdc con los parches ----
GLDC="$KOS_PORTS/libGL/build/libGL-1.1.1"
if [ ! -f "$KOS_PORTS/lib/libGL.a" ]; then
    echo "== GLdc: bajando y compilando (kos-ports)"
    (cd "$KOS_PORTS/libGL" && make install) > "$DC/gldc_build.log" 2>&1 || { echo "fallo (ver $DC/gldc_build.log)"; exit 1; }
fi
if (cd "$GLDC" && patch -p1 -N --dry-run -s < "$AQUI/parches/gldc.patch" > /dev/null 2>&1); then
    echo "== GLdc: aplicando parches/gldc.patch"
    (cd "$GLDC" && patch -p1 -N -s < "$AQUI/parches/gldc.patch")
    (cd "$GLDC" && make GL) > "$DC/gldc_rebuild.log" 2>&1 || { echo "fallo (ver $DC/gldc_rebuild.log)"; exit 1; }
    cp "$GLDC/libGL.a" "$KOS_PORTS/libGL/inst/lib/libGL.a"
fi

# ---- 3. SDL2 de Dreamcast con el parche ----
SDL_SRC="$DC/sdl2-dc"; SDL_BUILD="$DC/sdl2-dc-build"; SDL_INST="${SDL2_DC:-$DC/sdl2-dc-inst}"
if [ ! -d "$SDL_SRC" ]; then
    echo "== SDL2 de Dreamcast: bajando"
    git clone -b dreamcastSDL2 https://github.com/GPF/SDL.git "$SDL_SRC" > /dev/null 2>&1
    (cd "$SDL_SRC" && git checkout -q "$SDL2_COMMIT")
fi
PARCHE_SDL=0
if (cd "$SDL_SRC" && patch -p1 -N --dry-run -s < "$AQUI/parches/sdl2-dreamcast.patch" > /dev/null 2>&1); then
    echo "== SDL2 de Dreamcast: aplicando parches/sdl2-dreamcast.patch"
    (cd "$SDL_SRC" && patch -p1 -N -s < "$AQUI/parches/sdl2-dreamcast.patch")
    PARCHE_SDL=1
fi
if [ "$PARCHE_SDL" = 1 ] || [ ! -f "$SDL_INST/lib/libSDL2.a" ]; then
    echo "== SDL2 de Dreamcast: compilando"
    mkdir -p "$SDL_BUILD"
    (cd "$SDL_BUILD" && cmake -DCMAKE_TOOLCHAIN_FILE="$KOS_CMAKE_TOOLCHAIN" -G "Unix Makefiles" -DSDL_OPENGL=ON -DSDL_HAPTIC=ON \
        -DSDL_TEST=OFF -DSDL_TESTS=OFF -DSDL_VIDEO_RENDER_DREAMCAST_PVR=ON -DSDL_PTHREADS=ON -DSDL_TIMER_UNIX=ON \
        -DCMAKE_INSTALL_PREFIX="$SDL_INST" -DCMAKE_INSTALL_LIBDIR=lib -DCMAKE_INSTALL_INCLUDEDIR=include "$SDL_SRC" \
        && make -j"$JOBS" && make install) > "$DC/sdl2_build.log" 2>&1 || { echo "fallo (ver $DC/sdl2_build.log)"; exit 1; }
fi

# ---- 4. mkdcdisc (opcional: sin el, build_dreamcast.sh deja solo el .elf) ----
MK="$DC/mkdcdisc"
if [ ! -x "$MK/build_manual/mkdcdisc" ]; then
    echo "== mkdcdisc: bajando y compilando"
    [ -d "$MK" ] || { git clone https://gitlab.com/simulant/mkdcdisc.git "$MK" > /dev/null 2>&1 && (cd "$MK" && git checkout -q "$MKDCDISC_COMMIT"); }
    LIBISOFS=$(ls /usr/lib/*/libisofs.so.6 2>/dev/null | head -1)
    if [ -z "$LIBISOFS" ]; then
        echo "   (sin libisofs del sistema -instalar xorriso o libisofs6-: no se arma el .cdi)"
    else
        mkdir -p "$MK/build_manual"
        (
            cd "$MK/build_manual"
            sed 's/@VERSION_STRING@/0.0.4/' ../src/version.h.in > version.h
            for f in $(sed -n '/project_sources = files(/,/^)/p' ../meson.build | grep -o "src/[a-z_/]*\.cpp"); do
                g++ -c -O2 -std=c++17 -I. -I../src -I../src/third_party/libisofs/libisofs "../$f" -o "$(echo $f | tr / _).o"
            done
            for f in src/third_party/libedc/edc_ecc.c src/disc_image/formats/cdi.c src/disc_image/formats/mds.c \
                     src/disc_image/formats/nrg.c src/disc_image/formats/gdi.c src/disc_image/disc_image.c src/disc_image/raw_sector.c; do
                gcc -c -O2 -std=c99 -I../src -I../src/third_party/libedc "../$f" -o "c_$(echo $f | tr / _).o"
            done
            g++ -o mkdcdisc *.o "$LIBISOFS" -lz -lpthread
        ) > "$DC/mkdcdisc_build.log" 2>&1 || echo "   (mkdcdisc no compilo: ver $DC/mkdcdisc_build.log)"
    fi
fi
echo "Listo. Compilar: bash platform/dreamcast/build_dreamcast.sh"
