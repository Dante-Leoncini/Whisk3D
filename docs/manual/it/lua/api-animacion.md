# Animazione

| Funzione | Cosa fa |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | Animazioni di tutta la scena. |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | Clip di animazione di un oggetto e dei suoi figli. |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | Animazioni di un'armatura (camminare, saltare…) e la transizione morbida tra di esse. |
| `animCapa(esq, n, clip [, peso, modo])` e famiglia | Mescolare più animazioni contemporaneamente a livelli (da 1 a 16), per esempio correre + sparare. |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | Dove si trova un osso (per mettere un'arma in mano). |
| `animar(malla, n [, frame])` | Cambia l'animazione dei vertici di una mesh. |
