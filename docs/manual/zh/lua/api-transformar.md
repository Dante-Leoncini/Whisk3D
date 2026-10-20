# 3D 中的移动、旋转和缩放

| 函数 | 作用 |
|---|---|
| `posicion(obj) → x, y, z` | 它所在的位置。 |
| `setPosicion(obj, x, y, z)` | 把它放到一个精确的位置（忽略物理）。 |
| `mover(obj, dx, dy, dz)` | 从当前位置移动它（配合 `dt` 使用）。 |
| `rotacion(obj) → x, y, z` | 它的旋转，以度为单位。 |
| `setRotacion(obj, x, y, z [, orden])` | 精确的旋转；`orden` 例如 `"YXZ"`（默认为 `"XYZ"`）。 |
| `girar(obj, dx, dy, dz)` | 让它绕自身的轴旋转。 |
| `girarHacia(obj, dx, dz [, factor])` | 让它平滑地转向地面上的某个方向。 |
| `mirarA(obj, x, y, z)` | 让它朝向某个点（相机的正面）。 |
| `escala(obj) → sx, sy, sz` | 它的缩放。 |
| `setEscala(obj, s [, sy, sz])` | 精确的缩放；只传一个数字时等比缩放。 |
| `escalar(obj, f)` | 把当前缩放乘以一个系数。 |
| `puntoMundo(obj, x, y, z) → x, y, z` | 把对象上的一个点转换为世界坐标。 |
| `visible(obj) → bool`, `setVisible(obj, bool)` | 显示或隐藏它。隐藏的对象不再收到 `actualizar`。 |
| `setTinte(obj, r, g, b [, a])` | 改变它的颜色（取值 0 到 1）。 |
