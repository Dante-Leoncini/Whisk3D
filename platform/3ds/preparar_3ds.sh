#!/bin/bash
# ---------------------------------------------------------------------------------------------------------------
#  preparar_3ds.sh -- deja listo lo que hace falta FUERA del proyecto para compilar Whisk3D para la Nintendo 3DS
#  (en ~/3ds, o RAIZ3DS). Todo con los kits LIBRES de devkitPro (nada de Nintendo) y sin root:
#
#    1. devkitARM (binutils + gcc + newlib de devkitPro) compilado con sus buildscripts. Las fuentes salen de los
#       servidores de GNU y de sourceware, y las reglas y los crt de GitHub: no hace falta downloads.devkitpro.org
#       (que no siempre responde) ni el instalador con pacman (que va en /opt y pide root).
#    2. Las herramientas de devkitPro para la PC (de GitHub, compiladas directo, sin autotools): picasso (ensambla los
#       shaders de la GPU de la 3DS), 3dsxtool / smdhtool (arman el .3dsx y su icono) y bin2s.
#    3. libctru (el sistema de la 3DS) y citro3d (la GPU), de GitHub, instaladas en devkitpro/libctru.
#    4. SDL2 de 3DS (el del proyecto: thirdparty/SDL2 trae el port oficial) para el tactil, los botones y los eventos.
#    5. El emulador Azahar (fork de Citra) en ~/3ds/emu, para probar sin la consola. No va dentro del proyecto.
#    6. Para probar sin ventana (captura_azahar.sh): el emulador desarmado, Xvfb y xdotool (bajados con apt download,
#       sin root) y la configuracion del emulador con el log del juego.
#
#  Cada paso se saltea si ya esta hecho. Uso: bash platform/3ds/preparar_3ds.sh
#  Tarda: compilar gcc lleva un buen rato. Usa unos 5 GB mientras compila (se borran al terminar).
# ---------------------------------------------------------------------------------------------------------------
set -e
RAIZ3DS="${RAIZ3DS:-$HOME/3ds}"
JOBS="${W3D_JOBS:-$(nproc)}"
BUILDSCRIPTS_COMMIT=5740da9beb433ff9f5b724fafc1127f3a5ddc944
DEVKITPRO_DIR="$RAIZ3DS/devkitpro"
mkdir -p "$RAIZ3DS"

# ---- herramientas del sistema que el build de gcc necesita y que se arman aca si faltan ----
HOST="$RAIZ3DS/host"
export PATH="$HOST/bin:$PATH"
if ! command -v m4 > /dev/null; then
    echo "== m4 (lo pide GMP, una dependencia de gcc)"
    mkdir -p "$RAIZ3DS/fuentes" && cd "$RAIZ3DS/fuentes"
    [ -f m4-1.4.19.tar.xz ] || curl -sSfLO https://ftp.gnu.org/gnu/m4/m4-1.4.19.tar.xz
    rm -rf m4-1.4.19 && tar -xf m4-1.4.19.tar.xz && cd m4-1.4.19
    (./configure --prefix="$HOST" && make -j"$JOBS" && make install) > "$RAIZ3DS/m4_build.log" 2>&1 \
        || { echo "fallo (ver $RAIZ3DS/m4_build.log)"; exit 1; }
fi

# sin texinfo: un makeinfo que deja vacio el archivo de salida (newlib arma su documentacion aunque no se pida)
if ! command -v makeinfo > /dev/null; then
    mkdir -p "$HOST/bin"
    cat > "$HOST/bin/makeinfo" <<'FIN'
#!/bin/sh
# (preparar_3ds.sh: sin texinfo no se arma la documentacion; deja vacio el archivo de salida)
salida=""
while [ $# -gt 0 ]; do
    case "$1" in -o) salida="$2"; shift ;; --output=*) salida="${1#--output=}" ;; --version) echo "makeinfo (texinfo) 7.0"; exit 0 ;; esac
    shift
