# Lo básico de Lua

## Comentarios

```lua
-- esto es un comentario de una línea
--[[ esto es un comentario
     de varias líneas ]]
```

## Variables y tipos

Una variable se crea al asignarle un valor. Usá siempre `local`: la variable existe solo dentro del bloque donde se declaró y no choca con otras.

```lua
local vidas = 3           -- número (entero)
local velocidad = 2.5     -- número (con decimales)
local nombre = "Whisky"   -- texto (string)
local vivo = true         -- booleano: true o false
local nada = nil          -- nil = "sin valor"
```

Los tipos de Lua son: `nil`, `boolean`, `number`, `string`, `table` y `function`. Los objetos de la escena que te da Whisk3D son un tipo especial que solo se usa pasándolo a las funciones del motor.

## Operadores

| Operador | Qué hace | Ejemplo |
|---|---|---|
| `+ - * /` | Suma, resta, multiplicación, división (siempre con decimales) | `7 / 2` → 3.5 |
| `//` | División entera | `7 // 2` → 3 |
| `%` | Resto | `7 % 2` → 1 |
| `^` | Potencia | `2 ^ 3` → 8.0 |
| `== ~= < > <= >=` | Comparaciones (`~=` es "distinto") | `vidas ~= 0` |
| `and or not` | Lógicos | `vivo and vidas > 0` |
| `..` | Unir textos | `"Vidas: " .. vidas` |
| `#` | Largo de un texto o de una lista | `#"hola"` → 4 |

> [!NOTE]
> En Lua, solo `false` y `nil` son "falso". El `0` y el texto vacío `""` cuentan como **verdadero**.

## Decisiones: if

```lua
if vidas <= 0 then
  print("perdiste")
elseif vidas == 1 then
  print("última vida")
else
  print("seguís jugando")
end
```

## Repeticiones: for y while

```lua
for i = 1, 10 do          -- de 1 a 10
  print(i)
end
for i = 10, 0, -2 do      -- de 10 a 0, de a 2 para abajo
  print(i)
end
local n = 0
while n < 5 do
  n = n + 1
end
```

Lua no tiene `n++` ni `n += 1`: se escribe `n = n + 1`. Para cortar un bucle se usa `break`.

## Funciones

```lua
local function sumar(a, b)
  return a + b
end
print(sumar(2, 3))        -- 5

-- una función puede devolver varios valores
local function minMax(a, b)
  if a < b then return a, b else return b, a end
end
local menor, mayor = minMax(8, 3)
```

Muchas funciones de Whisk3D devuelven varios valores a la vez, por ejemplo `local x, y, z = posicion(yo())`.

## Tablas: listas y diccionarios

La tabla es la única estructura de datos de Lua y sirve para todo.

```lua
-- como lista (los índices empiezan en 1, no en 0)
local frutas = { "manzana", "pera", "uva" }
print(frutas[1])          -- manzana
print(#frutas)            -- 3
frutas[#frutas + 1] = "kiwi"   -- agregar al final
table.insert(frutas, "melón")  -- otra forma

for i, f in ipairs(frutas) do  -- recorrer una lista en orden
  print(i, f)
end

-- como diccionario (clave = valor)
local jugador = { nombre = "Ana", puntos = 0 }
jugador.puntos = jugador.puntos + 10
print(jugador["nombre"])  -- Ana

for clave, valor in pairs(jugador) do  -- recorrer todas las claves (sin orden fijo)
  print(clave, valor)
end
```

## Textos y números útiles

```lua
local t = string.format("Puntos: %d  Tiempo: %.1f", 120, 3.456)  -- "Puntos: 120  Tiempo: 3.5"
local may = string.upper("hola")        -- "HOLA"
local parte = string.sub("Whisk3D", 1, 5)   -- "Whisk"
local n = tonumber("42")                -- texto a número
local s = tostring(3.5)                 -- número a texto
local r = math.floor(2.7)               -- 2
local d = math.sqrt(16)                 -- 4.0
local a = math.abs(-3)                  -- 3
local m = math.max(4, 9, 2)             -- 9
local pi = math.pi
```

Para números al azar, Whisk3D tiene `azar()` (ver la referencia). También anda `math.random`, que ya viene sembrado distinto en cada partida.
