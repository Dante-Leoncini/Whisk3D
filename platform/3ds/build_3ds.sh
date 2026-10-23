#!/bin/bash
# ---------------------------------------------------------------------------------------------------------------
#  build_3ds.sh -- compila Whisk3D para la Nintendo 3DS (build/whisk3d.3dsx). Antes, una vez: preparar_3ds.sh.
#  Los argumentos pasan a make (por ejemplo CAPTURA=5, o clean).
# ---------------------------------------------------------------------------------------------------------------
set -e
cd "$(dirname "$0")"
RAIZ3DS="${RAIZ3DS:-$HOME/3ds}"
export DEVKITPRO="${DEVKITPRO:-$RAIZ3DS/devkitpro}"
export DEVKITARM="${DEVKITARM:-$DEVKITPRO/devkitARM}"
export SDL2_3DS="${SDL2_3DS:-$RAIZ3DS/sdl2-3ds-inst}"
[ -x "$DEVKITARM/bin/arm-none-eabi-g++" ] || { echo "falta devkitARM en $DEVKITARM (correr preparar_3ds.sh)"; exit 1; }
[ -f "$DEVKITPRO/libctru/lib/libcitro3d.a" ] || { echo "falta citro3d en $DEVKITPRO/libctru (correr preparar_3ds.sh)"; exit 1; }
[ -f "$SDL2_3DS/lib/libSDL2.a" ] || { echo "falta SDL2 de 3DS en $SDL2_3DS (correr preparar_3ds.sh)"; exit 1; }
make -j"${W3D_JOBS:-$(nproc)}" "$@"
