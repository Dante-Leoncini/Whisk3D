# A script is a component of an object

In Whisk3D a script always belongs to an **object** in the scene (a mesh, an empty, a 2D button…). An object can have several scripts; each one runs separately, with its own variables, in the order they appear.

From the script, `yo()` returns the object that owns it. To use *other* objects, the script declares a global table called `propiedades`. The editor reads it and shows a field for each entry in the script's card, in the Properties panel:

```lua
propiedades = {
  pelota     = "objeto",                          -- a field to pick an object from the scene
  dificultad = { "facil", "normal", "dificil" },  -- a drop-down list (the first one is the default)
  velocidad  = 200,                               -- a number of its own for each object that uses the script
  activo     = true,                              -- a yes/no
  etiqueta   = "caja",                            -- a text
}

function inicio()
  local p   = objeto("pelota")         -- the object picked in the "pelota" field
  local dif = opcion("dificultad")     -- "facil", "normal" or "dificil"
  local v   = propiedad("velocidad")   -- 200, or whatever was set on that object
end
```

That way, the same script works for many objects with different values: one enemy's `velocidad` field can be 200 and another's 350.

> [!NOTE]
> To read `propiedades`, the editor **runs the file** even when the game isn't running. That's why, outside the functions, you should only put declarations (tables, constants, `local`), never code that does things.

Scripts don't share variables with each other. To pass data around (the score, whether the player won…) they use a shared space: `setCompartido("puntos", 10)` writes and `compartido("puntos")` reads. It stores numbers, yes/no values and strings, and it's emptied when the game stops.
