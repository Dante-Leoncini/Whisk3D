# Tastiera, controller, touch e mouse

| Funzione | Cosa fa |
|---|---|
| `tecla(nombre) → bool` | Il tasto è premuto (finché lo tieni premuto). |
| `teclaApretada(nombre) → bool` | È stato premuto proprio in questo fotogramma (una sola volta per pressione). |
| `boton(nombre)`, `botonApretado(nombre)` | Lo stesso con un pulsante del controller. |
| `stick(["izq"\|"der"]) → x, y` | Levetta del controller, da -1 a 1 (in alto è -1). |
| `gatillo(["izq"\|"der"]) → 0..1` | Grilletto analogico. |
| `controles() → n`, `control([n]) → nombre, tipo` | Quanti controller ci sono e di che tipo (`"xbox"`, `"playstation"`, `"nintendo"`, `"generico"`). |
| `toque() → x, y, tocando` | Il dito (o il clic del mouse) sullo schermo. |
| `dedo([n]) → x, y, activo` | Multitouch: il dito numero n (da 1 a 4). |
| `apretado(obj) → bool` | Quell'elemento 2D è stato toccato o cliccato in questo fotogramma (pulsanti). |
| `raton() → x, y, dentro` | Dove si trova il mouse. |
| `capturarRaton(bool)`, `ratonRel() → dx, dy`, `ratonCapturado()` | Mouse catturato per guardarsi intorno con il mouse (giochi in prima persona, solo PC). |
