# Clavier, manette, tactile et souris

| Fonction | Ce qu'elle fait |
|---|---|
| `tecla(nombre) → bool` | La touche est enfoncée (tant que vous la maintenez). |
| `teclaApretada(nombre) → bool` | La touche vient d'être enfoncée à cette image (une seule fois par appui). |
| `boton(nombre)`, `botonApretado(nombre)` | La même chose avec un bouton de la manette. |
| `stick(["izq"\|"der"]) → x, y` | Stick de la manette, de -1 à 1 (le haut vaut -1). |
| `gatillo(["izq"\|"der"]) → 0..1` | Gâchette analogique. |
| `controles() → n`, `control([n]) → nombre, tipo` | Le nombre de manettes et leur type (`"xbox"`, `"playstation"`, `"nintendo"`, `"generico"`). |
| `toque() → x, y, tocando` | Le doigt (ou le clic de la souris) sur l'écran. |
| `dedo([n]) → x, y, activo` | Multitouch : le doigt numéro n (1 à 4). |
| `apretado(obj) → bool` | Cet élément 2D a été touché ou cliqué à cette image (boutons). |
| `raton() → x, y, dentro` | La position de la souris. |
| `capturarRaton(bool)`, `ratonRel() → dx, dy`, `ratonCapturado()` | Souris capturée pour regarder autour avec la souris (jeux à la première personne, PC uniquement). |
