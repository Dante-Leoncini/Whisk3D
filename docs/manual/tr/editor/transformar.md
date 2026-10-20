# Taşıma, döndürme ve ölçekleme

Object Mode'da, Edit Mode'da, Pose Mode'da ve kemik düzenlemede aynı şekilde çalışır.

| İşlev | Açıklama | Kısayol |
|---|---|---|
| Move (taşıma) | Seçilen, işaretçiyi takip eder. | <kbd>G</kbd> |
| Rotate | Pivot etrafında döndürür. <kbd>R</kbd>'ye bir kez daha basmak serbest döndürme (trackball) ile yörüngesel döndürme arasında geçiş yapar. | <kbd>R</kbd> |
| Scale | Pivottan itibaren büyütür ya da küçültür. | <kbd>S</kbd> |
| Bir eksene kısıtlama | Dönüştürme sırasında. Tekrar basmak Global → Local → View → serbest arasında sırayla geçer. | <kbd>X</kbd> / <kbd>Y</kbd> / <kbd>Z</kbd> |
| Bir düzleme kısıtlama | O ekseni hariç tutar (diğer ikisinde taşır). | <kbd>Shift+X</kbd> / <kbd>Shift+Y</kbd> / <kbd>Shift+Z</kbd> |
| Tam değer | Bir sayı ya da işlem yaz (`2*3`, `(1+0.5)/2`). <kbd>-</kbd> işareti tersine çevirir, <kbd>Backspace</kbd> siler. | Sayılar |
| Confirm | İşlemi onaylar. | Sol tık, <kbd>Enter</kbd>, yeşil onay işareti |
| Cancel | Her şey eski hâline döner. | <kbd>Esc</kbd>, sağ tık, kırmızı çarpı |
| İnce adımlar | Azar azar taşır, döndürür ya da ölçekler. | Ok tuşları |

İşlem sürerken üst çubuk ne yapıldığını gösterir, örneğin "Move X: 1.5 along global X". Dokunmatik ekranda bu çubuğa dokunmak sayısal bir klavye açar.

## Gizmo

Gizmo, Object Mode'da ve Edit Mode'da pivotun üzerinde görünür (Overlays → Gizmo'dan açılıp kapatılır).

| İşlev | Açıklama |
|---|---|
| Taşıma gizmosu | Oklar = bir eksen; kareler = bir düzlem; ortadaki daire = serbest. |
| Döndürme gizmosu | Her eksen için renkli bir yarım daire, görünüme dönük döndürmek için beyaz bir halka ve serbest döndürmek için iç kısım. |
| Ölçekleme gizmosu | Her eksen için kare uçlar; ortadaki daire eşit oranda ölçekler. |
| Gizmo değiştirme | Gizmonun üzerine sürüklemeden yapılan hızlı bir tık (ya da dokunuş), Move'dan Rotate'e, oradan Scale'e ve yeniden Move'a geçirir. |

## Son işlemi ayarlama

Taşıma, döndürme ya da ölçeklemeden sonra (Object Mode'da veya Edit Mode'da) sol altta yapılanı gösteren bir panel belirir: X, Y, Z değerleri (ya da açı), yönelim ve seçenekleriyle birlikte orantılı düzenleme. Bir değeri değiştirmek işlemi yeni değerle yeniden yapar. **Cancel** işlemi geri alır, **Accept** ise olduğu gibi bırakır. Panelin dışına bir tık da onaylar. Panel açıkken 3D Viewport'un alt çubuğu gizlenir.

Panelin kenarlığı yeşildir çünkü odaktaki pencere odur. Ekran yüksekliğinin yarısına sığmazsa o yarıya küçülür ve parmağı sürükleyerek (seçeneklere dokunmadan), tekerlekle ya da ok tuşlarıyla kaydırılır. Klavyeyle ya da telefonla: ok tuşları satırlarda dolaşır, <kbd>OK</kbd> / <kbd>Enter</kbd> paneli kapatmadan değeri düzenler, **Accept**, <kbd>Esc</kbd> veya <kbd>Delete</kbd> (N95'te <kbd>C</kbd>) değişikliği koruyarak paneli kapatır ve yalnızca **Cancel** işlemi geri alır.

## Alt çubuk

Undo ve Redo'yu, son kullanılan işlemleri ve orantılı düzenleme düğmesini içerir. Dönüştürme sırasında onay işaretini (kabul), çarpıyı (iptal), yönelimi ve X / Y / Z eksenlerini gösterir (iki eksen açık = bir düzlem). Dokunmatik ekranda, extrude işleminden sonra **Repeat** belirir: işlemi onaylar ve yeniden extrude eder.
