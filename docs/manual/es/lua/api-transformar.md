# Mover, rotar y escalar en 3D

| Función | Qué hace |
|---|---|
| `posicion(obj) → x, y, z` | Dónde está. |
| `setPosicion(obj, x, y, z)` | Lo pone en un lugar exacto (ignora la física). |
| `mover(obj, dx, dy, dz)` | Lo corre desde donde está (usalo con `dt`). |
| `rotacion(obj) → x, y, z` | Su rotación en grados. |
| `setRotacion(obj, x, y, z [, orden])` | Rotación exacta; `orden` es por ejemplo `"YXZ"` (de fábrica `"XYZ"`). |
| `girar(obj, dx, dy, dz)` | Lo gira sobre sus propios ejes. |
| `girarHacia(obj, dx, dz [, factor])` | Lo va girando suave hacia una dirección del piso. |
| `mirarA(obj, x, y, z)` | Lo apunta hacia un punto (el frente de una cámara). |
| `escala(obj) → sx, sy, sz` | Su escala. |
| `setEscala(obj, s [, sy, sz])` | Escala exacta; con un solo número escala parejo. |
| `escalar(obj, f)` | Multiplica la escala actual. |
| `puntoMundo(obj, x, y, z) → x, y, z` | Pasa un punto del objeto a coordenadas del mundo. |
| `visible(obj) → bool`, `setVisible(obj, bool)` | Lo muestra u oculta. Un objeto oculto deja de recibir `actualizar`. |
| `setTinte(obj, r, g, b [, a])` | Le cambia el color (valores de 0 a 1). |
