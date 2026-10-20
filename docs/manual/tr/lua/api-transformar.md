# 3D'de taşıma, döndürme ve ölçekleme

| Fonksiyon | Ne yapar |
|---|---|
| `posicion(obj) → x, y, z` | Nerede olduğu. |
| `setPosicion(obj, x, y, z)` | Onu tam bir konuma yerleştirir (fiziği yok sayar). |
| `mover(obj, dx, dy, dz)` | Onu bulunduğu yerden kaydırır (`dt` ile kullan). |
| `rotacion(obj) → x, y, z` | Derece cinsinden dönüşü. |
| `setRotacion(obj, x, y, z [, orden])` | Tam dönüş; `orden` örneğin `"YXZ"` olur (varsayılan `"XYZ"`). |
| `girar(obj, dx, dy, dz)` | Onu kendi eksenleri etrafında döndürür. |
| `girarHacia(obj, dx, dz [, factor])` | Onu zemindeki bir yöne doğru yumuşakça döndürür. |
| `mirarA(obj, x, y, z)` | Onu bir noktaya doğru yöneltir (bir kameranın önü). |
| `escala(obj) → sx, sy, sz` | Ölçeği. |
| `setEscala(obj, s [, sy, sz])` | Tam ölçek; tek bir sayıyla eşit oranda ölçekler. |
| `escalar(obj, f)` | Geçerli ölçeği çarpar. |
| `puntoMundo(obj, x, y, z) → x, y, z` | Nesnenin bir noktasını dünya koordinatlarına çevirir. |
| `visible(obj) → bool`, `setVisible(obj, bool)` | Onu gösterir ya da gizler. Gizli bir nesne artık `actualizar` çağrısı almaz. |
| `setTinte(obj, r, g, b [, a])` | Rengini değiştirir (0 ile 1 arası değerler). |
