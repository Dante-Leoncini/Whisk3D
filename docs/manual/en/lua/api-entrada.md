# Keyboard, gamepad, touch and mouse

| Function | What it does |
|---|---|
| `tecla(nombre) → bool` | The key is pressed (for as long as you hold it). |
| `teclaApretada(nombre) → bool` | It was pressed in this very frame (only once per press). |
| `boton(nombre)`, `botonApretado(nombre)` | The same, with a gamepad button. |
| `stick(["izq"\|"der"]) → x, y` | Gamepad stick, from -1 to 1 (up is -1). |
| `gatillo(["izq"\|"der"]) → 0..1` | Analog trigger. |
| `controles() → n`, `control([n]) → nombre, tipo` | How many gamepads there are and of what type (`"xbox"`, `"playstation"`, `"nintendo"`, `"generico"`). |
| `toque() → x, y, tocando` | The finger (or the mouse click) on the screen. |
| `dedo([n]) → x, y, activo` | Multi-touch: finger number n (1 to 4). |
| `apretado(obj) → bool` | That 2D element was touched or clicked in this frame (buttons). |
| `raton() → x, y, dentro` | Where the mouse is. |
| `capturarRaton(bool)`, `ratonRel() → dx, dy`, `ratonCapturado()` | Captured mouse for mouse look (first-person games, PC only). |
