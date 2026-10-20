# Il progetto (.w3d) e i file

| Funzione | Descrizione | Dove |
|---|---|---|
| Open project | Apre un .w3d (anche con un doppio clic dal sistema). | Properties → File/Render → File |
| Save / Save As | Salva nella cartella e con il nome indicati nel riquadro; Save As ne chiede altri. Se manca il nome, il campo diventa rosso. | Riquadro File, <kbd>Ctrl+S</kbd> |
| Save version | Salva e inoltre lascia una copia numerata (`proyecto_v03.w3d`). | Riquadro File |
| Extract assets | Copia tutto il contenuto interno in una cartella (le copie non cambiano il progetto). | Riquadro File |
| Meshes as text | Salva le mesh come testo leggibile invece che in binario. | Riquadro File |
| Imports | OBJ, FBX, glTF, GLB e interfacce .w3dui. Ciò che viene importato si copia dentro il progetto (senza duplicati). | 3D Viewport → Add → Imports |
| Export | OBJ, glTF o GLB dell'oggetto selezionato (con o senza modificatori e trasformazioni). | Properties → Export |
| Modifiche non salvate | Ciò che è stato modificato e non salvato (script, texture dipinte) è segnato con `*`. Quando chiudi o apri un altro progetto, un avviso elenca ciò che andrebbe perso. | Automatico |
| Risorsa dentro o fuori | Una risorsa esterna non viene copiata: si salva il suo percorso e si avvisa se manca. | Riquadro Resource; "Save inside / outside the .w3d" nell'IDE e nell'UV Editor |

Il salvataggio non lascia mai il file a metà: prima scrive una copia temporanea e poi la rinomina.
