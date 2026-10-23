#!/bin/bash
# ---------------------------------------------------------------------------------------------------------------
#  captura_azahar.sh -- ver en la PC lo que dibuja Whisk3D en la 3DS, sin la consola ni una ventana en el escritorio.
#
#  Corre build/whisk3d.3dsx en Azahar (el emulador, ~/3ds/emu: lo deja preparar_3ds.sh) adentro de un X virtual
#  (Xvfb, display :77), espera a que arranque, opcionalmente toca la pantalla de abajo y captura las dos pantallas:
#    <salida>_arriba.png (400x240) y <salida>_abajo.png (320x240, la tactil). El log del juego queda en build/azahar.log.
#
#  Uso: bash platform/3ds/captura_azahar.sh [segundos=25] [salida=build/captura]
#  TOQUES="x,y x,y" antes del comando: toques en la pantalla de abajo (pixeles de la 3DS, 0..319 x 0..239), uno por
#  segundo despues de arrancar. "x,y>x2,y2" arrastra de un punto al otro.
#  TECLAS="tecla tecla:ms": despues de los toques, botones de la consola por el teclado de la PC (lo que tiene puesto
#  Azahar): a=A s=B z=X x=Y q=L w=R 1=ZL 2=ZR m=Start n=Select, cruceta t/g/f/h, circle pad = flechas (Up Down Left
#  Right), C-stick i/k/j/l. ":ms" la mantiene apretada ese tiempo (sin eso, 150 ms).
# ---------------------------------------------------------------------------------------------------------------
set -e
cd "$(dirname "$0")"
SEGUNDOS="${1:-25}"
SALIDA="${2:-build/captura}"
RAIZ3DS="${RAIZ3DS:-$HOME/3ds}"
EMU="$RAIZ3DS/emu"
PKG="$RAIZ3DS/host/pkg"
XDO="$PKG/usr/bin/xdotool"
export LD_LIBRARY_PATH="$PKG/usr/lib/x86_64-linux-gnu${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
[ -f build/whisk3d.3dsx ] || { echo "falta build/whisk3d.3dsx (bash build_3ds.sh)"; exit 1; }
[ -x "$EMU/squashfs-root/AppRun" ] && [ -x "$PKG/usr/bin/Xvfb" ] && [ -x "$XDO" ] || { echo "falta el emulador o Xvfb/xdotool (preparar_3ds.sh)"; exit 1; }
export DISPLAY=:77 QT_QPA_PLATFORM=xcb WAYLAND_DISPLAY=
export XDG_CONFIG_HOME="$EMU/home/config" XDG_DATA_HOME="$EMU/home/data" XDG_CACHE_HOME="$EMU/home/cache"
mkdir -p "$XDG_DATA_HOME/azahar-emu/sdmc/3ds"
LOGEMU="$XDG_DATA_HOME/azahar-emu/log/azahar_log.txt"

"$PKG/usr/bin/Xvfb" :77 -screen 0 1024x768x24 -nolisten tcp > /dev/null 2>&1 &
XVFB=$!
sleep 1
"$EMU/squashfs-root/AppRun" "$PWD/build/whisk3d.3dsx" > build/azahar_qt.log 2>&1 &
EMUPID=$!
trap 'kill $EMUPID 2>/dev/null; sleep 1; kill $XVFB 2>/dev/null' EXIT

# la ventana: las dos pantallas van centradas debajo de la barra de menu, sin escalar (arriba 400x240, abajo 320x240)
VENTANA=$(timeout 60 "$XDO" search --sync --onlyvisible --name "Azahar" | head -1)
sleep "$SEGUNDOS"
eval "$("$XDO" getwindowgeometry --shell "$VENTANA")"   # X Y WIDTH HEIGHT
BARRA=22
X0=$((X + (WIDTH - 400) / 2)); Y0=$((Y + BARRA))       # la pantalla de arriba
XA=$((X0 + 40)); YA=$((Y0 + 240))                       # la de abajo
for t in ${TOQUES:-}; do
    if [[ "$t" == *">"* ]]; then
        a="${t%%>*}"; b="${t##*>}"
        "$XDO" mousemove $((XA + ${a%%,*})) $((YA + ${a##*,})) mousedown 1
        sleep 0.3
        "$XDO" mousemove $((XA + ${b%%,*})) $((YA + ${b##*,}))
        sleep 0.3
        "$XDO" mouseup 1
    else
        # (un toque de verdad dura algo: un click instantaneo cae entre dos lecturas del tactil y la consola no lo ve)
        "$XDO" mousemove $((XA + ${t%%,*})) $((YA + ${t##*,})) mousedown 1
        sleep 0.15
        "$XDO" mouseup 1
    fi
    sleep 1
done
[ -n "${TECLAS:-}" ] && "$XDO" windowfocus --sync "$VENTANA" 2>/dev/null || true
for k in ${TECLAS:-}; do
    tecla="${k%%:*}"; ms=150
    [[ "$k" == *:* ]] && ms="${k##*:}"
    "$XDO" keydown --window "$VENTANA" "$tecla"
    sleep "$(awk "BEGIN { print $ms / 1000 }")"
    "$XDO" keyup --window "$VENTANA" "$tecla"
    sleep 0.5
done
sleep 1
import -window root build/captura_pantalla.png
convert build/captura_pantalla.png -crop 400x240+$X0+$Y0 +repage "${SALIDA}_arriba.png"
convert build/captura_pantalla.png -crop 320x240+$XA+$YA +repage "${SALIDA}_abajo.png"
grep -a "Debug.Emulated\|<Critical>\|<Error>" "$LOGEMU" > build/azahar.log 2>/dev/null || true
echo "capturas: ${SALIDA}_arriba.png ${SALIDA}_abajo.png (log: build/azahar.log)"
