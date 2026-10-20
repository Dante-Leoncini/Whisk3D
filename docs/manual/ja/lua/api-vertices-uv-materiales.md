# 頂点、UV、マテリアル

| 関数 | 説明 |
|---|---|
| `numVertices(m)`、`verticePos(m, i)`、`setVerticePos(m, i, x, y, z)` | 頂点を1つずつ読み取り、動かします。 |
| `setVertices(m, {i, x, y, z, ...})` | 多くの頂点を一度に動かします（ずっと高速です）。 |
| `grupoVertices(m, "grupo") → {índices}` | グループに属する頂点（`inicio`で一度だけ呼んでください）。 |
| `setVerticeColor`、`setVerticesColor` | コードで頂点に色を塗ります。 |
| `setVerticeUV`、`desplazarUV(m, du, dv)`、`copiarUV` | UVを動かします（水、ベルトコンベア…）。 |
| `setTexturaB`、`setMezclaTextura`、`mezclaTextura` | マテリアルで2つのテクスチャをブレンドします。 |
