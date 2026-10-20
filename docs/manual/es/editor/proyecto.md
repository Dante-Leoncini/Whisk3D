# El proyecto (.w3d) y los archivos

| Función | Descripción | Dónde |
|---|---|---|
| Abrir proyecto | Abre un .w3d (también con doble click desde el sistema). | Propiedades → Archivo/Render → Archivo |
| Guardar / Guardar como | Guarda en la carpeta y con el nombre de la tarjeta; Guardar como pide otro. Si falta el nombre, el campo se pone rojo. | Tarjeta Archivo, <kbd>Ctrl+S</kbd> |
| Guardar versión | Guarda y además deja una copia numerada (`proyecto_v03.w3d`). | Tarjeta Archivo |
| Extraer assets | Copia todo lo de adentro a una carpeta (las copias no cambian el proyecto). | Tarjeta Archivo |
| Mallas en texto | Guarda las mallas como texto legible en vez de binario. | Tarjeta Archivo |
| Importar | OBJ, FBX, glTF, GLB e interfaces .w3dui. Lo importado se copia adentro del proyecto (sin duplicados). | Vista 3D → Añadir → Importar |
| Exportar | OBJ, glTF o GLB del objeto seleccionado (con o sin modificadores y transformaciones). | Propiedades → Exportar |
| Cambios sin guardar | Lo editado y no guardado (scripts, texturas pintadas) se marca con `*`. Al cerrar o abrir otro proyecto, un aviso lista lo que se perdería. | Automático |
| Recurso adentro o afuera | Un recurso externo no se copia: se guarda su ruta y se avisa si falta. | Tarjeta Recurso; "Guardar en / fuera del w3d" en IDE y Editor UV |

El guardado nunca deja el archivo a medias: primero escribe una copia temporal y después la renombra.

## En el navegador (versión web)

El navegador no deja que una página lea ni escriba los archivos de la PC por su cuenta. Por eso, en la versión web:

- **Abrir proyecto**, **Importar** y elegir una textura abren el explorador de archivos del navegador: aparece un cartel con el botón **Elegir archivo**. Para un OBJ se eligen juntos el .obj, su .mtl y sus texturas; para un glTF, el .gltf y su .bin.
- **Guardar** (<kbd>Ctrl+S</kbd>), **Guardar como**, **Guardar versión** y **Extraer assets** descargan el archivo a la carpeta de descargas del navegador. Lo mismo pasa con **Exportar** (el OBJ baja con su .mtl y sus texturas al lado), el render, el mapa UV, las texturas pintadas guardadas afuera y los scripts externos.
- Cuando el editor pide una carpeta para guardar, no se abre ningún explorador: el archivo se descarga directamente.
- Si el navegador pregunta si la página puede descargar varios archivos, hay que aceptar. Si no, solo baja el primero.
- Lo abierto vive en la memoria de la página: al recargarla se pierde todo lo que no se descargó.
