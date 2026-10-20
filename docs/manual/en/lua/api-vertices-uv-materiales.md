# Vertices, UVs and materials

| Function | What it does |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | Read and move vertices one by one. |
| `setVertices(m, {i, x, y, z, ...})` | Move many vertices at once (much faster). |
| `grupoVertices(m, "grupo") → {índices}` | The vertices of a group (call it only once, in `inicio`). |
| `setVerticeColor`, `setVerticesColor` | Paint vertices from code. |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | Move the UVs (water, conveyor belts…). |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | Blend two textures in a material. |
