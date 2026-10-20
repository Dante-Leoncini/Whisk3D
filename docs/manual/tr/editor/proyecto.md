# Proje (.w3d) ve dosyalar

| İşlev | Açıklama | Nerede |
|---|---|---|
| Open project | Bir .w3d açar (sistemden çift tıklayarak da olur). | Properties → File/Render → File |
| Save / Save As | Karttaki klasöre ve karttaki adla kaydeder; Save As başka bir ad ister. Ad eksikse alan kırmızı olur. | File kartı, <kbd>Ctrl+S</kbd> |
| Save version | Kaydeder ve ayrıca numaralı bir kopya bırakır (`proyecto_v03.w3d`). | File kartı |
| Extract assets | İçerideki her şeyi bir klasöre kopyalar (kopyalar projeyi değiştirmez). | File kartı |
| Meshes as text | Mesh'leri ikili biçim yerine okunabilir metin olarak kaydeder. | File kartı |
| Imports | OBJ, FBX, glTF, GLB ve .w3dui arayüzleri. İçe aktarılanlar projenin içine kopyalanır (yinelenmeden). | 3D Viewport → Add → Imports |
| Export | Seçili nesnenin OBJ, glTF ya da GLB'si (modifier'lar ve dönüşümlerle ya da onlarsız). | Properties → Export |
| Kaydedilmemiş değişiklikler | Düzenlenmiş ama kaydedilmemiş olanlar (script'ler, boyanmış dokular) `*` ile işaretlenir. Kapatırken ya da başka bir proje açarken, bir uyarı kaybolacak olanları listeler. | Otomatik |
| Kaynak içeride ya da dışarıda | Harici bir kaynak kopyalanmaz: yolu kaydedilir ve eksikse uyarı verilir. | Resource kartı; IDE'de ve UV Editor'de "Save inside / outside the .w3d" |

Kaydetme işlemi dosyayı asla yarım bırakmaz: önce geçici bir kopya yazar, sonra onu yeniden adlandırır.
