#!/usr/bin/env python3
# ---------------------------------------------------------------------------------------------------------------
#  genmanual_atajos.py -- regenera las tablas de "Atajos de fabrica" del manual (docs/manual/es/editor/atajos.md)
#  desde la tabla del codigo (main/app/W3dAtajos.cpp) y las traducciones (main/config/W3dLangTabla.h).
#
#  La pagina tiene dos marcas, <!--ATAJOS-INICIO--> y <!--ATAJOS-FIN-->: lo de adentro se reemplaza entero.
#  Asi el manual dice siempre lo mismo que el editor: si cambia un atajo de fabrica, se corre esto y listo.
#
#  Uso:
#      python3 tools/genmanual_atajos.py           # reescribe el manual (si hace falta)
#      python3 tools/genmanual_atajos.py --check   # no escribe: 0 si esta al dia, 1 si no
# ---------------------------------------------------------------------------------------------------------------
import os
import re
import sys

RAIZ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ATAJOS = os.path.join(RAIZ, "main", "app", "W3dAtajos.cpp")
TABLA = os.path.join(RAIZ, "main", "config", "W3dLangTabla.h")
MANUAL = os.path.join(RAIZ, "docs", "manual", "es", "editor", "atajos.md")
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


def md_texto(s, en_tabla=True):
    """Texto suelto en Markdown: se escapan los caracteres que Markdown interpretaria."""
    s = s.replace("\\", "\\\\")
    for ch in "*_`":
        s = s.replace(ch, "\\" + ch)
    s = re.sub(r"<(?=[A-Za-z/!?])", "&lt;", s)
    s = re.sub(r"&(?=#?\w+;)", "&amp;", s)
    return s.replace("|", "\\|") if en_tabla else s


def md_tecla(k):
    k = k.replace("&", "&amp;").replace("<", "&lt;").replace("*", "\\*").replace("_", "\\_").replace("|", "\\|")
    return "<kbd>%s</kbd>" % k


def generar():
    src = leer(ATAJOS)
    lit = r'(NULL|"[^"]*")'
    filas = re.findall(r'\{ "([^"]+)",\s+(W3dATC_\w+),\s+"([^"]+)",\s+"([^"]*)"(?:,\s*' + lit + r',\s*' + lit + r')?\s*\}', src)
    es = dict(re.findall(r'\{ "((?:[^"\\]|\\.)*)", "((?:[^"\\]|\\.)*)",', leer(TABLA)))
    tr = lambda s: es.get(s, s)
    bloques, ctx = [], None
    for ident, c, nombre, defecto, tel, _bt in filas:
        if c != ctx:
            bloques.append(["### %s\n" % md_texto(CONTEXTOS.get(c, c), False),
                            "| Función | Atajo de fábrica | Nokia N95 (teclado del teléfono) | Nombre en atajos.ini |",
                            "|---|---|---|---|"])
            ctx = c
        teclas = ", ".join(md_tecla(k.strip()) for k in defecto.split(","))
        tel = tel.strip('"') if tel and tel != "NULL" else ""
        telmd = md_tecla(tr(tel)) if tel else "—"
        bloques[-1].append("| %s | %s | %s | `%s` |" % (md_texto(tr(nombre)), teclas, telmd, ident.replace("|", "\\|")))
    return "\n\n".join("\n".join(b) for b in bloques)


def main():
    man = leer(MANUAL)
    if INI not in man or FIN not in man:
        print("el manual no tiene las marcas %s / %s" % (INI, FIN))
        return 1
    a, b = man.index(INI) + len(INI), man.index(FIN)
    nuevo = man[:a] + "\n\n" + generar() + "\n\n" + man[b:]   # lineas en blanco: si no, Markdown pega la tabla a la marca
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
