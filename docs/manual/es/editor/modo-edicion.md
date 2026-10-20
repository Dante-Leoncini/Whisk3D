# Modo Edición (mallas)

Se entra con <kbd>Tab</kbd> sobre una malla. Se trabaja sobre **vértices**, **aristas** o **caras** según el botón de la barra superior.

## Seleccionar

| Función | Descripción | Atajo |
|---|---|---|
| Seleccionar | Elige un vértice, arista o cara. | Click; <kbd>Shift</kbd>+click alterna |
| Seleccionar vinculado | Toda la isla conectada bajo el puntero. | <kbd>L</kbd> |
| Seleccionar loop | Un anillo de aristas o de caras. | <kbd>Shift+Alt</kbd>+click |
| Camino más corto | Selecciona el camino entre el activo y el clickeado. | <kbd>Ctrl</kbd>+click |
| Camino más corto (rellenar región) | Selecciona toda la región entre los dos. | <kbd>Ctrl+Shift</kbd>+click |
| Todo / Ninguno / Invertir / Caja | Como en Modo Objeto, sobre los elementos de la malla. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## Modelar

| Función | Descripción | Atajo |
|---|---|---|
| Mover / Rotar / Escalar | Transforma lo seleccionado. Con un mover en curso, otra <kbd>G</kbd> pasa a deslizar. | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Encoger / Engordar | Mueve cada vértice por su normal (infla o desinfla). | <kbd>Alt+S</kbd> |
| Extruir | Saca geometría nueva desde lo seleccionado (las caras salen por su normal). | <kbd>E</kbd> |
| Loop Cut y Deslizar | Corta un anillo de aristas. La rueda cambia la cantidad de cortes; click aplica y después se desliza. | <kbd>Ctrl+R</kbd> |
| Nueva arista / cara desde vértices | Une los vértices seleccionados con una arista o una cara. | <kbd>F</kbd> |
| Conectar camino de vértices | Corta en línea recta entre dos vértices. | <kbd>J</kbd> |
| Deslizar vértices | Desliza los vértices a lo largo de sus aristas. | <kbd>Shift+V</kbd> |
| Rasgar | Separa la malla por la selección. | <kbd>V</kbd> |
| Duplicar | Copia lo seleccionado y lo deja agarrado. | <kbd>Shift+D</kbd> |
| Separar | Pasa las caras seleccionadas a un objeto nuevo. | <kbd>P</kbd> |
| Fusionar | Suelda vértices: en el centro, en el cursor, colapsar o por distancia. | <kbd>M</kbd> |
| Auto fusionar | Al terminar de mover, suelda los vértices que quedaron más cerca que el umbral. | Menú Malla |
| Borrar | Vértices, aristas, caras o loops de aristas. | <kbd>X</kbd> o <kbd>Supr</kbd> |
| Recalcular normales / Voltear | Corrige hacia dónde miran las caras, o las da vuelta. | <kbd>Shift+N</kbd> |
| Triangular caras | Parte en triángulos las caras de más de 3 lados. | <kbd>Ctrl+T</kbd> |
| Sombreado suave / plano | Cómo se ilumina la superficie. | Menú Cara |
| Marcar / limpiar afilado | Aristas que se ven duras aunque la malla sea suave. | Menú Arista |
| Marcar / limpiar costura | Por dónde se corta la malla al desplegar las UV. | Menú Arista o UV |
| Menú de contexto | Las operaciones del sub-modo actual (vértice, arista o cara) en el puntero. | <kbd>W</kbd> o click derecho |
| Insertar keyframe | Guarda la forma de la malla en el frame actual (animación de vértices). | <kbd>I</kbd> |

## Menú UV

| Función | Descripción | Atajo |
|---|---|---|
| Desplegar | Basado en ángulos, conforme o de mínimo estiramiento: abre la malla por sus costuras. | <kbd>U</kbd> |
| Proyección UV inteligente | Corta y despliega sola según los ángulos entre caras. | <kbd>U</kbd> |
| Empaquetar lightmap / Seguir quads activos | Islas ordenadas sin solaparse / UV ordenadas siguiendo la cara activa. | <kbd>U</kbd> |
| Proyección de cubo, cilindro, esfera, desde la vista | Proyecciones simples. | <kbd>U</kbd> |
| Restablecer | Cada cara ocupa toda la imagen. | <kbd>U</kbd> |

## Edición de curvas (rutas)

Con <kbd>Tab</kbd> sobre una curva se editan sus nodos como si fuera una malla de puntos: <kbd>G</kbd> mueve, <kbd>E</kbd> agrega el nodo siguiente, <kbd>X</kbd> borra.
