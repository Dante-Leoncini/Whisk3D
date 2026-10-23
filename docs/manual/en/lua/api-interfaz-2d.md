# 2D interface and screen

| Function | What it does |
|---|---|
| `pantalla() → ancho, alto` | Size of the canvas. |
| `margenPantalla() → mx, my` | How much screen is left on each side around a fixed-size canvas, in canvas units, up to the real edges (the camera framing bands are screen too). In portrait with a 4:3 canvas: moving a meter `my` up sticks it to the top edge. |
| `marcoPantalla() → x, y, ancho, alto` | The frame of the 3D image (the camera framing, without the bands) in canvas units, from its center. |
| `capturarPantalla(nombre [, conHud]) → ruta` | Copies this frame's 3D image (when the scene is done; with `conHud`, after the HUD) to a texture. The path (`"pantalla:<nombre>"`) works with `setTextura`, a material or the "Bind texture" step of a routine. |
| `capturaUV(nombre) → u0, v0, u1, v1` | The part of the captured texture with the upright image, for `setUVRect` (or `nil` if the copy hasn't happened yet: it happens when the frame is drawn). |
| `areaSegura() → x, y, w, h` | The part of the screen without the notch (don't use it in `inicio`). |
| `escala() → f` | With no arguments: factor to adapt sizes to the screen (shorter side / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Position of a 2D element (a `nil` leaves that axis unchanged). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Size of a 2D element. |
| `cajaUI(obj) → x, y, w, h` | The rectangle it actually takes up (x, y = center). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Changes the text of a text or button element, and the font size. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Changes the image, crops a part of it (with u1 < u0 or v1 < v0, mirrored), or animates a sprite sheet. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Transparency and fades. |
| `setRot2D(obj, grados)` | Rotates a 2D element. |
| `chocan(a, b) → bool` | Whether two 2D elements overlap on the screen. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Keep an element inside another one, or ask whether a point is inside. |
| `salir()` | Closes the game (in the editor it does nothing). |
