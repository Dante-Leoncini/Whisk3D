# Sound

| Function | What it does |
|---|---|
| `beep(freq [, ms, vol])` | A beep (no file needed). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Plays a sound; returns a handle. |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Stop or adjust sounds. |
| `silenciar(bool)`, `estaMudo()` | Mute everything. |
