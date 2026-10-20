# UV Editor

Mostra come la texture si appoggia sulla mesh. Per modificare, la mesh deve essere in **Edit Mode nel 3D Viewport**; altrimenti l'editor mostra solo la texture. La modalità dell'UV Editor è indipendente: non cambia la modalità del 3D Viewport. Gli strumenti per fare l'unwrap e proiettare le UV si trovano nel 3D Viewport (Edit Mode, tasto <kbd>U</kbd>).

## Navigazione e barra superiore

| Funzione | Descrizione | Come si usa |
|---|---|---|
| Zoom / Spostare la vista | Avvicina verso il puntatore / sposta la vista. | Rotella / tasto centrale o frecce; touch: 1 dito sposta la vista, 2 dita zoom |
| Mode | Object Mode, Edit Mode, Weight Paint, Edit Bones e Pose Mode (questi ultimi due se la mesh ha un'armatura 2D). | Pulsante della modalità, <kbd>Tab</kbd> |
| Vertex / Edge / Face | Cosa si seleziona in Edit Mode. | Pulsante |
| Pivot | Cursor, Individual Origins o Median Point. | Pulsante |
| Cursor | Cursor to Selection, Selection to Cursor, Cursor to Center. | Menu |
| View | Sync Selection (la selezione UV è la stessa della mesh), Repeat Texture (mosaico), Show Chrome UV, Frame Selected, Frame All. | Menu; <kbd>Num.</kbd> |
| Texture | Quale texture si mostra: New Texture…, Auto (quella della parte attiva), o una qualsiasi del progetto. | Menu |
| New Texture | Crea un'immagine (nome, dimensione, colore, trasparenza; tinta unita, griglia UV o griglia di colori), la salva nel progetto e la assegna al materiale. | Texture → New Texture… |
| Mipmap | Mostra un livello di mipmap in particolare, per controllarlo. | Pulsante Mip |
| Edit | Entra ed esce dalla pittura di texture sull'immagine. | Pulsante Edit |
| Save (dischetto, sempre visibile) | Save, Save As…, Save outside the .w3d…, Save inside the .w3d, Export UV Layout… | Menu |
| Export UV Layout | Salva un PNG con sfondo trasparente: facce semitrasparenti (più opache dove si sovrappongono) e linee opache. Si scelgono nome, cartella e risoluzione (predefinita 512, 256 sull'N95, o la dimensione della texture mostrata). | Save → Export UV Layout… |
| Animation | Inserire, eliminare o ripulire keyframe del livello UV, o della posa 2D. | Menu |

## Object Mode (UV)

Il clic sceglie cosa si modifica: un'armatura 2D (se si tocca un osso) o la geometria. <kbd>Tab</kbd> entra a modificare l'elemento scelto.

## Edit Mode (UV)

| Funzione | Descrizione | Scorciatoia |
|---|---|---|
| Select | Vertici, spigoli o facce UV. Senza sincronizzazione, il 3D Viewport filtra: si vedono solo le facce selezionate in 3D. | Clic; <kbd>Shift</kbd>+clic |
| All / None / Invert | Su ciò che è visibile. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | L'isola UV sotto il puntatore (<kbd>Shift</kbd> aggiunge). | <kbd>L</kbd> |
| Box Select | Rettangolo; <kbd>Shift</kbd> aggiunge. | <kbd>B</kbd> |
| Move / Rotate / Scale | Trasforma le UV. <kbd>X</kbd> / <kbd>Y</kbd> bloccano un asse; si può digitare il valore (1.0 = una piastrella). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Posizionare il cursore 2D | Mette il cursore dove si clicca. | Clic destro |
| Insert Keyframe | Salva il livello UV nell'animazione dei vertici attiva. | <kbd>I</kbd> |

## Weight Paint (UV)

Dipinge i pesi delle ossa 2D sulla mappa UV, con gli stessi controlli del 3D Viewport (modalità +/−/=, gruppo, marcatori, falloff, solo la selezione). <kbd>Ctrl</kbd>+clic su un osso lo sceglie per dipingere.

## Edit Bones e Pose Mode (armatura 2D)

| Funzione | Descrizione | Scorciatoia |
|---|---|---|
| Add Armature 2D / Bone | Crea l'armatura 2D della mesh (con il suo gruppo UV) o aggiunge un osso. | Menu Add |
| Select | Un'estremità o l'osso intero; trascinando lo si sposta. | Clic; <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | In Edit Bones cambia la posizione di riposo; in Pose, mette in posa (le UV pesate seguono l'osso). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | Solo in Edit Bones. | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | Keep Offset o Connected / Disconnect. | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | In Pose: menu dei canali, o tutto con <kbd>Shift+I</kbd>. | <kbd>I</kbd> |

## Texture Paint (UV)

Con il pulsante **Edit** si dipinge direttamente sull'immagine, con colore, falloff, raggio e forza. Si salva dal dischetto.
