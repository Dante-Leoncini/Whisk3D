# Suono

| Funzione | Cosa fa |
|---|---|
| `beep(freq [, ms, vol])` | Un bip (senza file). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Riproduce un suono; restituisce un identificatore. |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Interrompere o regolare i suoni. |
| `silenciar(bool)`, `estaMudo()` | Silenzio generale. |
