# Le basi di Lua

## Commenti

```lua
-- questo è un commento di una riga
--[[ questo è un commento
     di più righe ]]
```

## Variabili e tipi

Una variabile si crea assegnandole un valore. Usa sempre `local`: la variabile esiste solo dentro il blocco in cui è stata dichiarata e non entra in conflitto con altre.

```lua
local vidas = 3           -- numero (intero)
local velocidad = 2.5     -- numero (con decimali)
local nombre = "Whisky"   -- testo (string)
local vivo = true         -- booleano: true o false
local nada = nil          -- nil = "nessun valore"
```

I tipi di Lua sono: `nil`, `boolean`, `number`, `string`, `table` e `function`. Gli oggetti della scena che ti dà Whisk3D sono un tipo speciale che si usa solo passandolo alle funzioni del motore.

## Operatori

| Operatore | Cosa fa | Esempio |
|---|---|---|
| `+ - * /` | Somma, sottrazione, moltiplicazione, divisione (sempre con decimali) | `7 / 2` → 3.5 |
| `//` | Divisione intera | `7 // 2` → 3 |
| `%` | Resto | `7 % 2` → 1 |
| `^` | Potenza | `2 ^ 3` → 8.0 |
| `== ~= < > <= >=` | Confronti (`~=` significa "diverso") | `vidas ~= 0` |
| `and or not` | Logici | `vivo and vidas > 0` |
| `..` | Unire testi | `"Vidas: " .. vidas` |
| `#` | Lunghezza di un testo o di una lista | `#"hola"` → 4 |

> [!NOTE]
> In Lua, solo `false` e `nil` sono "falso". Lo `0` e il testo vuoto `""` contano come **vero**.

## Decisioni: if

```lua
if vidas <= 0 then
  print("perdiste")
elseif vidas == 1 then
  print("última vida")
else
  print("seguís jugando")
end
```

## Ripetizioni: for e while

```lua
for i = 1, 10 do          -- da 1 a 10
  print(i)
end
for i = 10, 0, -2 do      -- da 10 a 0, scendendo di 2 alla volta
  print(i)
end
local n = 0
while n < 5 do
  n = n + 1
end
```

Lua non ha `n++` né `n += 1`: si scrive `n = n + 1`. Per interrompere un ciclo si usa `break`.

## Funzioni

```lua
local function sumar(a, b)
  return a + b
end
print(sumar(2, 3))        -- 5

-- una funzione può restituire più valori
local function minMax(a, b)
  if a < b then return a, b else return b, a end
end
local menor, mayor = minMax(8, 3)
```

Molte funzioni di Whisk3D restituiscono più valori alla volta, per esempio `local x, y, z = posicion(yo())`.

## Tabelle: liste e dizionari

La tabella è l'unica struttura dati di Lua e serve per tutto.

```lua
-- come lista (gli indici partono da 1, non da 0)
local frutas = { "manzana", "pera", "uva" }
print(frutas[1])          -- manzana
print(#frutas)            -- 3
frutas[#frutas + 1] = "kiwi"   -- aggiungere in fondo
table.insert(frutas, "melón")  -- un altro modo

for i, f in ipairs(frutas) do  -- percorrere una lista in ordine
  print(i, f)
end

-- come dizionario (chiave = valore)
local jugador = { nombre = "Ana", puntos = 0 }
jugador.puntos = jugador.puntos + 10
print(jugador["nombre"])  -- Ana

for clave, valor in pairs(jugador) do  -- percorrere tutte le chiavi (senza un ordine fisso)
  print(clave, valor)
end
```

## Testi e numeri utili

```lua
local t = string.format("Puntos: %d  Tiempo: %.1f", 120, 3.456)  -- "Puntos: 120  Tiempo: 3.5"
local may = string.upper("hola")        -- "HOLA"
local parte = string.sub("Whisk3D", 1, 5)   -- "Whisk"
local n = tonumber("42")                -- da testo a numero
local s = tostring(3.5)                 -- da numero a testo
local r = math.floor(2.7)               -- 2
local d = math.sqrt(16)                 -- 4.0
local a = math.abs(-3)                  -- 3
local m = math.max(4, 9, 2)             -- 9
local pi = math.pi
```

Per i numeri casuali, Whisk3D ha `azar()` (vedi il riferimento). Funziona anche `math.random`, che parte già con un seme diverso in ogni partita.
