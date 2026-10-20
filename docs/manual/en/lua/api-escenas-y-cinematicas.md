# Scenes and cutscenes

| Function | What it does |
|---|---|
| `cambiarEscena(nombre [, reiniciar])` | Switches to another scene (menu, level 2…) at the end of the frame. |
| `reproducirEscena(nombre [, "funcion"])` | Plays a 3D scene as a cutscene with the game paused; when it ends, it calls that function. |
| `pararEscena3D()`, `escenaReproduciendo()` | Stops the cutscene / tells you which one is playing. |
| `dibujar3D([on])` | Turns all the 3D off or on (for example, behind an opaque menu). |
