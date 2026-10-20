# Interface 2D e tela

| Função | O que faz |
|---|---|
| `pantalla() → ancho, alto` | Tamanho do canvas. |
| `areaSegura() → x, y, w, h` | A parte da tela sem notch (não usar em `inicio`). |
| `escala() → f` | Sem argumentos: fator para adaptar tamanhos à tela (lado menor / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Posição de um elemento 2D (um `nil` deixa esse eixo como está). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Tamanho de um elemento 2D. |
| `cajaUI(obj) → x, y, w, h` | O retângulo que ele ocupa de verdade (x, y = centro). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Muda o texto de um texto ou botão, e o tamanho da letra. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Muda a imagem, recorta uma parte ou anima uma folha de quadros. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Transparência e fades. |
| `setRot2D(obj, grados)` | Gira um elemento 2D. |
| `chocan(a, b) → bool` | Se dois elementos 2D se sobrepõem na tela. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Manter um elemento dentro de outro, ou perguntar se um ponto está dentro. |
| `salir()` | Fecha o jogo (no editor não faz nada). |
