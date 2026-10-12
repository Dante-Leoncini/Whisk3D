#!/usr/bin/env python3
# ---------------------------------------------------------------------------------------------------------------
#  genmanual_atajos.py -- regenera las tablas de "Atajos de fabrica" del manual (docs/manual/manual_es.html)
#  desde la tabla del codigo (main/app/W3dAtajos.cpp) y las traducciones (main/config/W3dLangTabla.h).
#
#  El manual tiene dos marcas, <!--ATAJOS-INICIO--> y <!--ATAJOS-FIN-->: lo de adentro se reemplaza entero.
#  Asi el manual dice siempre lo mismo que el editor: si cambia un atajo de fabrica, se corre esto y listo.
#
#  Uso:
#      python3 tools/genmanual_atajos.py           # reescribe el manual (si hace falta)
#      python3 tools/genmanual_atajos.py --check   # no escribe: 0 si esta al dia, 1 si no
# ---------------------------------------------------------------------------------------------------------------
import html
import os
import re
import sys

RAIZ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ATAJOS = os.path.join(RAIZ, "main", "app", "W3dAtajos.cpp")
TABLA = os.path.join(RAIZ, "main", "config", "W3dLangTabla.h")
MANUAL = os.path.join(RAIZ, "docs", "manual", "manual_es.html")
INI, FIN = "<!--ATAJOS-INICIO-->", "<!--ATAJOS-FIN-->"

CONTEXTOS = {
    "W3dATC_GLOBAL": "General (cualquier panel)",
    "W3dATC_3D": "Vista 3D",
    "W3dATC_XFORM": "Durante una transformación (mover / rotar / escalar)",
    "W3dATC_UV": "Editor UV",
    "W3dATC_TIMELINE": "Línea de tiempo",
    "W3dATC_OUTLINER": "Outliner",
    "W3dATC_2D": "Editor 2D",
    "W3dATC_PROPS": "Propiedades (pasos de una rutina)",
    "W3dATC_IDE": "Editor de scripts",
}


def leer(p):
    with open(p, encoding="utf-8") as f:
        return f.read()


def generar():
    src = leer(ATAJOS)
    lit = r'(NULL|"[^"]*")'
    filas = re.findall(r'\{ "([^"]+)",\s+(W3dATC_\w+),\s+"([^"]+)",\s+"([^"]*)"(?:,\s*' + lit + r',\s*' + lit + r')?\s*\}', src)
    es = dict(re.findall(r'\{ "((?:[^"\\]|\\.)*)", "((?:[^"\\]|\\.)*)",', leer(TABLA)))
    tr = lambda s: es.get(s, s)
    out, ctx = [], None
    for ident, c, nombre, defecto, tel, _bt in filas:
        if c != ctx:
            if ctx:
                out.append("</table></div>")
            out.append("<h4>%s</h4>" % CONTEXTOS.get(c, c))
            out.append('<div class="tabla"><table>')
            out.append("<tr><th>Función</th><th>Atajo de fábrica</th><th>Nokia N95 (teclado del teléfono)</th><th>Nombre en atajos.ini</th></tr>")
            ctx = c
        teclas = ", ".join("<kbd>%s</kbd>" % html.escape(k.strip()) for k in defecto.split(","))
        tel = tel.strip('"') if tel and tel != "NULL" else ""
        telhtml = "<kbd>%s</kbd>" % html.escape(tr(tel)) if tel else "—"
        out.append("<tr><td>%s</td><td>%s</td><td>%s</td><td><code>%s</code></td></tr>" % (html.escape(tr(nombre)), teclas, telhtml, ident))
    out.append("</table></div>")
    return "\n".join(out)


def main():
    man = leer(MANUAL)
    if INI not in man or FIN not in man:
        print("el manual no tiene las marcas %s / %s" % (INI, FIN))
        return 1
    a, b = man.index(INI) + len(INI), man.index(FIN)
    nuevo = man[:a] + "\n" + generar() + "\n" + man[b:]
    if nuevo == man:
        print("manual: tablas de atajos al dia")
        return 0
    if "--check" in sys.argv:
        print("manual: las tablas de atajos estan VIEJAS (correr tools/genmanual_atajos.py)")
        return 1
    with open(MANUAL, "w", encoding="utf-8") as f:
        f.write(nuevo)
    print("manual: tablas de atajos regeneradas")
    return 0


if __name__ == "__main__":
    sys.exit(main())
