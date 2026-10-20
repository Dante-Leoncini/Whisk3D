# 2D arayüz ve ekran

| Fonksiyon | Ne yapar |
|---|---|
| `pantalla() → ancho, alto` | Tuvalin boyutu. |
| `areaSegura() → x, y, w, h` | Ekranın çentiksiz kısmı (`inicio` içinde kullanma). |
| `escala() → f` | Argümansız: boyutları ekrana uyarlamak için çarpan (kısa kenar / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Bir 2D öğenin konumu (`nil` o ekseni olduğu gibi bırakır). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Bir 2D öğenin boyutu. |
| `cajaUI(obj) → x, y, w, h` | Gerçekte kapladığı dikdörtgen (x, y = merkez). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Bir metnin ya da düğmenin yazısını ve yazı boyutunu değiştirir. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Görüntüyü değiştirir, bir kısmını kırpar ya da bir kare sayfasını canlandırır. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Saydamlık ve yumuşak geçişler. |
| `setRot2D(obj, grados)` | Bir 2D öğeyi döndürür. |
| `chocan(a, b) → bool` | İki 2D öğenin ekranda üst üste binip binmediği. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Bir öğeyi başka bir öğenin içinde tutma ya da bir noktanın içeride olup olmadığını sorma. |
| `salir()` | Oyunu kapatır (editörde hiçbir şey yapmaz). |
