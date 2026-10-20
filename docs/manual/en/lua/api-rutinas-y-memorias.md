# Routines and memories

Routines (lists of drawing steps built in the Properties panel) can read values set by Lua. Each memory is a named block of 256 numbers, and the steps read it as `@nombre[i]`.

| Function | What it does |
|---|---|
| `setMemoria(nombre, i, v)`, `memoria(nombre, i)`, `setMemorias(nombre, i, v1, v2, ...)` | Write and read memories (the index goes from **0** to 255). |
| `setPaso(rutina, i, campo, ...)`, `leerPaso(rutina, i, campo)` | Change or read a step of a routine (fields: `"on"`, `"n"`, `"color"`, `"ref"`, `"modo"`, `"entero"`). |
| `paso(nombre, ...)` | Runs a drawing step; it only works inside a function called by a routine's "Call Lua" step. |

In a routine with **Repeat** greater than 1, the `bucle` memory tells you which pass it's on: `@bucle[0]` is the current pass (starting from 0) and `@bucle[1]` the total.
