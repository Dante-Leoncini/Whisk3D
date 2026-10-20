# 简单物理（速度和反弹）

| 函数 | 作用 |
|---|---|
| `velocidad(obj, vx [, vy, vz])` / `velocidad(obj) → vx, vy, vz` | 给它一个速度，引擎会自动移动它。 |
| `acelerar(obj, factor [, tope])` | 通过乘以它的速度来加速。 |
| `caja(obj [, w, h, d])` | 它的碰撞盒的大小。 |
| `rebotar(obj, otro)`, `rebotarEn(obj, area [, lados])`, `rebotarDentro(obj, area)` | 碰到另一个对象或某个区域的边缘时反弹（发生反弹时返回 `true`）。 |
