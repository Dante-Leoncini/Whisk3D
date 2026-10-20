# Animation

| Fonction | Ce qu'elle fait |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | Animations de toute la scène. |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | Clips d'animation d'un objet et de ses enfants. |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | Animations d'une armature (marcher, sauter…) et transition douce entre elles. |
| `animCapa(esq, n, clip [, peso, modo])` et ses variantes | Mélanger plusieurs animations à la fois en couches (1 à 16), par exemple courir + tirer. |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | La position d'un os (pour placer une arme dans la main). |
| `animar(malla, n [, frame])` | Change l'animation de sommets d'un maillage. |