done
[ -n "$salida" ] && : > "$salida"
exit 0
FIN
    chmod +x "$HOST/bin/makeinfo"
fi

# ---- 2. herramientas de devkitPro para la PC (picasso, 3dsxtool, smdhtool, bin2s) ----
TOOLS="$DEVKITPRO_DIR/tools/bin"
herramienta() {   # repo tag: la clona (si no esta) en el tag pedido
    [ -d "$RAIZ3DS/fuentes/$1" ] || git clone -q --depth 1 -b "$2" https://github.com/devkitPro/$1.git "$RAIZ3DS/fuentes/$1"
}
if [ ! -x "$TOOLS/picasso" ] || [ ! -x "$TOOLS/3dsxtool" ] || [ ! -x "$TOOLS/smdhtool" ] || [ ! -x "$TOOLS/bin2s" ]; then
    echo "== herramientas: picasso, 3dsxtool, smdhtool, bin2s"
    mkdir -p "$TOOLS" "$RAIZ3DS/fuentes"
    herramienta picasso v2.7.2; herramienta 3dstools v1.3.1; herramienta general-tools v1.4.4
    F="$RAIZ3DS/fuentes"
    g++ -O2 -DPACKAGE_STRING='"picasso 2.7.2"' -o "$TOOLS/picasso" "$F"/picasso/source/picasso_assembler.cpp "$F"/picasso/source/picasso_frontend.cpp
    g++ -O2 -o "$TOOLS/3dsxtool" "$F"/3dstools/src/3dsxtool.cpp "$F"/3dstools/src/romfs.cpp
    g++ -O2 -o "$TOOLS/smdhtool" "$F"/3dstools/src/smdhtool.cpp "$F"/3dstools/src/lodepng/lodepng.cpp
    gcc -O2 -DPACKAGE_STRING='"bin2s - general-tools 1.4.4"' -o "$TOOLS/bin2s" "$F"/general-tools/bin2s.c
fi
export PATH="$TOOLS:$PATH"

