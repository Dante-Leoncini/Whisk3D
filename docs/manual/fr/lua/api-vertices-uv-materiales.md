# Sommets, UV et matériaux

| Fonction | Ce qu'elle fait |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | Lire et déplacer les sommets un par un. |
| `setVertices(m, {i, x, y, z, ...})` | Déplacer de nombreux sommets d'un coup (beaucoup plus rapide). |
| `grupoVertices(m, "grupo") → {índices}` | Les sommets d'un groupe (à appeler une seule fois, dans `inicio`). |
| `setVerticeColor`, `setVerticesColor` | Peindre des sommets par code. |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | Déplacer les UV (eau, tapis roulants…). |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | Mélanger deux textures dans un matériau. |
