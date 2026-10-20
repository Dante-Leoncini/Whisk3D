# Edit Mode (mesh'ler)

Bir mesh üzerindeyken <kbd>Tab</kbd> ile girilir. Üst çubuktaki düğmeye göre **köşeler**, **kenarlar** ya da **yüzler** üzerinde çalışılır.

## Seçim

| İşlev | Açıklama | Kısayol |
|---|---|---|
| Select | Bir köşe, kenar ya da yüz seçer. | Tık; <kbd>Shift</kbd>+tık seçimi açıp kapatır |
| Select Linked | İşaretçinin altındaki bağlantılı adanın tamamı. | <kbd>L</kbd> |
| Loop Select | Bir kenar ya da yüz halkası. | <kbd>Shift+Alt</kbd>+tık |
| Pick Shortest Path | Etkin öğe ile tıklanan öğe arasındaki yolu seçer. | <kbd>Ctrl</kbd>+tık |
| Shortest Path (Fill Region) | İkisi arasındaki bölgenin tamamını seçer. | <kbd>Ctrl+Shift</kbd>+tık |
| All / None / Invert / Box Select | Object Mode'daki gibi, ama mesh'in öğeleri üzerinde. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## Modelleme

| İşlev | Açıklama | Kısayol |
|---|---|---|
| Move / Rotate / Scale | Seçileni dönüştürür. Bir taşıma sürerken <kbd>G</kbd>'ye bir kez daha basmak kaydırmaya geçer. | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Shrink/Fatten | Her köşeyi normali boyunca taşır (şişirir ya da söndürür). | <kbd>Alt+S</kbd> |
| Extrude | Seçilenden yeni geometri çıkarır (yüzler normalleri yönünde çıkar). | <kbd>E</kbd> |
| Loop Cut and Slide | Bir kenar halkası keser. Tekerlek kesim sayısını değiştirir; tık uygular, ardından kaydırılır. | <kbd>Ctrl+R</kbd> |
| New Edge/Face from Vertices | Seçili köşeleri bir kenar ya da yüzle birleştirir. | <kbd>F</kbd> |
| Connect Vertex Path | İki köşe arasında düz bir çizgi boyunca keser. | <kbd>J</kbd> |
| Slide Vertices | Köşeleri kenarları boyunca kaydırır. | <kbd>Shift+V</kbd> |
| Rip | Mesh'i seçim boyunca ayırır. | <kbd>V</kbd> |
| Duplicate | Seçileni kopyalar ve tutulmuş hâlde bırakır. | <kbd>Shift+D</kbd> |
| Separate | Seçili yüzleri yeni bir nesneye aktarır. | <kbd>P</kbd> |
| Merge | Köşeleri kaynaştırır: At Center, At Cursor, Collapse ya da By Distance. | <kbd>M</kbd> |
| Auto Merge | Taşıma bittiğinde, eşik değerinden daha yakın kalan köşeleri kaynaştırır. | Mesh menüsü |
| Delete | Vertices, Edges, Faces ya da Edge Loops. | <kbd>X</kbd> ya da <kbd>Delete</kbd> |
| Recalculate Normals / Flip | Yüzlerin baktığı yönü düzeltir ya da onları ters çevirir. | <kbd>Shift+N</kbd> |
| Triangulate Faces | 3'ten fazla kenarı olan yüzleri üçgenlere böler. | <kbd>Ctrl+T</kbd> |
| Shade Smooth / Shade Flat | Yüzeyin nasıl aydınlatılacağı. | Face menüsü |
| Mark Sharp / Clear Sharp | Mesh yumuşak olsa bile sert görünen kenarlar. | Edge menüsü |
| Mark Seam / Clear Seam | UV açılırken mesh'in nereden kesileceği. | Edge ya da UV menüsü |
| Context menu | Geçerli alt modun (köşe, kenar ya da yüz) işlemlerini işaretçinin olduğu yerde açar. | <kbd>W</kbd> ya da sağ tık |
| Insert Keyframe | Mesh'in şeklini geçerli karede kaydeder (köşe animasyonu). | <kbd>I</kbd> |

## UV menüsü

| İşlev | Açıklama | Kısayol |
|---|---|---|
| Unwrap | Angle Based, Conformal ya da Minimum Stretch: mesh'i dikişlerinden açar. | <kbd>U</kbd> |
| Smart UV Project | Yüzler arasındaki açılara göre kendiliğinden keser ve açar. | <kbd>U</kbd> |
| Lightmap Pack / Follow Active Quads | Üst üste binmeden düzenlenmiş adalar / etkin yüzü takip ederek düzenlenmiş UV'ler. | <kbd>U</kbd> |
| Cube Projection, Cylinder Projection, Sphere Projection, Project from View | Basit projeksiyonlar. | <kbd>U</kbd> |
| Reset | Her yüz görüntünün tamamını kaplar. | <kbd>U</kbd> |

## Eğri düzenleme (path'ler)

Bir eğri üzerinde <kbd>Tab</kbd> ile, düğümleri noktalardan oluşan bir mesh'miş gibi düzenlenir: <kbd>G</kbd> taşır, <kbd>E</kbd> sonraki düğümü ekler, <kbd>X</kbd> siler.
