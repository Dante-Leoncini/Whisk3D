# Time, randomness and utilities

| Function | What it does |
|---|---|
| `azar() → 0..1`, `azar(min, max) → entero` | Random numbers. |
| `relojMs() → ms` | Milliseconds, to measure how long something takes. |
| `perfilLua(cuadros [, etiqueta])` | Measures which parts of the script are slow (`perfilLua(0)` turns it off). |
| `lineaCrear(nombre, puntos)`, `lineaPunto(id, s)` | A smooth closed curve calculated by the engine (paths). |

There's no "time since start" function: add up `dt` in a variable.
