#!/bin/bash
# ---------------------------------------------------------------------------------------------------------------
#  build_dreamcast.sh -- compila Whisk3D para Sega Dreamcast.
#
#  Necesita (fuera del proyecto):
#    - KallistiOS compilado con su toolchain SH-4      (KOS_ENV, por defecto ~/dc/kos/environ.sh)
#    - GLdc instalado en kos-ports                      (cd $KOS_PORTS/libGL && make install)
#    - SDL2 de Dreamcast instalado                      (SDL2_DC, por defecto ~/dc/sdl2-dc-inst; rama dreamcastSDL2
#                                                         de github.com/GPF/SDL compilada con el toolchain de KOS)
#  Salida: platform/dreamcast/build/whisk3d.elf (el emulador Flycast lo abre directo) y, si esta mkdcdisc, el disco
#          autoarrancable build/whisk3d.cdi (emuladores, CD-R o una unidad tipo GDEMU).
#  Uso:    bash platform/dreamcast/build_dreamcast.sh [clean]
# ---------------------------------------------------------------------------------------------------------------
set -e
cd "$(dirname "$0")"
KOS_ENV="${KOS_ENV:-$HOME/dc/kos/environ.sh}"
[ -f "$KOS_ENV" ] || { echo "falta el entorno de KallistiOS: $KOS_ENV"; exit 1; }
source "$KOS_ENV"
export SDL2_DC="${SDL2_DC:-$HOME/dc/sdl2-dc-inst}"
[ -f "$SDL2_DC/lib/libSDL2.a" ] || { echo "falta SDL2 de Dreamcast en $SDL2_DC"; exit 1; }
make -j"${W3D_JOBS:-6}" "$@"
# el disco autoarrancable, si esta mkdcdisc (https://gitlab.com/simulant/mkdcdisc)
export MKDCDISC="${MKDCDISC:-$HOME/dc/mkdcdisc/build_manual/mkdcdisc}"
if [ -z "$*" ] && [ -x "$MKDCDISC" ]; then make cdi; fi
