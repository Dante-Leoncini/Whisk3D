# Son

| Fonction | Ce qu'elle fait |
|---|---|
| `beep(freq [, ms, vol])` | Un bip (sans fichier). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Joue un son ; renvoie un identifiant. |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Arrêter ou ajuster des sons. |
| `silenciar(bool)`, `estaMudo()` | Silence général. |
