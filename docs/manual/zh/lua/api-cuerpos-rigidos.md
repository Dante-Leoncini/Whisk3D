# 刚体、碰撞和碰撞盒

| 函数 | 作用 |
|---|---|
| `fisicaVel`, `fisicaVelAng`, `fisicaImpulso`, `fisicaFuerza` | 刚体的速度、旋转、冲量和力。 |
| `fisicaGravedad([g])`, `fisicaActiva(obj, bool)`, `fisicaDespierto(obj)` | 重力（默认 9.81），开启/关闭某个对象的物理。 |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | 发射一条射线，返回它碰到了什么。 |
| `contactos() → lista` | 这一帧中的所有碰撞。 |
| `colSuelo(malla, x, y, z)`, `colPared(...)`, `colRayo(...)` | 与网格三角形的碰撞（站在地面上、不穿墙）。 |
| `hitboxActivo`, `setHitboxActivo`, `setHitboxTam`, `hitboxDentro`, `hitboxTocando` | 管理碰撞盒，并查询其中有什么。 |
| `verHitboxes(bool)` | 绘制碰撞盒，便于调试。 |
