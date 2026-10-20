# 动画

| 函数 | 作用 |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | 整个场景的动画。 |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | 对象及其子级的动画片段。 |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | 骨架的动画（走、跳……）以及它们之间的平滑过渡。 |
| `animCapa(esq, n, clip [, peso, modo])` 及同系列函数 | 在多个层（1 到 16）中同时混合多个动画，例如跑步 + 射击。 |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | 某根骨骼所在的位置（用来把武器放到手上）。 |
| `animar(malla, n [, frame])` | 切换网格的顶点动画。 |