# ---- 1. devkitARM ----
if [ ! -f "$DEVKITPRO_DIR/devkitARM/base_rules" ]; then   # (las reglas se instalan al final: si estan, esta todo)
    echo "== devkitARM: buildscripts de devkitPro"
    BS="$RAIZ3DS/buildscripts"
    [ -d "$BS" ] || git clone -q https://github.com/devkitPro/buildscripts.git "$BS"
    cd "$BS" && git checkout -q "$BUILDSCRIPTS_COMMIT"
    # las versiones que pide este commit de los buildscripts
    BINUTILS_VER=$(sed -n '/"1" )/,/;;/p' select_toolchain.sh | grep -m1 -o 'BINUTILS_VER=[0-9.]*' | cut -d= -f2)
    GCC_VER=$(sed -n '/"1" )/,/;;/p' select_toolchain.sh | grep -m1 -o 'GCC_VER=[0-9.]*' | cut -d= -f2)
    NEWLIB_VER=$(sed -n '/"1" )/,/;;/p' select_toolchain.sh | grep -m1 -o 'NEWLIB_VER=[0-9.]*' | cut -d= -f2)
    RULES_VER=$(grep -m1 -o 'DKARM_RULES_VER=[0-9.]*' build-devkit.sh | cut -d= -f2)
    CRTLS_VER=$(grep -m1 -o 'DKARM_CRTLS_VER=[0-9.]*' build-devkit.sh | cut -d= -f2)
    echo "   binutils $BINUTILS_VER, gcc $GCC_VER, newlib $NEWLIB_VER, rules $RULES_VER, crtls $CRTLS_VER"
    # las fuentes, de los servidores de origen (los buildscripts las buscan en downloads.devkitpro.org)
    [ -f binutils-$BINUTILS_VER.tar.xz ] || curl -sSfLO https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VER.tar.xz
    [ -f gcc-$GCC_VER.tar.xz ] || curl -sSfLO https://ftp.gnu.org/gnu/gcc/gcc-$GCC_VER/gcc-$GCC_VER.tar.xz
    [ -f newlib-$NEWLIB_VER.tar.gz ] || curl -sSfLO https://sourceware.org/pub/newlib/newlib-$NEWLIB_VER.tar.gz
    [ -f devkitarm-rules-$RULES_VER.tar.gz ] || \
        curl -sSfL -o devkitarm-rules-$RULES_VER.tar.gz https://github.com/devkitPro/devkitarm-rules/archive/refs/tags/v$RULES_VER.tar.gz
    [ -f devkitarm-crtls-$CRTLS_VER.tar.gz ] || \
        curl -sSfL -o devkitarm-crtls-$CRTLS_VER.tar.gz https://github.com/devkitPro/devkitarm-crtls/archive/refs/tags/v$CRTLS_VER.tar.gz
    # el destino: ~/3ds/devkitpro en vez de /opt/devkitpro (el toolchain es relocalizable: DEVKITPRO/DEVKITARM)
    sed -i "s|^INSTALLDIR=.*|INSTALLDIR=$DEVKITPRO_DIR|" build-devkit.sh
    # (las reglas y los crt se instalan abajo: sus Makefiles van fijo a /opt/devkitpro)
    printf 'BUILD_DKPRO_PACKAGE=1\nBUILD_DKPRO_AUTOMATED=1\nBUILD_DKPRO_SKIP_CRTLS=1\n' > config.sh
    if [ ! -x "$DEVKITPRO_DIR/devkitARM/bin/arm-none-eabi-g++" ] || [ ! -f "$DEVKITPRO_DIR/devkitARM/arm-none-eabi/lib/libc.a" ]; then
        MAKEFLAGS="-j$JOBS" ./build-devkit.sh > "$RAIZ3DS/devkitarm_build.log" 2>&1 \
            || { echo "fallo (ver $RAIZ3DS/devkitarm_build.log)"; exit 1; }
    fi
    git checkout -q build-devkit.sh
    # las reglas de make (base_rules, 3ds_rules...) y los crt/linkscripts (3dsx.specs...), en DEVKITPRO_DIR
    echo "   reglas $RULES_VER y crt $CRTLS_VER"
    T="$RAIZ3DS/fuentes/crtls" && rm -rf "$T" && mkdir -p "$T" && cd "$T"
    tar -xf "$BS/devkitarm-rules-$RULES_VER.tar.gz" && tar -xf "$BS/devkitarm-crtls-$CRTLS_VER.tar.gz"
    (cd devkitarm-rules-$RULES_VER && cp 3ds_rules base_rules base_tools ds_rules gba_rules gp32_rules "$DEVKITPRO_DIR/devkitARM/")
    (cd devkitarm-crtls-$CRTLS_VER && DEVKITPRO="$DEVKITPRO_DIR" DEVKITARM="$DEVKITPRO_DIR/devkitARM" \
        PATH="$DEVKITPRO_DIR/devkitARM/bin:$PATH" make all > "$RAIZ3DS/crtls_build.log" 2>&1 \
        && cp *.specs *.ld *.mem "$DEVKITPRO_DIR/devkitARM/arm-none-eabi/lib/" \
        && cp -r thumb armv6k *.o "$DEVKITPRO_DIR/devkitARM/arm-none-eabi/lib/") \
        || { echo "fallo (ver $RAIZ3DS/crtls_build.log)"; exit 1; }
    cd "$RAIZ3DS" && rm -rf "$T"
    # EL limits.h DE GCC ENCADENADO AL DE NEWLIB: la primera etapa de gcc se configura antes de que esten los
    # encabezados de newlib, y en una instalacion desde cero queda el limits.h "suelto" (sin PATH_MAX y los demas de
    # newlib: libctru no compila). Se arma como lo arma gcc cuando el sistema tiene el suyo: limitx + glimits + limity
    GCCINC="$DEVKITPRO_DIR/devkitARM/lib/gcc/arm-none-eabi/$GCC_VER/include"
    T="$RAIZ3DS/fuentes/gcclimits" && rm -rf "$T" && mkdir -p "$T"
    tar -xf "$BS/gcc-$GCC_VER.tar.xz" -C "$T" gcc-$GCC_VER/gcc/limitx.h gcc-$GCC_VER/gcc/glimits.h gcc-$GCC_VER/gcc/limity.h
    cat "$T/gcc-$GCC_VER/gcc/limitx.h" "$T/gcc-$GCC_VER/gcc/glimits.h" "$T/gcc-$GCC_VER/gcc/limity.h" > "$GCCINC/limits.h"
    rm -rf "$T"
