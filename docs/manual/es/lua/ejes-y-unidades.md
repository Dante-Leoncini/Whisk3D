# Ejes, unidades y objetos

- **3D:** en los scripts el eje **Y apunta para arriba**. El panel de Propiedades muestra Z arriba, así que el campo "Z" del panel es la `y` del script. Las posiciones, rotaciones y escalas son relativas al padre del objeto. Las rotaciones van en **grados**.
- **2D (pantalla y UI):** píxeles del lienzo, con el (0, 0) en el **centro**; +x hacia la derecha y +y hacia **abajo**.
- **Objetos:** las funciones que buscan o devuelven objetos (`yo`, `buscar`, `objeto`…) dan un valor que no tiene campos ni métodos: se lo pasás a otras funciones. Dos objetos se pueden comparar con `==`. Si el objeto se destruyó, se comporta como `nil`.
- **Tolerancia:** casi todas las funciones aceptan `nil` o un objeto del tipo equivocado sin romper nada: las que leen devuelven 0, `""` o `false` y las que escriben no hacen nada.
- **Índices:** como en Lua, casi todo empieza en 1 (vértices, dedos, capas, pasos de rutina). La excepción son las memorias de las rutinas (`memoria`), que van de 0 a 255.
