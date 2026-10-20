# Límites y consejos

## Qué partes de Lua no están

- Están `string`, `table` y `math`, más las funciones básicas (`print`, `pairs`, `ipairs`, `type`, `tostring`, `tonumber`, `pcall`, `assert`…).
- **No** están `io` ni `os` (un juego no toca archivos del disco; por eso no hay `os.time`), ni `require`, `coroutine`, `utf8` ni `debug`. Para guardar datos usá `config` / `guardarConfig`.
- Cada script es independiente: no puede ver las variables de otro. Para comunicarse, `setCompartido` / `compartido`.

## Errores

- Si una función tiene un error, se anota en el registro (`archivo.lua:LÍNEA: mensaje`) y esa llamada se corta, pero se vuelve a llamar en el cuadro siguiente: el mismo error se repite en cada cuadro hasta que lo arregles.
- Si el archivo no se puede leer o tiene un error de sintaxis, ese script queda apagado hasta el próximo Play.
- `error("...")` en Whisk3D solo anota el mensaje y el script sigue. Si querés cortar, usá `assert(condicion, "mensaje")`.

## Cosas a tener en cuenta

- `actualizar` solo corre en objetos **visibles** de la escena activa: ocultar un objeto apaga su lógica.
- `destruir`, `cambiarEscena` y `reproducirEscena` se aplican al final del cuadro, no en el momento.
- La fuente de los textos del juego no dibuja tildes ni eñes: escribí `"MENU"` en vez de `"MENÚ"`.
- `areaSegura`, `cajaUI` y `resolucion` recién tienen valores reales después del primer cuadro dibujado: no las uses en `inicio`.
- En Web y Android solo la **primera** luz ilumina.
- En el Nokia N95 no hay mando ni mouse: usá `tecla` con los nombres del teclado del teléfono. Los números enteros son de 32 bits.

## Para que ande rápido (sobre todo en el teléfono)

- Buscá los objetos una sola vez, en `inicio`, y guardalos en variables `local`.
- Usá las versiones "de a muchos" (`setVertices`, `setVerticesColor`) en vez de llamar mil veces a la de uno.
- Preferí las funciones del motor (`desplazarUV`, `lineaPunto`, `setRotacion` con orden) antes que hacer las cuentas en Lua.
- Medí con `perfilLua` y `relojMs` antes de optimizar a ciegas.
