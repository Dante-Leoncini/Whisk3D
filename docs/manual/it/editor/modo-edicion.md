# Edit Mode (mesh)

Si entra con <kbd>Tab</kbd> su una mesh. Si lavora su **vertici**, **spigoli** o **facce** a seconda del pulsante della barra superiore.

## Selezionare

| Funzione | Descrizione | Scorciatoia |
|---|---|---|
| Select | Sceglie un vertice, uno spigolo o una faccia. | Clic; <kbd>Shift</kbd>+clic alterna |
| Select Linked | Tutta l'isola connessa sotto il puntatore. | <kbd>L</kbd> |
| Loop Select | Un anello di spigoli o di facce. | <kbd>Shift+Alt</kbd>+clic |
| Pick Shortest Path | Seleziona il percorso tra l'elemento attivo e quello cliccato. | <kbd>Ctrl</kbd>+clic |
| Shortest Path (Fill Region) | Seleziona tutta la regione tra i due. | <kbd>Ctrl+Shift</kbd>+clic |
| All / None / Invert / Box Select | Come in Object Mode, sugli elementi della mesh. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## Modellare

| Funzione | Descrizione | Scorciatoia |
|---|---|---|
| Move / Rotate / Scale | Trasforma ciò che è selezionato. Con uno spostamento in corso, premendo di nuovo <kbd>G</kbd> si passa a far scorrere. | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Shrink/Fatten | Sposta ogni vertice lungo la sua normale (gonfia o sgonfia). | <kbd>Alt+S</kbd> |
| Extrude | Crea nuova geometria a partire da ciò che è selezionato (le facce escono lungo la loro normale). | <kbd>E</kbd> |
| Loop Cut and Slide | Taglia un anello di spigoli. La rotella cambia il numero di tagli; il clic applica e poi si fa scorrere. | <kbd>Ctrl+R</kbd> |
| New Edge/Face from Vertices | Unisce i vertici selezionati con uno spigolo o una faccia. | <kbd>F</kbd> |
| Connect Vertex Path | Taglia in linea retta tra due vertici. | <kbd>J</kbd> |
| Vertex Slide | Fa scorrere i vertici lungo i loro spigoli. | <kbd>Shift+V</kbd> |
| Rip | Separa la mesh lungo la selezione. | <kbd>V</kbd> |
| Duplicate | Copia ciò che è selezionato e lo lascia agganciato al puntatore. | <kbd>Shift+D</kbd> |
| Separate | Sposta le facce selezionate in un nuovo oggetto. | <kbd>P</kbd> |
| Merge | Salda i vertici: At Center, At Cursor, Collapse o By Distance. | <kbd>M</kbd> |
| Auto Merge | Al termine dello spostamento, salda i vertici rimasti più vicini della soglia. | Menu Mesh |
| Delete | Vertici, spigoli, facce o loop di spigoli. | <kbd>X</kbd> o <kbd>Delete</kbd> |
| Recalculate Normals / Flip | Corregge la direzione verso cui guardano le facce, o le capovolge. | <kbd>Shift+N</kbd> |
| Triangulate Faces | Divide in triangoli le facce con più di 3 lati. | <kbd>Ctrl+T</kbd> |
| Shade Smooth / Flat | Come viene illuminata la superficie. | Menu Face |
| Mark / Clear Sharp | Spigoli che appaiono netti anche se la mesh è smussata. | Menu Edge |
| Mark / Clear Seam | Dove si taglia la mesh quando si fa l'unwrap delle UV. | Menu Edge o UV |
| Context menu | Le operazioni della sotto-modalità attuale (vertice, spigolo o faccia) sul puntatore. | <kbd>W</kbd> o clic destro |
| Insert Keyframe | Salva la forma della mesh nel frame attuale (animazione dei vertici). | <kbd>I</kbd> |

## Menu UV

| Funzione | Descrizione | Scorciatoia |
|---|---|---|
| Unwrap | Angle Based, Conformal o Minimum Stretch: apre la mesh lungo le sue cuciture. | <kbd>U</kbd> |
| Smart UV Project | Taglia e fa l'unwrap da sola in base agli angoli tra le facce. | <kbd>U</kbd> |
| Lightmap Pack / Follow Active Quads | Isole ordinate senza sovrapporsi / UV ordinate seguendo la faccia attiva. | <kbd>U</kbd> |
| Cube, Cylinder, Sphere Projection, Project from View | Proiezioni semplici. | <kbd>U</kbd> |
| Reset | Ogni faccia occupa tutta l'immagine. | <kbd>U</kbd> |

## Modifica delle curve (path)

Con <kbd>Tab</kbd> su una curva se ne modificano i nodi come se fosse una mesh di punti: <kbd>G</kbd> sposta, <kbd>E</kbd> aggiunge il nodo successivo, <kbd>X</kbd> elimina.
