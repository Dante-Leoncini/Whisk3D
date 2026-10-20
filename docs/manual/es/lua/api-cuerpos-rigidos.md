# Cuerpos rígidos, choques y hitboxes

| Función | Qué hace |
|---|---|
| `fisicaVel`, `fisicaVelAng`, `fisicaImpulso`, `fisicaFuerza` | Velocidad, giro, empujones y fuerzas de un cuerpo rígido. |
| `fisicaGravedad([g])`, `fisicaActiva(obj, bool)`, `fisicaDespierto(obj)` | Gravedad (9.81 de fábrica), prender/apagar la física de un objeto. |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | Tira un rayo y dice contra qué choca. |
| `contactos() → lista` | Todos los choques de este cuadro. |
| `colSuelo(malla, x, y, z)`, `colPared(...)`, `colRayo(...)` | Choque contra los triángulos de una malla (pisar el suelo, no atravesar paredes). |
| `hitboxActivo`, `setHitboxActivo`, `setHitboxTam`, `hitboxDentro`, `hitboxTocando` | Manejar hitboxes y preguntar qué hay adentro. |
| `verHitboxes(bool)` | Dibuja los hitboxes para depurar. |
