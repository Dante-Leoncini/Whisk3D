# Interfaz 2D y pantalla

| Función | Qué hace |
|---|---|
| `pantalla() → ancho, alto` | Tamaño del lienzo. |
| `areaSegura() → x, y, w, h` | La parte de la pantalla sin notch (no usar en `inicio`). |
| `escala() → f` | Sin argumentos: factor para adaptar tamaños a la pantalla (lado menor / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Posición de un elemento 2D (un `nil` deja ese eje igual). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Tamaño de un elemento 2D. |
| `cajaUI(obj) → x, y, w, h` | El rectángulo que ocupa de verdad (x, y = centro). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Cambia el texto de un texto o botón, y el tamaño de letra. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Cambia la imagen, recorta una parte, o anima una hoja de cuadros. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Transparencia y fundidos. |
| `setRot2D(obj, grados)` | Rota un elemento 2D. |
| `chocan(a, b) → bool` | Si dos elementos 2D se superponen en pantalla. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Mantener un elemento adentro de otro, o preguntar si un punto está adentro. |
| `salir()` | Cierra el juego (en el editor no hace nada). |
