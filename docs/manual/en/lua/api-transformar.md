# Move, rotate and scale in 3D

| Function | What it does |
|---|---|
| `posicion(obj) → x, y, z` | Where it is. |
| `setPosicion(obj, x, y, z)` | Puts it in an exact place (ignores physics). |
| `mover(obj, dx, dy, dz)` | Moves it from where it is (use it with `dt`). |
| `rotacion(obj) → x, y, z` | Its rotation in degrees. |
| `setRotacion(obj, x, y, z [, orden])` | Exact rotation; `orden` is for example `"YXZ"` (the default is `"XYZ"`). |
| `girar(obj, dx, dy, dz)` | Rotates it around its own axes. |
| `girarHacia(obj, dx, dz [, factor])` | Turns it smoothly toward a direction on the floor. |
| `mirarA(obj, x, y, z)` | Points it at a point (the front of a camera). |
| `escala(obj) → sx, sy, sz` | Its scale. |
| `setEscala(obj, s [, sy, sz])` | Exact scale; with a single number it scales uniformly. |
| `escalar(obj, f)` | Multiplies the current scale. |
| `puntoMundo(obj, x, y, z) → x, y, z` | Converts a point of the object to world coordinates. |
| `visible(obj) → bool`, `setVisible(obj, bool)` | Shows or hides it. A hidden object stops receiving `actualizar`. |
| `setTinte(obj, r, g, b [, a])` | Changes its color (values from 0 to 1). |