fi
export DEVKITPRO="$DEVKITPRO_DIR"
export DEVKITARM="$DEVKITPRO/devkitARM"
echo "devkitARM: $("$DEVKITARM/bin/arm-none-eabi-gcc" --version | head -1)"

# ---- 3. libctru y citro3d ----
# (libctru de la rama principal: la v2.7.0 no compila con el gcc 16 de los buildscripts de hoy)
LIBCTRU_COMMIT=9b55eda44cf80b971503991e0c78f9bc8fe50425
CITRO3D_TAG=v1.7.1
if [ ! -f "$DEVKITPRO/libctru/lib/libctru.a" ]; then
    echo "== libctru ${LIBCTRU_COMMIT:0:7}"
    [ -d "$RAIZ3DS/fuentes/libctru" ] || git clone -q https://github.com/devkitPro/libctru.git "$RAIZ3DS/fuentes/libctru"
    (cd "$RAIZ3DS/fuentes/libctru" && git fetch -q origin && git checkout -q "$LIBCTRU_COMMIT")
    (cd "$RAIZ3DS/fuentes/libctru/libctru" && make -j"$JOBS" && make install) > "$RAIZ3DS/libctru_build.log" 2>&1 \
        || { echo "fallo (ver $RAIZ3DS/libctru_build.log)"; exit 1; }
fi
if [ ! -f "$DEVKITPRO/libctru/lib/libcitro3d.a" ]; then
    echo "== citro3d $CITRO3D_TAG"
    herramienta citro3d $CITRO3D_TAG
    (cd "$RAIZ3DS/fuentes/citro3d" && make -j"$JOBS" && make install) > "$RAIZ3DS/citro3d_build.log" 2>&1 \
        || { echo "fallo (ver $RAIZ3DS/citro3d_build.log)"; exit 1; }
fi

# ---- 4. SDL2 de 3DS (el del proyecto) ----
PROYECTO="$(cd "$(dirname "$0")/../.." && pwd)"
SDL_INST="${SDL2_3DS:-$RAIZ3DS/sdl2-3ds-inst}"
if [ ! -f "$SDL_INST/lib/libSDL2.a" ]; then
    echo "== SDL2 de 3DS"
    rm -rf "$RAIZ3DS/sdl2-3ds-build"
    (cmake -S "$PROYECTO/thirdparty/SDL2" -B "$RAIZ3DS/sdl2-3ds-build" -DCMAKE_TOOLCHAIN_FILE="$PROYECTO/platform/3ds/3ds.cmake" \
        -DCMAKE_BUILD_TYPE=Release -DSDL_SHARED=OFF -DSDL_STATIC=ON -DSDL_TEST=OFF -DCMAKE_INSTALL_PREFIX="$SDL_INST" \
        && cmake --build "$RAIZ3DS/sdl2-3ds-build" -j"$JOBS" && cmake --install "$RAIZ3DS/sdl2-3ds-build") \
        > "$RAIZ3DS/sdl2_build.log" 2>&1 || { echo "fallo (ver $RAIZ3DS/sdl2_build.log)"; exit 1; }
    rm -rf "$RAIZ3DS/sdl2-3ds-build"
fi

