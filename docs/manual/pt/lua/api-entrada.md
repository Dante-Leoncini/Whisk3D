# Teclado, controle, toque e mouse

| Função | O que faz |
|---|---|
| `tecla(nombre) → bool` | A tecla está pressionada (enquanto você a mantém). |
| `teclaApretada(nombre) → bool` | Foi pressionada exatamente neste quadro (uma única vez por pressionamento). |
| `boton(nombre)`, `botonApretado(nombre)` | O mesmo com um botão do controle. |
| `stick(["izq"\|"der"]) → x, y` | Alavanca do controle, de -1 a 1 (para cima é -1). |
| `gatillo(["izq"\|"der"]) → 0..1` | Gatilho analógico. |
| `controles() → n`, `control([n]) → nombre, tipo` | Quantos controles há e de que tipo (`"xbox"`, `"playstation"`, `"nintendo"`, `"generico"`). |
| `toque() → x, y, tocando` | O dedo (ou o clique do mouse) na tela. |
| `dedo([n]) → x, y, activo` | Multitoque: o dedo número n (1 a 4). |
| `apretado(obj) → bool` | Esse elemento 2D foi tocado ou clicado neste quadro (botões). |
| `raton() → x, y, dentro` | Onde está o mouse. |
| `capturarRaton(bool)`, `ratonRel() → dx, dy`, `ratonCapturado()` | Mouse capturado para olhar com o mouse (jogos em primeira pessoa, só no PC). |
