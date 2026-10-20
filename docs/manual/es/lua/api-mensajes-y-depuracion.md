# Mensajes y depuración

| Función | Qué hace |
|---|---|
| `print(...)` | Escribe en el registro (log) del motor, no en pantalla. |
| `info(msg)`, `aviso(msg)`, `error(msg)` | Mensajes de información, aviso o error en el registro. `error` **no** corta el script. |
| `depurar(msg)`, `esDebug()` | Mensajes solo en versiones de depuración. |
| `logCantidad()`, `logLinea(i)` | Leer el registro desde el juego (una consola propia). |
