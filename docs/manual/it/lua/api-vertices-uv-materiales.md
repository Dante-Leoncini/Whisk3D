# Vertici, UV e materiali

| Funzione | Cosa fa |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | Leggere e spostare i vertici uno per uno. |
| `setVertices(m, {i, x, y, z, ...})` | Spostare molti vertici in una volta (molto più veloce). |
| `grupoVertices(m, "grupo") → {índices}` | I vertici di un gruppo (chiamala una sola volta, in `inicio`). |
| `setVerticeColor`, `setVerticesColor` | Colorare i vertici da codice. |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | Spostare le UV (acqua, nastri trasportatori…). |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | Mescolare due texture in un materiale. |
