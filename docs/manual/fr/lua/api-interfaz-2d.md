# Interface 2D et écran

| Fonction | Ce qu'elle fait |
|---|---|
| `pantalla() → ancho, alto` | Taille du canevas. |
| `areaSegura() → x, y, w, h` | La partie de l'écran sans encoche (à ne pas utiliser dans `inicio`). |
| `escala() → f` | Sans arguments : facteur pour adapter les tailles à l'écran (petit côté / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Position d'un élément 2D (un `nil` laisse cet axe inchangé). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Taille d'un élément 2D. |
| `cajaUI(obj) → x, y, w, h` | Le rectangle qu'il occupe réellement (x, y = centre). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Change le texte d'un texte ou d'un bouton, et la taille de police. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Change l'image, en découpe une partie ou anime une planche d'images. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Transparence et fondus. |
| `setRot2D(obj, grados)` | Fait pivoter un élément 2D. |
| `chocan(a, b) → bool` | Si deux éléments 2D se chevauchent à l'écran. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Garder un élément à l'intérieur d'un autre, ou demander si un point est à l'intérieur. |
| `salir()` | Ferme le jeu (dans l'éditeur, ne fait rien). |
