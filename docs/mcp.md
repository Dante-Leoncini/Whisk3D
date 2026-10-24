# MCP: Whisk3D para IAs

Whisk3D fue hecho para personas, pero el avance de la IA es innegable. Así que se agregó un MCP para que puedan usarlo.

El **MCP** (Model Context Protocol) es un estándar abierto para que una IA, como Claude, use programas: el programa le ofrece herramientas con un nombre y una descripción, y la IA las llama para hacer cosas. Con `whisk3d --mcp`, el editor abre como siempre y además atiende a la IA. Lo que hace se ve en la ventana y se deshace con Ctrl+Z, como si lo hubiera hecho una persona.

Las herramientas:

| Herramienta | Qué hace |
|---|---|
| `escena` | El árbol de objetos: nombre, tipo, posición, rotación, escala, selección |
| `captura` | Una imagen de la vista 3D o de la ventana entera, para ver el resultado |
| `agregar_objeto` | Cubo, plano, círculo, esfera, cono, cilindro, vértice, empty, cámara o luz |
| `seleccionar`, `transformar`, `borrar_seleccion` | Elegir objetos por nombre y moverlos, rotarlos, escalarlos o borrarlos |
| `deshacer` | Ctrl+Z y Ctrl+Y |
| `abrir_proyecto`, `guardar_proyecto`, `importar_modelo` | Archivos `.w3d`, `.obj`, `.fbx`, `.gltf` y `.glb` |
| `comando` | Todo lo demás: los más de 600 comandos del editor (modo edición, extrude, modificadores, materiales, UV, animación, exportar, render...) |

Las coordenadas son las del panel Propiedades, con Z para arriba.

**Configurarlo en Claude Code:**

```bash
claude mcp add whisk3d -- /ruta/a/whisk3d --mcp
```

**En otros clientes** (Claude Desktop y la mayoría), en su archivo de configuración:

```json
{ "mcpServers": { "whisk3d": { "command": "/ruta/a/whisk3d", "args": ["--mcp"] } } }
```

Sin ventana (por ejemplo, en un servidor), con la variable de entorno `SDL_VIDEODRIVER=offscreen`.

El MCP está solo en la versión de PC; por ahora se probó en GNU/Linux. Las versiones de Symbian, Dreamcast y 3DS no lo incluyen, así que no les cuesta nada. En la PC, sin `--mcp`, tampoco.
