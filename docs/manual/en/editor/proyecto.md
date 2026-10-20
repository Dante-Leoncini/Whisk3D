# The project (.w3d) and files

| Function | Description | Where |
|---|---|---|
| Open project | Opens a .w3d (also with a double click from the system). | Properties → File/Render → File |
| Save / Save As | Saves in the folder and with the name shown in the card; Save As asks for another one. If the name is missing, the field turns red. | File card, <kbd>Ctrl+S</kbd> |
| Save version | Saves and also leaves a numbered copy (`proyecto_v03.w3d`). | File card |
| Extract assets | Copies everything inside to a folder (the copies don't change the project). | File card |
| Meshes as text | Saves the meshes as readable text instead of binary. | File card |
| Import | OBJ, FBX, glTF, GLB and .w3dui interfaces. What you import is copied into the project (without duplicates). | 3D Viewport → Add → Imports |
| Export | OBJ, glTF or GLB of the selected object (with or without modifiers and transformations). | Properties → Export |
| Unsaved changes | Whatever was edited and not saved (scripts, painted textures) is marked with `*`. When closing or opening another project, a warning lists what would be lost. | Automatic |
| Resource inside or outside | An external resource isn't copied: its path is saved and you get a warning if it's missing. | Resource card; "Save inside / outside the .w3d" in the IDE and the UV Editor |

Saving never leaves the file half-written: it first writes a temporary copy and then renames it.
