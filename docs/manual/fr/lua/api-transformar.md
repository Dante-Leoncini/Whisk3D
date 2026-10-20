# Déplacer, faire pivoter et mettre à l'échelle en 3D

| Fonction | Ce qu'elle fait |
|---|---|
| `posicion(obj) → x, y, z` | Où il se trouve. |
| `setPosicion(obj, x, y, z)` | Le place à un endroit précis (ignore la physique). |
| `mover(obj, dx, dy, dz)` | Le décale depuis sa position actuelle (utilisez-la avec `dt`). |
| `rotacion(obj) → x, y, z` | Sa rotation en degrés. |
| `setRotacion(obj, x, y, z [, orden])` | Rotation exacte ; `orden` vaut par exemple `"YXZ"` (par défaut `"XYZ"`). |
| `girar(obj, dx, dy, dz)` | Le fait tourner sur ses propres axes. |
| `girarHacia(obj, dx, dz [, factor])` | Le fait tourner en douceur vers une direction au sol. |
| `mirarA(obj, x, y, z)` | L'oriente vers un point (l'avant d'une caméra). |
| `escala(obj) → sx, sy, sz` | Son échelle. |
| `setEscala(obj, s [, sy, sz])` | Échelle exacte ; avec un seul nombre, met à l'échelle uniformément. |
| `escalar(obj, f)` | Multiplie l'échelle actuelle. |
| `puntoMundo(obj, x, y, z) → x, y, z` | Convertit un point de l'objet en coordonnées du monde. |
| `visible(obj) → bool`, `setVisible(obj, bool)` | L'affiche ou le masque. Un objet masqué ne reçoit plus `actualizar`. |
| `setTinte(obj, r, g, b [, a])` | Change sa couleur (valeurs de 0 à 1). |
