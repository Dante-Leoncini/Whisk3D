# Tempo, casualità e utilità

| Funzione | Cosa fa |
|---|---|
| `azar() → 0..1`, `azar(min, max) → entero` | Numeri casuali. |
| `relojMs() → ms` | Millisecondi, per misurare quanto tempo richiede qualcosa. |
| `perfilLua(cuadros [, etiqueta])` | Misura quali parti dello script sono lente (`perfilLua(0)` lo spegne). |
| `lineaCrear(nombre, puntos)`, `lineaPunto(id, s)` | Una curva morbida chiusa calcolata dal motore (percorsi). |

Non esiste una funzione "tempo trascorso dall'inizio": somma `dt` in una variabile.
