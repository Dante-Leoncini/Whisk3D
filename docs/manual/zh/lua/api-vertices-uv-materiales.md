# 顶点、UV 和材质

| 函数 | 作用 |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | 逐个读取和移动顶点。 |
| `setVertices(m, {i, x, y, z, ...})` | 一次移动大量顶点（快得多）。 |
| `grupoVertices(m, "grupo") → {índices}` | 某个组中的顶点（只调用一次，放在 `inicio` 中）。 |
| `setVerticeColor`, `setVerticesColor` | 用代码为顶点上色。 |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | 移动 UV（水面、传送带……）。 |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | 在一个材质中混合两张纹理。 |
