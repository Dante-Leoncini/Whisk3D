# Interfaccia 2D e schermo

| Funzione | Cosa fa |
|---|---|
| `pantalla() → ancho, alto` | Dimensione della tela. |
| `areaSegura() → x, y, w, h` | La parte dello schermo senza notch (non usarla in `inicio`). |
| `escala() → f` | Senza argomenti: fattore per adattare le dimensioni allo schermo (lato minore / 480). |
| `posPx(obj) → x, y`, `setPosPx(obj, x, y)` | Posizione di un elemento 2D (un `nil` lascia invariato quell'asse). |
| `tamPx(obj) → w, h`, `setTamPx(obj, w, h)` | Dimensione di un elemento 2D. |
| `cajaUI(obj) → x, y, w, h` | Il rettangolo che occupa davvero (x, y = centro). |
| `setTexto(obj, valor)`, `setTam(texto, px)` | Cambia il testo di un testo o di un pulsante, e la dimensione del carattere. |
| `setTextura(img, "ruta.png")`, `setUVRect`, `setFlipbook` | Cambia l'immagine, ne ritaglia una parte, o anima un foglio di fotogrammi. |
| `setOpacidad(obj, 0..1)`, `fundir(obj, objetivo, paso)` | Trasparenza e dissolvenze. |
| `setRot2D(obj, grados)` | Ruota un elemento 2D. |
| `chocan(a, b) → bool` | Se due elementi 2D si sovrappongono sullo schermo. |
| `limitar(obj, area [, eje])`, `dentro(area, x [, y])` | Mantenere un elemento dentro un altro, o chiedere se un punto è dentro. |
| `salir()` | Chiude il gioco (nell'editor non fa nulla). |
