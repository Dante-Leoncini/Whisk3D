# Interfaz 2D y pantalla

| Función | Qué hace |
|---|---|
| `pantalla() → ancho, alto` | Tamaño del lienzo. |
| `margenPantalla() → mx, my` | Cuánta pantalla sobra por lado alrededor de un lienzo de tamaño fijo, en unidades del lienzo, hasta los bordes reales (las bandas del encuadre también son pantalla). En vertical con un lienzo 4:3: correr un medidor `my` para arriba lo pega al borde de arriba. |
| `marcoPantalla() → x, y, ancho, alto` | El cuadro de la imagen 3D (el encuadre de la cámara, sin las bandas) en unidades del lienzo, desde su centro. |
| `capturarPantalla(nombre [, conHud]) → ruta` | Copia la imagen 3D de este cuadro (al terminar la escena; con `conHud`, después del HUD) a una textura. La ruta (`"pantalla:<nombre>"`) sirve para `setTextura`, un material o el paso "Bind texture" de una rutina. |
| `capturaUV(nombre) → u0, v0, u1, v1` | La parte de la textura capturada con la imagen derecha, para `setUVRect` (o `nil` si la copia todavía no se hizo: se hace al dibujar el cuadro). |
| `areaSegura() → x, y, w, h` | La parte de la pantalla sin notch (no usar en `inicio`). |
| `escala() → f` | Sin argumentos: factor para adaptar tamaños a la pantalla (lado menor / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Posición de un elemento 2D (un `nil` deja ese eje igual). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Tamaño de un elemento 2D. |
| `cajaUI(obj) → x, y, w, h` | El rectángulo que ocupa de verdad (x, y = centro). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Cambia el texto de un texto o botón, y el tamaño de letra. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Cambia la imagen, recorta una parte (con u1 < u0 o v1 < v0, espejada), o anima una hoja de cuadros. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Transparencia y fundidos. |
| `setRot2D(obj, grados)` | Rota un elemento 2D. |
| `chocan(a, b) → bool` | Si dos elementos 2D se superponen en pantalla. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Mantener un elemento adentro de otro, o preguntar si un punto está adentro. |
| `salir()` | Cierra el juego (en el editor no hace nada). |
