# Corpi rigidi, collisioni e hitbox

| Funzione | Cosa fa |
|---|---|
| `fisicaVel`, `fisicaVelAng`, `fisicaImpulso`, `fisicaFuerza` | Velocità, rotazione, spinte e forze di un corpo rigido. |
| `fisicaGravedad([g])`, `fisicaActiva(obj, bool)`, `fisicaDespierto(obj)` | Gravità (9.81 predefinita), accendere/spegnere la fisica di un oggetto. |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | Lancia un raggio e dice contro cosa colpisce. |
| `contactos() → lista` | Tutte le collisioni di questo fotogramma. |
| `colSuelo(malla, x, y, z)`, `colPared(...)`, `colRayo(...)` | Collisione contro i triangoli di una mesh (camminare sul pavimento, non attraversare i muri). |
| `hitboxActivo`, `setHitboxActivo`, `setHitboxTam`, `hitboxDentro`, `hitboxTocando` | Gestire gli hitbox e chiedere cosa c'è dentro. |
| `verHitboxes(bool)` | Disegna gli hitbox per il debug. |
