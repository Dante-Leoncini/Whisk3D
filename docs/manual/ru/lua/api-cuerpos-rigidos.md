# Твёрдые тела, столкновения и хитбоксы

| Функция | Что делает |
|---|---|
| `fisicaVel`, `fisicaVelAng`, `fisicaImpulso`, `fisicaFuerza` | Скорость, вращение, толчки и силы твёрдого тела. |
| `fisicaGravedad([g])`, `fisicaActiva(obj, bool)`, `fisicaDespierto(obj)` | Гравитация (по умолчанию 9.81), включение/выключение физики объекта. |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | Пускает луч и сообщает, во что он попал. |
| `contactos() → lista` | Все столкновения этого кадра. |
| `colSuelo(malla, x, y, z)`, `colPared(...)`, `colRayo(...)` | Столкновение с треугольниками меша (стоять на полу, не проходить сквозь стены). |
| `hitboxActivo`, `setHitboxActivo`, `setHitboxTam`, `hitboxDentro`, `hitboxTocando` | Управлять хитбоксами и узнавать, что внутри. |
| `verHitboxes(bool)` | Рисует хитбоксы для отладки. |
