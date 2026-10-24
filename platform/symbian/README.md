# Whisk3D en Symbian (Nokia N95 y S60)

Backend OpenGL ES 1.1. El objetivo insignia del proyecto: correr en un teléfono de 2007.

## Instalar (usuario final)

La última versión está siempre en la carpeta `sis` como `Whisk3D_gcce.sisx` (puede no funcionar del todo; está en desarrollo constante). La versión **verificada** está en `releases`, con la fecha en el nombre, referenciando los videos/imágenes de demostración de [Instagram](https://www.instagram.com/dante_leoncini).

> Ojo: algunas features van y vienen entre versiones. Por ejemplo el modelado 3D se sacó en las últimas; si querés esa función, usá una versión anterior como `Whisk3D_gcce_beta_24-08-15_FERNET.sisx`.

Si el instalador falla, probablemente tengas que "hackear" el teléfono para ignorar los certificados de Symbian: [Tutorial Hack](https://www.youtube.com/watch?v=UJJICzbk3TA).

## Compilar

El proyecto de Symbian está en esta carpeta:

- `group/Whisk3D.mmp` — el proyecto (fuentes, includes, libs). Comparte casi todo el código con el resto de las plataformas (`main/`, `libs/Whisk3DCore`, `libs/WhiskUI`); lo específico del teléfono está en `src/`.
- `src/` — la capa de Symbian: app framework (`Whisk3D*.cpp`), input (teclado/keypad, mouse virtual, HID bluetooth), carga de texturas por ICL, y el reloj/glue.
- `data/`, `sis/` — recursos e instaladores.

Se compila con el SDK de S60 3rd Edition + **Carbide.c++** (o `bldmake` + `abld` a mano). La toolchain es vieja (**C++03**: sin `nullptr`, `auto`, range-for, `vector::data`...) y no todo el subsistema nuevo (FBX, skinning) está portado — mirá los `#ifndef W3D_SYMBIAN` del código.

## Diagnosticar un cierre en el teléfono

La app escribe `E:\whisk3d.log` línea por línea, con flush a disco. Si se cierra, el log llega hasta el último paso que hizo. Tres tipos de líneas sirven para saber por qué se cerró:

- `[cierre] el hilo principal termino con un PANIC: <categoria> <numero>`: lo escribe un hilo vigía (`Whisk3DAppUi.cpp`) cuando muere el hilo principal. Por ejemplo, `KERN-EXEC 3` es un acceso a memoria inválida o la pila desbordada, y `USER 47` es el heap roto. Si sale con `[cierre] ... tipo 0` es una salida normal.
- `[mem] SIN MEMORIA: fallo un pedido de N bytes ...`: el `operator new` (`newdel_compat.cpp`) devuelve NULL cuando no hay memoria. Antes, el código que seguía escribía en NULL y no quedaba rastro.
- `[mem] <hito>: heap X KB en uso (Y KB tomados), RAM libre Z KB`: los hitos de una carga grande (contenedor montado, JSON leído, cada animset y cada prefab, proyecto abierto, texturas del Play). "Tomados" es lo que el chunk del heap ya le sacó al teléfono: los huecos que deja lo liberado no vuelven.

Pila del hilo principal: 80 KB (`EPOCSTACKSIZE 0x14000`, el máximo de EKA2).

Al arrancar, las líneas `[gl]` registran lo que expone el driver: `GL_VENDOR`, `GL_RENDERER`, `GL_VERSION`, las extensiones de GL y de EGL en tramos, los límites (luces, unidades de textura, `GL_MAX_PALETTE_MATRICES_OES`, `GL_MAX_VERTEX_UNITS_OES`) y si `eglGetProcAddress` encuentra funciones que el driver no anuncia (programas de vértices de `IMG_vertex_program`, la paleta de matrices, multi-draw).

## GPU del N95: lo que se sabe

- **El chip.** El N95 usa un OMAP2420 con PowerVR **MBX + VGP**, según la hoja de datos de TI ("2D/3D hardware MBX/VGP accelerators, up to 2 Million polygons/sec"). El VGP es el procesador de vértices programable. El OMAP2430 trae, en cambio, MBX Lite + VGP Lite.
- **El acceso al VGP.** Desde OpenGL ES 1.1 se programa con la extensión `GL_IMG_vertex_program` (ensamblador al estilo de `ARB_vertex_program`, compilado con el VGP Compiler del SDK de PowerVR). Según Imagination (foro de PowerVR, 2008), **el driver de Nokia no la expone en el N95 ni en ningún Nokia con OMAP2**, aunque otros equipos con el mismo chip sí (Samsung i8510 e i7710, Motorola Z8 y Z10). Sin esa extensión no hay programas de vértices propios.

