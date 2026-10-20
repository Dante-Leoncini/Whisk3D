# Animation

| Function | What it does |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | Animations of the whole scene. |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | Animation clips of an object and its children. |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | Animations of an armature (walk, jump…) and the smooth transition between them. |
| `animCapa(esq, n, clip [, peso, modo])` and related functions | Blend several animations at once in layers (1 to 16), for example run + shoot. |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | Where a bone is (to put a weapon in a hand). |
| `animar(malla, n [, frame])` | Changes a mesh's vertex animation. |
