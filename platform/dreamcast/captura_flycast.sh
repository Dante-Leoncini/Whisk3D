#!/bin/bash
# ---------------------------------------------------------------------------------------------------------------
#  captura_flycast.sh -- ver en la PC lo que dibuja Whisk3D en la Dreamcast, sin la consola ni una ventana.
#
#  Compila con CAPTURA=<cuadro> (la pantalla sale en base64 por la consola serie en ese cuadro), lo corre en Flycast
#  sin ventana con la consola serie prendida y convierte la captura en PNG.
#
#  Necesita Flycast con la consola serie a stdout (Debug.SerialConsoleEnabled = yes en su emu.cfg). FLYCAST es el
#  comando que lo corre (por defecto ~/dc/emu/flycast.sh, que usa su propia configuracion).
#  Uso: bash platform/dreamcast/captura_flycast.sh [cuadro=2] [salida.png=build/captura.png] [segundos=180]
#  PRUEBA=n antes del comando: antes de capturar empuja eventos de teclado y mouse (1: Tab + click en el menu del modo;
#  2: mover el cubo con G, X y el mouse; 3: seleccionar con click; 4: arrastrar el borde de un viewport;
#  5: modo edicion y click en un vertice; 6: trazado de rayos;
#  7: pintura de textura).
#  (el editor solo dibuja cuando algo cambia: quieto se queda en los primeros cuadros. La consola serie emulada es
#  lenta: una captura de 640x480 tarda cerca de un minuto)
# ---------------------------------------------------------------------------------------------------------------
set -e
cd "$(dirname "$0")"
CUADRO="${1:-2}"
SALIDA="${2:-build/captura.png}"
SEGUNDOS="${3:-180}"   # (la consola serie emulada es lenta: una captura de 640x480 tarda ~1 minuto)
FLYCAST="${FLYCAST:-$HOME/dc/emu/flycast.sh}"
[ -x "$FLYCAST" ] || { echo "no encuentro Flycast: $FLYCAST"; exit 1; }

rm -f build/obj/platform/dreamcast/w3d_dreamcast.o   # (el define CAPTURA solo lo mira ese archivo)
bash build_dreamcast.sh CAPTURA="$CUADRO" ${PRUEBA:+PRUEBA=$PRUEBA} > build/captura_compila.log 2>&1 || { echo "fallo la compilacion (build/captura_compila.log)"; exit 1; }
rm -f build/obj/platform/dreamcast/w3d_dreamcast.o   # (el proximo build normal queda sin captura)

LOG=build/captura_flycast.log
# (rend.EmulateFramebuffer: que Flycast escriba lo dibujado en la memoria de video emulada, que es lo que se captura)
SDL_VIDEODRIVER=offscreen timeout "$SEGUNDOS" "$FLYCAST" --sinventana -config config:rend.EmulateFramebuffer=yes "$PWD/build/whisk3d.elf" > "$LOG" 2>&1 &
PID=$!
# se corta apenas llega la captura (no hace falta esperar el tiempo entero)
for _ in $(seq 1 "$SEGUNDOS"); do
    grep -q "W3DCAP FIN\|W3DCAP ERROR" "$LOG" 2>/dev/null && break
    kill -0 $PID 2>/dev/null || break
    sleep 1
done
kill $PID 2>/dev/null || true
wait $PID 2>/dev/null || true

python3 - "$LOG" "$SALIDA" <<'EOF'
import base64, sys, zlib, struct
log, salida = sys.argv[1], sys.argv[2]
lineas = open(log, encoding="utf-8", errors="replace").read().splitlines()
try:
    i = next(k for k, l in enumerate(lineas) if l.startswith("W3DCAP INICIO"))
except StopIteration:
    print("no llego ninguna captura (mirar %s)" % log); sys.exit(1)
_, _, w, h, n = lineas[i].split()
w, h, n = int(w), int(h), int(n)
datos = []
import re
for l in lineas[i + 1:]:
    if l.startswith("W3DCAP FIN"): break
    l = l.strip()
    if re.fullmatch(r"[A-Za-z0-9+/=]+", l): datos.append(l)   # (el log de Flycast se puede intercalar)
rgb = base64.b64decode("".join(datos))[:n]
# PNG sin dependencias (RGB 8 bits)
filas = b"".join(b"\x00" + rgb[y * w * 3:(y + 1) * w * 3] for y in range(h))
def trozo(t, d): return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xffffffff)
png = b"\x89PNG\r\n\x1a\n" + trozo(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)) + trozo(b"IDAT", zlib.compress(filas, 9)) + trozo(b"IEND", b"")
open(salida, "wb").write(png)
print("captura %dx%d -> %s" % (w, h, salida))
EOF
