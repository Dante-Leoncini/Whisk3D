# 2D interface and screen

| Function | What it does |
|---|---|
| `pantalla() → ancho, alto` | Size of the canvas. |
| `areaSegura() → x, y, w, h` | The part of the screen without the notch (don't use it in `inicio`). |
| `escala() → f` | With no arguments: factor to adapt sizes to the screen (shorter side / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Position of a 2D element (a `nil` leaves that axis unchanged). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Size of a 2D element. |
| `cajaUI(obj) → x, y, w, h` | The rectangle it actually takes up (x, y = center). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Changes the text of a text or button element, and the font size. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Changes the image, crops a part of it, or animates a sprite sheet. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Transparency and fades. |
| `setRot2D(obj, grados)` | Rotates a 2D element. |
| `chocan(a, b) → bool` | Whether two 2D elements overlap on the screen. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Keep an element inside another one, or ask whether a point is inside. |
| `salir()` | Closes the game (in the editor it does nothing). |
