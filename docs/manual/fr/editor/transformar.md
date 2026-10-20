# Déplacer, faire pivoter et mettre à l'échelle

Fonctionne de la même façon en Object Mode, en Edit Mode, en Pose et dans l'édition des os.

| Fonction | Description | Raccourci |
|---|---|---|
| Move (Translate) | La sélection suit le pointeur. | <kbd>G</kbd> |
| Rotate | Tourne autour du pivot. Un nouvel appui sur <kbd>R</kbd> alterne entre rotation libre (trackball) et orbitale. | <kbd>R</kbd> |
| Scale | Agrandit ou réduit depuis le pivot. | <kbd>S</kbd> |
| Contraindre à un axe | Pendant la transformation. Appuyer à nouveau fait passer de Global → Local → View → libre. | <kbd>X</kbd> / <kbd>Y</kbd> / <kbd>Z</kbd> |
| Contraindre à un plan | Exclut cet axe (déplace sur les deux autres). | <kbd>Shift+X</kbd> / <kbd>Shift+Y</kbd> / <kbd>Shift+Z</kbd> |
| Valeur exacte | Tapez un nombre ou un calcul (`2*3`, `(1+0.5)/2`). <kbd>-</kbd> inverse le signe, <kbd>Backspace</kbd> efface. | Chiffres |
| Confirm | Valide l'opération. | Clic gauche, <kbd>Enter</kbd>, coche verte |
| Cancel | Tout revient comme avant. | <kbd>Esc</kbd>, clic droit, croix rouge |
| Pas fins | Déplace, fait pivoter ou met à l'échelle petit à petit. | Flèches |

Pendant l'opération, la barre supérieure affiche ce qui est en cours, par exemple « Move X 1.5 along global X ». En tactile, toucher cette barre ouvre un pavé numérique.

## Le gizmo

Le gizmo apparaît sur le pivot en Object Mode et en Edit Mode (il s'active et se désactive dans Overlays → Gizmo).

| Fonction | Description |
|---|---|
| Gizmo de déplacement | Flèches = un axe ; carrés = un plan ; cercle central = libre. |
| Gizmo de rotation | Un demi-cercle de couleur par axe, un anneau blanc pour tourner face à la vue, et l'intérieur pour tourner librement. |
| Gizmo de mise à l'échelle | Des pointes carrées par axe ; le cercle central met à l'échelle uniformément. |
| Changer de gizmo | Un clic (ou un toucher) rapide sur le gizmo, sans glisser, passe de Move à Rotate, puis à Scale, et revient à Move. |

## Ajuster la dernière opération

Après un déplacement, une rotation ou une mise à l'échelle (en Object Mode ou en Edit Mode), un panneau apparaît en bas à gauche avec ce qui a été fait : les valeurs X, Y, Z (ou l'angle), l'orientation et l'édition proportionnelle avec ses options. Modifier une valeur refait l'opération avec la nouvelle valeur. **Cancel** l'annule et **Accept** la conserve. Un clic hors du panneau valide aussi. Tant que le panneau est ouvert, la barre inférieure du 3D Viewport est masquée.

Le panneau a une bordure verte, car c'est la fenêtre qui a le focus. S'il ne tient pas dans la moitié de la hauteur de l'écran, il est réduit à cette moitié et défile en faisant glisser le doigt (sans toucher les options), avec la molette ou avec les flèches. Au clavier ou sur le téléphone : les flèches parcourent les lignes, <kbd>OK</kbd> / <kbd>Enter</kbd> modifie la valeur sans fermer le panneau, **Accept**, <kbd>Esc</kbd> ou <kbd>Delete</kbd> (la touche <kbd>C</kbd> sur le N95) le ferment en conservant la modification, et seul **Cancel** l'annule.

## Barre inférieure

Elle contient Undo et Redo, les dernières actions utilisées et le bouton d'édition proportionnelle. Pendant une transformation, elle affiche la coche (valider), la croix (annuler), l'orientation et les axes X / Y / Z (deux axes activés = un plan). En tactile, après une extrusion, **Repeat** apparaît : il valide et extrude à nouveau.
