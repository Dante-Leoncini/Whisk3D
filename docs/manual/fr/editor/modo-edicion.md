# Edit Mode (maillages)

On y entre avec <kbd>Tab</kbd> sur un maillage. On travaille sur les **sommets**, les **arêtes** ou les **faces** selon le bouton de la barre supérieure.

## Sélectionner

| Fonction | Description | Raccourci |
|---|---|---|
| Select | Choisit un sommet, une arête ou une face. | Clic ; <kbd>Shift</kbd>+clic alterne |
| Select Linked | Tout l'îlot connecté sous le pointeur. | <kbd>L</kbd> |
| Loop Select | Un anneau d'arêtes ou de faces. | <kbd>Shift+Alt</kbd>+clic |
| Pick Shortest Path | Sélectionne le chemin entre l'élément actif et l'élément cliqué. | <kbd>Ctrl</kbd>+clic |
| Shortest Path (Fill Region) | Sélectionne toute la région entre les deux. | <kbd>Ctrl+Shift</kbd>+clic |
| All / None / Invert / Box Select | Comme en Object Mode, sur les éléments du maillage. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## Modéliser

| Fonction | Description | Raccourci |
|---|---|---|
| Move / Rotate / Scale | Transforme la sélection. Pendant un déplacement, un nouvel appui sur <kbd>G</kbd> passe en glissement. | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Shrink/Fatten | Déplace chaque sommet le long de sa normale (gonfle ou dégonfle). | <kbd>Alt+S</kbd> |
| Extrude | Crée de la nouvelle géométrie à partir de la sélection (les faces sortent selon leur normale). | <kbd>E</kbd> |
| Loop Cut and Slide | Coupe un anneau d'arêtes. La molette change le nombre de coupes ; un clic applique, puis on fait glisser. | <kbd>Ctrl+R</kbd> |
| New Edge/Face from Vertices | Relie les sommets sélectionnés par une arête ou une face. | <kbd>F</kbd> |
| Connect Vertex Path | Coupe en ligne droite entre deux sommets. | <kbd>J</kbd> |
| Vertex Slide | Fait glisser les sommets le long de leurs arêtes. | <kbd>Shift+V</kbd> |
| Rip | Sépare le maillage le long de la sélection. | <kbd>V</kbd> |
| Duplicate | Copie la sélection et la laisse saisie. | <kbd>Shift+D</kbd> |
| Separate | Déplace les faces sélectionnées dans un nouvel objet. | <kbd>P</kbd> |
| Merge | Soude des sommets : At Center, At Cursor, Collapse ou By Distance. | <kbd>M</kbd> |
| Auto Merge | À la fin d'un déplacement, soude les sommets restés plus proches que le seuil. | Menu Mesh |
| Delete | Sommets, arêtes, faces ou boucles d'arêtes. | <kbd>X</kbd> ou <kbd>Delete</kbd> |
| Recalculate Normals / Flip | Corrige l'orientation des faces, ou les retourne. | <kbd>Shift+N</kbd> |
| Triangulate Faces | Découpe en triangles les faces de plus de 3 côtés. | <kbd>Ctrl+T</kbd> |
| Shade Smooth / Shade Flat | La façon dont la surface est éclairée. | Menu Face |
| Mark / Clear Sharp | Arêtes qui paraissent dures même si le maillage est lisse. | Menu Edge |
| Mark / Clear Seam | Endroits où le maillage est coupé lors du dépliage des UV. | Menu Edge ou UV |
| Context menu | Les opérations du sous-mode actuel (sommet, arête ou face), sous le pointeur. | <kbd>W</kbd> ou clic droit |
| Insert Keyframe | Enregistre la forme du maillage à la frame actuelle (animation de sommets). | <kbd>I</kbd> |

## Menu UV

| Fonction | Description | Raccourci |
|---|---|---|
| Unwrap | Angle Based, Conformal ou Minimum Stretch : ouvre le maillage le long de ses coutures. | <kbd>U</kbd> |
| Smart UV Project | Coupe et déplie automatiquement selon les angles entre les faces. | <kbd>U</kbd> |
| Lightmap Pack / Follow Active Quads | Îlots rangés sans chevauchement / UV ordonnées en suivant la face active. | <kbd>U</kbd> |
| Cube, Cylinder, Sphere Projection, Project from View | Projections simples. | <kbd>U</kbd> |
| Reset | Chaque face occupe toute l'image. | <kbd>U</kbd> |

## Édition des courbes (chemins)

Avec <kbd>Tab</kbd> sur une courbe, on modifie ses nœuds comme s'il s'agissait d'un maillage de points : <kbd>G</kbd> déplace, <kbd>E</kbd> ajoute le nœud suivant, <kbd>X</kbd> supprime.
