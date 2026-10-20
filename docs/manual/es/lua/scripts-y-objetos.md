# Un script es un componente de un objeto

En Whisk3D un script siempre pertenece a un **objeto** de la escena (una malla, un vacío, un botón 2D…). Un objeto puede tener varios scripts; cada uno corre por separado, con sus propias variables, en el orden en que aparecen.

Desde el script, `yo()` devuelve el objeto dueño. Para usar *otros* objetos, el script declara una tabla global llamada `propiedades`. El editor la lee y muestra un campo por cada entrada en la tarjeta del script, en el panel de Propiedades:

```lua
propiedades = {
  pelota     = "objeto",                          -- un campo para elegir un objeto de la escena
  dificultad = { "facil", "normal", "dificil" },  -- una lista desplegable (la primera es la de fábrica)
  velocidad  = 200,                               -- un número propio de cada objeto que use el script
  activo     = true,                              -- un sí/no
  etiqueta   = "caja",                            -- un texto
}

function inicio()
  local p   = objeto("pelota")         -- el objeto elegido en el campo "pelota"
  local dif = opcion("dificultad")     -- "facil", "normal" o "dificil"
  local v   = propiedad("velocidad")   -- 200, o lo que se haya puesto en ese objeto
end
```

Así, el mismo script sirve para muchos objetos con valores distintos: el campo `velocidad` de un enemigo puede valer 200 y el de otro 350.

> [!NOTE]
> Para leer `propiedades`, el editor **ejecuta el archivo** aunque el juego no esté corriendo. Por eso, afuera de las funciones poné solo declaraciones (tablas, constantes, `local`), nunca código que haga cosas.

Los scripts no comparten variables entre sí. Para pasarse datos (los puntos, si el jugador ganó…) usan un espacio compartido: `setCompartido("puntos", 10)` escribe y `compartido("puntos")` lee. Guarda números, sí/no y textos, y se vacía al detener el juego.
