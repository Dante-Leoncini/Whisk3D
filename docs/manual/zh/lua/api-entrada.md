# 键盘、手柄、触屏和鼠标

| 函数 | 作用 |
|---|---|
| `tecla(nombre) → bool` | 该键处于按下状态（只要你一直按着）。 |
| `teclaApretada(nombre) → bool` | 该键恰好在这一帧被按下（每次按下只触发一次）。 |
| `boton(nombre)`, `botonApretado(nombre)` | 同上，用于手柄按钮。 |
| `stick(["izq"\|"der"]) → x, y` | 手柄摇杆，从 -1 到 1（向上为 -1）。 |
| `gatillo(["izq"\|"der"]) → 0..1` | 模拟扳机。 |
| `controles() → n`, `control([n]) → nombre, tipo` | 有几个手柄，以及它们的类型（`"xbox"`、`"playstation"`、`"nintendo"`、`"generico"`）。 |
| `toque() → x, y, tocando` | 屏幕上的手指（或鼠标单击）。 |
| `dedo([n]) → x, y, activo` | 多点触控：第 n 根手指（1 到 4）。 |
| `apretado(obj) → bool` | 该 2D 元素在这一帧被点击或触摸（用于按钮）。 |
| `raton() → x, y, dentro` | 鼠标所在的位置。 |
| `capturarRaton(bool)`, `ratonRel() → dx, dy`, `ratonCapturado()` | 捕获鼠标，用鼠标控制视角（第一人称游戏，仅限 PC）。 |
