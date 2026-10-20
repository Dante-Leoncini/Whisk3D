# UV Editor

Dokunun mesh'in üzerine nasıl oturduğunu gösterir. Düzenleme yapabilmek için mesh'in **3D Viewport'ta Edit Mode'da** olması gerekir; değilse editör yalnızca dokuyu gösterir. UV Editor'ün modu kendine aittir: 3D Viewport'un modunu değiştirmez. UV açma ve yansıtma araçları 3D Viewport'tadır (Edit Mode, <kbd>U</kbd> tuşu).

## Gezinme ve üst çubuk

| İşlev | Açıklama | Nasıl kullanılır |
|---|---|---|
| Yakınlaştırma / Kaydırma | İşaretçiye doğru yakınlaştırır / görünümü kaydırır. | Tekerlek / orta tuş ya da ok tuşları; dokunmatik: 1 parmak kaydırır, 2 parmak yakınlaştırır |
| Mod | Object Mode, Edit Mode, Weight Paint, Edit Bones ve Pose Mode (son ikisi, mesh'in 2D iskeleti varsa). | Mod düğmesi, <kbd>Tab</kbd> |
| Vertex / Edge / Face | Edit Mode'da neyin seçileceği. | Düğme |
| Pivot | 3D Cursor, Individual Origins ya da Median Point. | Düğme |
| Cursor | Cursor to Selection, Selection to Cursor, Cursor to Center. | Menü |
| View | Sync Selection (UV seçimi mesh'inkiyle aynıdır), Repeat Texture (döşeme), Show Chrome UV, Frame Selected, Frame All. | Menü; <kbd>Num.</kbd> |
| Texture | Hangi dokunun gösterileceği: New Texture…, Auto (active part) ya da projedeki herhangi bir doku. | Menü |
| New Texture | Bir görüntü oluşturur (ad, boyut, renk, saydamlık; düz, UV Grid ya da Color Grid), onu projeye kaydeder ve materyale atar. | Texture → New Texture… |
| Mipmap | İncelemek için belirli bir mipmap seviyesini gösterir. | Mip düğmesi |
| Edit | Görüntü üzerinde doku boyamaya girer ve çıkar. | Edit düğmesi |
| Save (disket, her zaman görünür) | Save, Save As…, Save outside the .w3d…, Save inside the .w3d, Export UV Layout… | Menü |
| Export UV Layout | Saydam arka planlı bir PNG kaydeder: yarı saydam yüzler (üst üste bindikleri yerde daha opak) ve opak çizgiler. Ad, klasör ve çözünürlük seçilir (varsayılan 512, N95'te 256 ya da gösterilen dokunun boyutu). | Save → Export UV Layout… |
| Animation | UV katmanının ya da 2D pozun keyframe'lerini ekleme, silme ya da temizleme. | Menü |

## Object Mode (UV)

Tık neyin düzenleneceğini seçer: bir 2D iskelet (bir kemiğe dokunulursa) ya da geometri. <kbd>Tab</kbd> seçileni düzenlemeye girer.

## Edit Mode (UV)

| İşlev | Açıklama | Kısayol |
|---|---|---|
| Select | UV köşeleri, kenarları ya da yüzleri. Senkronizasyon kapalıyken 3D Viewport filtre görevi görür: yalnızca 3D'de seçili yüzler görünür. | Tık; <kbd>Shift</kbd>+tık |
| All / None / Invert | Görünenler üzerinde. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | İşaretçinin altındaki UV adası (<kbd>Shift</kbd> ekler). | <kbd>L</kbd> |
| Box Select | Dikdörtgen; <kbd>Shift</kbd> ekler. | <kbd>B</kbd> |
| Move / Rotate / Scale | UV'leri dönüştürür. <kbd>X</kbd> / <kbd>Y</kbd> bir ekseni kilitler; değeri yazabilirsin (1.0 = bir döşeme). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| 2D imleci konumlandırma | İmleci tıklanan yere koyar. | Sağ tık |
| Insert Keyframe | UV katmanını etkin köşe animasyonuna kaydeder. | <kbd>I</kbd> |

## Weight Paint (UV)

2D kemiklerin ağırlıklarını UV haritası üzerinde boyar; 3D Viewport'takiyle aynı kontroller kullanılır (+/−/= modu, grup, işaretler, falloff, yalnızca seçili olan). Bir kemiğe <kbd>Ctrl</kbd>+tık, onu boyamak için seçer.

## Edit Bones ve Pose Mode (2D iskelet)

| İşlev | Açıklama | Kısayol |
|---|---|---|
| Armature 2D / Bone | Mesh'in 2D iskeletini (UV grubuyla birlikte) oluşturur ya da bir kemik ekler. | Add menüsü |
| Select | Bir uç ya da kemiğin tamamı; sürüklemek onu taşır. | Tık; <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | Edit Bones'ta dinlenme konumunu değiştirir; Pose'da poz verir (ağırlık verilmiş UV'ler kemiği takip eder). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | Yalnızca Edit Bones'ta. | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | Keep Offset ya da Connected / bağlantıyı kesme. | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | Pose'da: kanal menüsü ya da <kbd>Shift+I</kbd> ile hepsi. | <kbd>I</kbd> |

## Texture Paint (UV)

**Edit** düğmesiyle doğrudan görüntünün üzerine; renk, falloff, yarıçap ve kuvvetle boyanır. Disketten kaydedilir.
