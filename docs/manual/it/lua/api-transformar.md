# Spostare, ruotare e scalare in 3D

| Funzione | Cosa fa |
|---|---|
| `posicion(obj) → x, y, z` | Dove si trova. |
| `setPosicion(obj, x, y, z)` | Lo mette in un punto esatto (ignora la fisica). |
| `mover(obj, dx, dy, dz)` | Lo sposta da dove si trova (usalo con `dt`). |
| `rotacion(obj) → x, y, z` | La sua rotazione in gradi. |
| `setRotacion(obj, x, y, z [, orden])` | Rotazione esatta; `orden` è per esempio `"YXZ"` (predefinito `"XYZ"`). |
| `girar(obj, dx, dy, dz)` | Lo ruota sui propri assi. |
| `girarHacia(obj, dx, dz [, factor])` | Lo fa ruotare gradualmente verso una direzione sul pavimento. |
| `mirarA(obj, x, y, z)` | Lo punta verso un punto (il fronte di una camera). |
| `escala(obj) → sx, sy, sz` | La sua scala. |
| `setEscala(obj, s [, sy, sz])` | Scala esatta; con un solo numero scala in modo uniforme. |
| `escalar(obj, f)` | Moltiplica la scala attuale. |
| `puntoMundo(obj, x, y, z) → x, y, z` | Converte un punto dell'oggetto in coordinate del mondo. |
| `visible(obj) → bool`, `setVisible(obj, bool)` | Lo mostra o lo nasconde. Un oggetto nascosto smette di ricevere `actualizar`. |
| `setTinte(obj, r, g, b [, a])` | Ne cambia il colore (valori da 0 a 1). |
