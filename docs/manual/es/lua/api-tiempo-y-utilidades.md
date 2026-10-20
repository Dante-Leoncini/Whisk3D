# Tiempo, azar y utilidades

| Función | Qué hace |
|---|---|
| `azar() → 0..1`, `azar(min, max) → entero` | Números al azar. |
| `relojMs() → ms` | Milisegundos, para medir cuánto tarda algo. |
| `perfilLua(cuadros [, etiqueta])` | Mide qué partes del script son lentas (`perfilLua(0)` lo apaga). |
| `lineaCrear(nombre, puntos)`, `lineaPunto(id, s)` | Una curva suave cerrada calculada por el motor (recorridos). |

No hay una función de "tiempo desde que empezó": sumá `dt` en una variable.
