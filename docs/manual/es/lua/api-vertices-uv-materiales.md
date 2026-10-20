# Vértices, UV y materiales

| Función | Qué hace |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | Leer y mover vértices uno por uno. |
| `setVertices(m, {i, x, y, z, ...})` | Mover muchos vértices de una vez (mucho más rápido). |
| `grupoVertices(m, "grupo") → {índices}` | Los vértices de un grupo (llamarla una sola vez, en `inicio`). |
| `setVerticeColor`, `setVerticesColor` | Pintar vértices por código. |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | Mover las UV (agua, cintas transportadoras…). |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | Mezclar dos texturas en un material. |
