# Corpos rígidos, colisões e hitboxes

| Função | O que faz |
|---|---|
| `fisicaVel`, `fisicaVelAng`, `fisicaImpulso`, `fisicaFuerza` | Velocidade, giro, empurrões e forças de um corpo rígido. |
| `fisicaGravedad([g])`, `fisicaActiva(obj, bool)`, `fisicaDespierto(obj)` | Gravidade (9.81 por padrão), ligar/desligar a física de um objeto. |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | Lança um raio e diz com o que ele colide. |
| `contactos() → lista` | Todas as colisões deste quadro. |
| `colSuelo(malla, x, y, z)`, `colPared(...)`, `colRayo(...)` | Colisão contra os triângulos de uma malha (pisar no chão, não atravessar paredes). |
| `hitboxActivo`, `setHitboxActivo`, `setHitboxTam`, `hitboxDentro`, `hitboxTocando` | Gerenciar hitboxes e perguntar o que há dentro. |
| `verHitboxes(bool)` | Desenha os hitboxes para depurar. |
