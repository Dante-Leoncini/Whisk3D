# UV Editor

Shows how the texture sits on the mesh. To edit, the mesh has to be in **Edit Mode in the 3D Viewport**; otherwise, the editor only shows the texture. The UV Editor has its own mode: it doesn't change the 3D Viewport's mode. The tools for unwrapping and projecting UVs are in the 3D Viewport (Edit Mode, <kbd>U</kbd> key).

## Navigation and top bar

| Function | Description | How to use it |
|---|---|---|
| Zoom / Pan | Zooms toward the pointer / moves the view. | Wheel / middle button or arrows; touch: 1 finger pans, 2 fingers zoom |
| Mode | Object Mode, Edit Mode, Weight Paint, Edit Bones and Pose Mode (these last two if the mesh has a 2D armature). | Mode button, <kbd>Tab</kbd> |
| Vertex / Edge / Face | What gets selected in Edit Mode. | Button |
| Pivot | Cursor, Individual Origins or Median Point. | Button |
| Cursor | Cursor to Selection, Selection to Cursor, Cursor to Center. | Menu |
| View | Sync Selection (the UV selection is the same as the mesh's), Repeat Texture (tiling), Show Chrome UV, Frame Selected, Frame All. | Menu; <kbd>Num.</kbd> |
| Texture | Which texture is shown: New Texture..., Auto (the active part's), or any texture in the project. | Menu |
| New Texture | Creates an image (name, size, color, transparency; blank, UV grid or color grid), saves it in the project and assigns it to the material. | Texture → New Texture... |
| Mipmap | Shows one specific mipmap level, to check it. | Mip button |
| Edit | Enters and leaves texture painting on the image. | Edit button |
| Save (floppy disk, always visible) | Save, Save As..., Save outside the .w3d..., Save inside the .w3d, Export UV Layout... | Menu |
| Export UV Layout | Saves a PNG with a transparent background: semi-transparent faces (more opaque where they overlap) and opaque lines. You choose the name, folder and resolution (512 by default, 256 on the N95, or the size of the displayed texture). | Save → Export UV Layout... |
| Animation | Insert, delete or clear keyframes of the UV layer, or of the 2D pose. | Menu |

## Object Mode (UV)

A click chooses what gets edited: a 2D armature (if you touch a bone) or the geometry. <kbd>Tab</kbd> starts editing the chosen one.

## Edit Mode (UV)

| Function | Description | Shortcut |
|---|---|---|
| Select | UV vertices, edges or faces. Without syncing, the 3D Viewport filters: only the faces selected in 3D are shown. | Click; <kbd>Shift</kbd>+click |
| All / None / Invert | On what's visible. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | The UV island under the pointer (<kbd>Shift</kbd> adds). | <kbd>L</kbd> |
| Box Select | Rectangle; <kbd>Shift</kbd> adds. | <kbd>B</kbd> |
| Move / Rotate / Scale | Transforms the UVs. <kbd>X</kbd> / <kbd>Y</kbd> lock an axis; you can type the value (1.0 = one tile). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Place the 2D cursor | Puts the cursor where you click. | Right click |
| Insert Keyframe | Stores the UV layer in the active vertex animation. | <kbd>I</kbd> |

## Weight Paint (UV)

Paints the weights of the 2D bones on the UV map, with the same controls as in the 3D Viewport (+/−/= mode, group, markers, falloff, selected only). <kbd>Ctrl</kbd>+click on a bone picks it for painting.

## Edit Bones and Pose Mode (2D armature)

| Function | Description | Shortcut |
|---|---|---|
| Add Armature 2D / Bone | Creates the mesh's 2D armature (with its UV group) or adds a bone. | Add menu |
| Select | A tip or the whole bone; dragging moves it. | Click; <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | In Edit Bones it changes the rest position; in Pose, it poses (the weighted UVs follow the bone). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | Edit Bones only. | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | Keep Offset or Connected / disconnect. | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | In Pose: channel menu, or everything with <kbd>Shift+I</kbd>. | <kbd>I</kbd> |

## Texture Paint (UV)

With the **Edit** button you paint directly on the image, with color, falloff, radius and strength. You save it from the floppy disk.
