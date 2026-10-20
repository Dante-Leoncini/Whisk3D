# Rigid bodies, collisions and hitboxes

| Function | What it does |
|---|---|
| `fisicaVel`, `fisicaVelAng`, `fisicaImpulso`, `fisicaFuerza` | Velocity, spin, pushes and forces of a rigid body. |
| `fisicaGravedad([g])`, `fisicaActiva(obj, bool)`, `fisicaDespierto(obj)` | Gravity (9.81 by default), turning an object's physics on/off. |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | Casts a ray and tells you what it hits. |
| `contactos() → lista` | All the collisions in this frame. |
| `colSuelo(malla, x, y, z)`, `colPared(...)`, `colRayo(...)` | Collision against the triangles of a mesh (standing on the floor, not going through walls). |
| `hitboxActivo`, `setHitboxActivo`, `setHitboxTam`, `hitboxDentro`, `hitboxTocando` | Manage hitboxes and ask what's inside them. |
| `verHitboxes(bool)` | Draws the hitboxes for debugging. |
