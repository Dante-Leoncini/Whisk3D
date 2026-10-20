# Вершины, UV и материалы

| Функция | Что делает |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | Читать и перемещать вершины по одной. |
| `setVertices(m, {i, x, y, z, ...})` | Переместить много вершин за раз (намного быстрее). |
| `grupoVertices(m, "grupo") → {índices}` | Вершины группы (вызывать один раз, в `inicio`). |
| `setVerticeColor`, `setVerticesColor` | Раскрашивать вершины из кода. |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | Сдвигать UV (вода, конвейерные ленты…). |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | Смешивать две текстуры в материале. |
