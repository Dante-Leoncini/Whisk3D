# Simple physics (velocity and bounces)

| Function | What it does |
|---|---|
| `velocidad(obj, vx [, vy, vz])` / `velocidad(obj) → vx, vy, vz` | You give it a velocity and the engine moves it by itself. |
| `acelerar(obj, factor [, tope])` | Speeds it up by multiplying its velocity. |
| `caja(obj [, w, h, d])` | The size of its collision box. |
| `rebotar(obj, otro)`, `rebotarEn(obj, area [, lados])`, `rebotarDentro(obj, area)` | Bounces off another object or off the edges of an area (they return `true` if it bounced). |