# ---- 5. el emulador ----
AZAHAR_VER=2126.2
if [ ! -x "$RAIZ3DS/emu/azahar.AppImage" ]; then
    echo "== Azahar $AZAHAR_VER (emulador)"
    mkdir -p "$RAIZ3DS/emu"
    curl -sSfL -o "$RAIZ3DS/emu/azahar.AppImage" https://github.com/azahar-emu/azahar/releases/download/$AZAHAR_VER/azahar.AppImage
    chmod +x "$RAIZ3DS/emu/azahar.AppImage"
fi

# ---- 6. para probar sin ventana (captura_azahar.sh): el emulador desarmado, un X virtual y xdotool ----
EMU="$RAIZ3DS/emu"
if [ ! -x "$EMU/squashfs-root/AppRun" ]; then
    echo "== Azahar: desarmando el AppImage (asi corre sin FUSE)"
    (cd "$EMU" && ./azahar.AppImage --appimage-extract > /dev/null)
fi
if [ ! -x "$RAIZ3DS/host/pkg/usr/bin/Xvfb" ] || [ ! -x "$RAIZ3DS/host/pkg/usr/bin/xdotool" ]; then
    # (los paquetes del sistema bajados con apt download y desarmados en host/pkg: sin root ni instalar nada)
    echo "== Xvfb y xdotool"
    mkdir -p "$RAIZ3DS/host/deb" && cd "$RAIZ3DS/host/deb"
    apt download xvfb xdotool libxdo3 > /dev/null 2>&1 || echo "   no se pudieron bajar: captura_azahar.sh necesita Xvfb y xdotool"
    for d in *.deb; do [ -f "$d" ] && dpkg -x "$d" "$RAIZ3DS/host/pkg"; done
fi
# su configuracion y su SD quedan en emu/home (no en la del usuario). El log anota lo que escribe el juego
# (svcOutputDebugString: lo que Whisk3D manda al log) y lo escribe en el momento
CONF="$EMU/home/config/azahar-emu/qt-config.ini"
if [ ! -f "$CONF" ]; then
    mkdir -p "$(dirname "$CONF")" "$EMU/home/data/azahar-emu/sdmc/3ds"
    cat > "$CONF" <<'FIN'
[Miscellaneous]
log_filter=*:Info Debug.Emulated:Debug
log_filter\default=false
check_for_update_on_start=false
check_for_update_on_start\default=false
enable_gamemode=false
enable_gamemode\default=false

[Debugging]
instant_debug_log=true
instant_debug_log\default=false
FIN
fi
if [ ! -f "$EMU/azahar.sh" ]; then
    cat > "$EMU/azahar.sh" <<'FIN'
#!/bin/bash
# Azahar (emulador de 3DS, fork de Citra) con su propia configuracion y su SD en ~/3ds/emu/home.
# --sinventana: adentro de un X virtual (Xvfb en el display :77, sin tocar el escritorio), para pruebas automaticas.
AQUI="$(cd "$(dirname "$0")" && pwd)"
export XDG_CONFIG_HOME="$AQUI/home/config" XDG_DATA_HOME="$AQUI/home/data" XDG_CACHE_HOME="$AQUI/home/cache"
mkdir -p "$XDG_CONFIG_HOME" "$XDG_DATA_HOME/azahar-emu/sdmc/3ds" "$XDG_CACHE_HOME"
if [ "$1" = "--sinventana" ]; then
    shift
    export DISPLAY="${W3D_XVFB_DISPLAY:-:77}" QT_QPA_PLATFORM=xcb WAYLAND_DISPLAY=
    if ! xdpyinfo -display "$DISPLAY" > /dev/null 2>&1; then
        "$AQUI/../host/pkg/usr/bin/Xvfb" "$DISPLAY" -screen 0 1024x768x24 -nolisten tcp > /dev/null 2>&1 &
        XVFB=$!
        trap 'kill $XVFB 2>/dev/null' EXIT
        sleep 1
    fi
    "$AQUI/squashfs-root/AppRun" "$@"
    exit $?
fi
exec "$AQUI/squashfs-root/AppRun" "$@"
FIN
    chmod +x "$EMU/azahar.sh"
fi
echo "Listo. Compilar: bash platform/3ds/build_3ds.sh"
