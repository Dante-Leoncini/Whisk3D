# Animación

| Función | Qué hace |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | Animaciones de toda la escena. |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | Clips de animación de un objeto y sus hijos. |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | Animaciones de un esqueleto (caminar, saltar…) y la transición suave entre ellas. |
| `animCapa(esq, n, clip [, peso, modo])` y familia | Mezclar varias animaciones a la vez en capas (1 a 16), por ejemplo correr + disparar. |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | Dónde está un hueso (para poner un arma en la mano). |
| `animar(malla, n [, frame])` | Cambia la animación de vértices de una malla. |
