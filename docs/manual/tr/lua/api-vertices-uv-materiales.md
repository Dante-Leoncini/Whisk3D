# Köşeler, UV ve materyaller

| Fonksiyon | Ne yapar |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | Köşeleri tek tek okuma ve taşıma. |
| `setVertices(m, {i, x, y, z, ...})` | Birçok köşeyi tek seferde taşıma (çok daha hızlı). |
| `grupoVertices(m, "grupo") → {índices}` | Bir grubun köşeleri (yalnızca bir kez, `inicio` içinde çağır). |
| `setVerticeColor`, `setVerticesColor` | Köşeleri kodla boyama. |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | UV'leri kaydırma (su, taşıma bantları…). |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | Bir materyalde iki dokuyu karıştırma. |
