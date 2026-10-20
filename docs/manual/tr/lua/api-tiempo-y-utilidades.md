# Zaman, rastgelelik ve yardımcı işlevler

| Fonksiyon | Ne yapar |
|---|---|
| `azar() → 0..1`, `azar(min, max) → entero` | Rastgele sayılar. |
| `relojMs() → ms` | Bir şeyin ne kadar sürdüğünü ölçmek için milisaniye. |
| `perfilLua(cuadros [, etiqueta])` | Script'in hangi kısımlarının yavaş olduğunu ölçer (`perfilLua(0)` onu kapatır). |
| `lineaCrear(nombre, puntos)`, `lineaPunto(id, s)` | Motorun hesapladığı kapalı, yumuşak bir eğri (güzergâhlar). |

"Başlangıçtan bu yana geçen süre" diye bir fonksiyon yoktur: `dt`'yi bir değişkende topla.
