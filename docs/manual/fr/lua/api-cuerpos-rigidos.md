# Corps rigides, collisions et hitbox

| Fonction | Ce qu'elle fait |
|---|---|
| `fisicaVel`, `fisicaVelAng`, `fisicaImpulso`, `fisicaFuerza` | Vitesse, rotation, poussées et forces d'un corps rigide. |
| `fisicaGravedad([g])`, `fisicaActiva(obj, bool)`, `fisicaDespierto(obj)` | Gravité (9.81 par défaut), activer/désactiver la physique d'un objet. |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | Lance un rayon et indique ce qu'il touche. |
| `contactos() → lista` | Toutes les collisions de cette image. |
| `colSuelo(malla, x, y, z)`, `colPared(...)`, `colRayo(...)` | Collision avec les triangles d'un maillage (marcher sur le sol, ne pas traverser les murs). |
| `hitboxActivo`, `setHitboxActivo`, `setHitboxTam`, `hitboxDentro`, `hitboxTocando` | Gérer les hitbox et demander ce qu'elles contiennent. |
| `verHitboxes(bool)` | Dessine les hitbox pour le débogage. |
