# UV Editor

Montre comment la texture se pose sur le maillage. Pour modifier, le maillage doit être en **Edit Mode dans le 3D Viewport** ; sinon, l'éditeur affiche seulement la texture. Le mode de l'UV Editor lui est propre : il ne change pas le mode du 3D Viewport. Les outils pour déplier et projeter les UV se trouvent dans le 3D Viewport (Edit Mode, touche <kbd>U</kbd>).

## Navigation et barre supérieure

| Fonction | Description | Utilisation |
|---|---|---|
| Zoom / Déplacer la vue | Zoome vers le pointeur / déplace la vue. | Molette / bouton du milieu ou flèches ; tactile : 1 doigt fait défiler, 2 doigts zooment |
| Mode | Object Mode, Edit Mode, Weight Paint, Edit Bones et Pose Mode (ces deux derniers si le maillage a une armature 2D). | Bouton de mode, <kbd>Tab</kbd> |
| Vertex / Edge / Face | Ce que l'on sélectionne en Edit Mode. | Bouton |
| Pivot | 3D Cursor, Individual Origins ou Median Point. | Bouton |
| Cursor | Cursor to Selection, Selection to Cursor, Cursor to Center. | Menu |
| View | Sync Selection (la sélection UV est la même que celle du maillage), Repeat Texture (mosaïque), Show Chrome UV, Frame Selected, Frame All. | Menu ; <kbd>Num.</kbd> |
| Texture | La texture affichée : New Texture…, Auto (active part), ou n'importe quelle texture du projet. | Menu |
| New Texture | Crée une image (nom, taille, couleur, transparence ; Blank, UV Grid ou Color Grid), l'enregistre dans le projet et l'assigne au matériau. | Texture → New Texture… |
| Mipmap | Affiche un niveau de mipmap précis, pour le vérifier. | Bouton Mipmap |
| Edit | Entre dans la peinture de texture sur l'image et en sort. | Bouton Edit |
| Save (disquette, toujours visible) | Save, Save As…, Save outside the .w3d…, Save inside the .w3d, Export UV Layout… | Menu |
| Export UV Layout | Enregistre un PNG à fond transparent : faces semi-transparentes (plus opaques là où elles se superposent) et lignes opaques. On choisit le nom, le dossier et la résolution (512 par défaut, 256 sur le N95, ou la taille de la texture affichée). | Save → Export UV Layout… |
| Animation | Insérer, supprimer ou effacer des keyframes de la couche UV, ou de la pose 2D. | Menu |

## Object Mode (UV)

Un clic choisit ce que l'on modifie : une armature 2D (si l'on touche un os) ou la géométrie. <kbd>Tab</kbd> entre en édition de l'élément choisi.

## Edit Mode (UV)

| Fonction | Description | Raccourci |
|---|---|---|
| Select | Sommets, arêtes ou faces UV. Sans synchronisation, le 3D Viewport filtre : seules les faces sélectionnées en 3D sont visibles. | Clic ; <kbd>Shift</kbd>+clic |
| All / None / Invert | Sur ce qui est visible. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | L'îlot UV sous le pointeur (<kbd>Shift</kbd> ajoute). | <kbd>L</kbd> |
| Box Select | Rectangle ; <kbd>Shift</kbd> ajoute. | <kbd>B</kbd> |
| Move / Rotate / Scale | Transforme les UV. <kbd>X</kbd> / <kbd>Y</kbd> verrouillent un axe ; on peut taper la valeur (1.0 = une tuile). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Placer le curseur 2D | Place le curseur à l'endroit cliqué. | Clic droit |
| Insert Keyframe | Enregistre la couche UV dans l'animation de sommets active. | <kbd>I</kbd> |

## Weight Paint (UV)

Peint les poids des os 2D sur la carte UV, avec les mêmes contrôles que dans le 3D Viewport (mode +/−/=, groupe, repères, falloff, sélection uniquement). <kbd>Ctrl</kbd>+clic sur un os le choisit pour la peinture.

## Edit Bones et Pose Mode (armature 2D)

| Fonction | Description | Raccourci |
|---|---|---|
| Add Armature 2D / Bone | Crée l'armature 2D du maillage (avec son groupe UV) ou ajoute un os. | Menu Add |
| Select | Une extrémité ou l'os entier ; le faire glisser le déplace. | Clic ; <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | Dans Edit Bones, change la position de repos ; en Pose, pose l'os (les UV pondérées suivent l'os). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | Uniquement dans Edit Bones. | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | Keep Offset ou Connected / déconnecter. | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | En Pose : menu des canaux, ou tout avec <kbd>Shift+I</kbd>. | <kbd>I</kbd> |

## Texture Paint (UV)

Avec le bouton **Edit**, on peint directement sur l'image, avec couleur, falloff, rayon et force. On enregistre depuis la disquette.
