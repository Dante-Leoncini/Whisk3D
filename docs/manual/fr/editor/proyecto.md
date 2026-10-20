# Le projet (.w3d) et les fichiers

| Fonction | Description | Où |
|---|---|---|
| Open project | Ouvre un .w3d (aussi par double clic depuis le système). | Properties → File/Render → File |
| Save / Save As | Enregistre dans le dossier et sous le nom indiqués dans la carte ; Save As en demande un autre. Si le nom manque, le champ devient rouge. | Carte File, <kbd>Ctrl+S</kbd> |
| Save version | Enregistre et laisse en plus une copie numérotée (`proyecto_v03.w3d`). | Carte File |
| Extract assets | Copie tout le contenu interne dans un dossier (les copies ne modifient pas le projet). | Carte File |
| Meshes as text | Enregistre les maillages sous forme de texte lisible au lieu de binaire. | Carte File |
| Imports | OBJ, FBX, glTF, GLB et interfaces .w3dui. Ce qui est importé est copié dans le projet (sans doublons). | 3D Viewport → Add → Imports |
| Export | OBJ, glTF ou GLB de l'objet sélectionné (avec ou sans modificateurs et transformations). | Properties → Export |
| Modifications non enregistrées | Ce qui a été modifié et pas encore enregistré (scripts, textures peintes) est marqué d'un `*`. Lorsque vous fermez ou ouvrez un autre projet, un avertissement liste ce qui serait perdu. | Automatique |
| Ressource interne ou externe | Une ressource externe n'est pas copiée : son chemin est enregistré et un avertissement s'affiche si elle manque. | Carte Resource ; « Save inside / outside the .w3d » dans l'IDE et l'UV Editor |

L'enregistrement ne laisse jamais le fichier à moitié écrit : il écrit d'abord une copie temporaire, puis la renomme.
