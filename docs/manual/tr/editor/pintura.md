# Boyama modları

> [!NOTE]
> Üç boyama modu da **yalnızca 3D mesh'ler içindir**: kameralar, ışıklar, iskeletler, eğriler ya da 2D öğelerle görünmezler. Boyama sırasında tık seçimi değiştirmez; başka bir nesneyi boyamak için onu Outliner'dan seç.

## Üçünde ortak olanlar

| İşlev | Açıklama | Nasıl kullanılır |
|---|---|---|
| Boyama | Yalnızca görünen, öne bakan yüzleri boyar (X-Ray ile arkadakileri de). Her fırça darbesi bir geri alma adımıdır. | Tıkla ve sürükle |
| Radius | Fırçanın piksel cinsinden boyutu. Değiştirdiğinde görünümün ortasında gerçek boyutta bir daire belirir. | Alt çubuğun üstündeki sürüklenebilir çubuk |
| Value | Fırçanın yoğunluğu. | Sürüklenebilir çubuk |
| Falloff | Fırça kenarının nasıl yumuşatılacağı; kendi eğrini de çizebilirsin. | Falloff düğmesi |
| Görünüm (dokunmatik) | Açık: parmak gezinir. Kapalı: parmak boyar. | Monitör şeklindeki düğme |

## Weight Paint

Bir kemiğin her köşeyi ne kadar etkilediğini boyar (mavi = hiç, kırmızı = tamamen). Mesh'in iskeletle düzgün deforme olmasını sağlayan budur.

| İşlev | Açıklama |
|---|---|
| Fırça modu | Ekleme (+), çıkarma (−) ya da eşitleme (=, tam değeri koyar). |
| Group (köşe grubu) | Hangi grubun (kemiğin) boyanacağı; grup ekleyebilirsin. Hiç grup yoksa ilk fırça darbesi bir tane oluşturur. |
| İşaretler | Her köşe için küçük bir kare gösterir; fırça yalnızca onlara etki eder. |
| Yalnızca seçili olan | Seçili olmayanı korur (karartılmış görünür). |

## Vertex Paint

Bir **3D mesh**'in köşelerine renk boyar (resimler ya da 2D öğeler için işe yaramaz: onun için Texture Paint var). Çok hafiftir ve N95'te renk vermenin önerilen yoludur.

| İşlev | Açıklama |
|---|---|
| Color | Renk seçiciyi açar (RGB, HSV, onaltılık ya da paletten bir dizin). |
| Per-Vertex / Per-Corner | Per-Vertex'te renk yüzler arasında paylaşılır; Per-Corner'da her yüzün kendi rengi olabilir (sert kenarlar). |
| Color Layer | Renk katmanlarını seçme ya da oluşturma. |
| İşaretler / Yalnızca seçili olan | Weight Paint'teki gibi. |

## Texture Paint

Doğrudan 3D nesnenin üzerine boyar ve fırça darbesi nesnenin dokusuna işlenir.

| İşlev | Açıklama |
|---|---|
| Otomatik doku | Mesh'in dokusu yoksa ilk fırça darbesinde kendiliğinden oluşturulur: kendine ait bir materyal, otomatik UV'ler ve materyalin renginde 1024×1024'lük (N95'te 256×256) bir görüntü. |
| Color, Falloff, Radius, Value | Diğer modlardaki gibi. |
| Save Texture | Boya, kaydedilene kadar bellekte durur. Kaydedilmemiş değişiklik varsa disket yeşil olur. Seçenekler: Save, Save As…, Save inside the .w3d ve Save outside the .w3d… |
