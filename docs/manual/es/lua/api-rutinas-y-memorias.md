# Rutinas y memorias

Las rutinas (listas de pasos de dibujo que se arman en el panel de Propiedades) pueden leer valores que pone Lua. Cada memoria es un bloque de 256 números con nombre, y los pasos la leen como `@nombre[i]`.

| Función | Qué hace |
|---|---|
| `setMemoria(nombre, i, v)`, `memoria(nombre, i)`, `setMemorias(nombre, i, v1, v2, ...)` | Escribir y leer memorias (el índice va de **0** a 255). |
| `setPaso(rutina, i, campo, ...)`, `leerPaso(rutina, i, campo)` | Cambiar o leer un paso de una rutina (campos: `"on"`, `"n"`, `"color"`, `"ref"`, `"modo"`, `"entero"`). |
| `paso(nombre, ...)` | Ejecuta un paso de dibujo; solo vale dentro de una función llamada por el paso "Llamar Lua" de una rutina. |

En una rutina con **Repetir** mayor que 1, la memoria `bucle` dice en qué vuelta va: `@bucle[0]` es la vuelta actual (desde 0) y `@bucle[1]` el total.
