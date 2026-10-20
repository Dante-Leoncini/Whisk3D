# Basit fizik (hız ve sekmeler)

| Fonksiyon | Ne yapar |
|---|---|
| `velocidad(obj, vx [, vy, vz])` / `velocidad(obj) → vx, vy, vz` | Ona bir hız verirsin, motor da onu kendiliğinden hareket ettirir. |
| `acelerar(obj, factor [, tope])` | Hızını çarparak onu hızlandırır. |
| `caja(obj [, w, h, d])` | Çarpışma kutusunun boyutu. |
| `rebotar(obj, otro)`, `rebotarEn(obj, area [, lados])`, `rebotarDentro(obj, area)` | Başka bir nesneden ya da bir alanın kenarlarından sekme (sektiyse `true` döndürürler). |
