# Lo script e la comunicazione

| Funzione | Cosa fa |
|---|---|
| `yo() → obj` | L'oggetto proprietario di questo script. |
| `objeto(prop) → obj \| nil` | L'oggetto scelto nel campo `prop` di `propiedades`. |
| `opcion(prop) → texto` | L'opzione scelta in un menu a tendina di `propiedades`. |
| `propiedad(prop) → valor` | Il numero, sì/no o testo proprio di questo oggetto (o quello predefinito dichiarato). |
| `parametro(prop [, def]) → número` | Come `propiedad` ma sempre un numero; se non esiste restituisce `def` (o 0). |
| `objetivo() → obj \| nil` | L'obiettivo ("target") dell'oggetto proprietario. |
| `compartido(clave) → valor` | Legge lo spazio condiviso da tutti gli script. |
| `setCompartido(clave, valor)` | Scrive un numero, sì/no o testo nello spazio condiviso; `nil` lo cancella. |
