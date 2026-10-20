# Vértices, UV e materiais

| Função | O que faz |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | Ler e mover vértices um por um. |
| `setVertices(m, {i, x, y, z, ...})` | Mover muitos vértices de uma vez (muito mais rápido). |
| `grupoVertices(m, "grupo") → {índices}` | Os vértices de um grupo (chame-a uma única vez, em `inicio`). |
| `setVerticeColor`, `setVerticesColor` | Pintar vértices por código. |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | Mover as UV (água, esteiras transportadoras…). |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | Misturar duas texturas em um material. |
