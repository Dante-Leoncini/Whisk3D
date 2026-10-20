# Klavye, oyun kumandası, dokunmatik ekran ve fare

| Fonksiyon | Ne yapar |
|---|---|
| `tecla(nombre) → bool` | Tuş basılı (basılı tuttuğun sürece). |
| `teclaApretada(nombre) → bool` | Tam bu karede basıldı (her basışta yalnızca bir kez). |
| `boton(nombre)`, `botonApretado(nombre)` | Aynısı, oyun kumandasının bir düğmesi için. |
| `stick(["izq"\|"der"]) → x, y` | Kumandanın analog çubuğu, -1'den 1'e (yukarı -1'dir). |
| `gatillo(["izq"\|"der"]) → 0..1` | Analog tetik. |
| `controles() → n`, `control([n]) → nombre, tipo` | Kaç kumanda olduğu ve türleri (`"xbox"`, `"playstation"`, `"nintendo"`, `"generico"`). |
| `toque() → x, y, tocando` | Ekrandaki parmak (ya da fare tıklaması). |
| `dedo([n]) → x, y, activo` | Çoklu dokunma: n numaralı parmak (1'den 4'e). |
| `apretado(obj) → bool` | Bu karede o 2D öğeye dokunuldu ya da tıklandı (düğmeler). |
| `raton() → x, y, dentro` | Farenin nerede olduğu. |
| `capturarRaton(bool)`, `ratonRel() → dx, dy`, `ratonCapturado()` | Fareyle etrafa bakmak için yakalanmış fare (birinci şahıs oyunları, yalnızca PC). |
