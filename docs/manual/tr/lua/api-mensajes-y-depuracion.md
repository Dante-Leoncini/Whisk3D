# Mesajlar ve hata ayıklama

| Fonksiyon | Ne yapar |
|---|---|
| `print(...)` | Ekrana değil, motorun günlüğüne (log) yazar. |
| `info(msg)`, `aviso(msg)`, `error(msg)` | Günlüğe bilgi, uyarı ya da hata mesajları yazar. `error` script'i **durdurmaz**. |
| `depurar(msg)`, `esDebug()` | Yalnızca hata ayıklama sürümlerinde görünen mesajlar. |
| `logCantidad()`, `logLinea(i)` | Günlüğü oyunun içinden okuma (kendi konsolun). |
