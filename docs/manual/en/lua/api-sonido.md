# Sound

| Function | What it does |
|---|---|
| `beep(freq [, ms, vol])` | A beep (no file needed). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Plays a sound; returns a handle. |
| `sonido("sonidos/x.wav", {vol, tono, loop, pan, ataque, decaimiento, sostenido, caida, liberacion, duracion, reverb}) → h` | The same with names, plus the envelope (attack, decay, sustain 0 to 1, `caida`: the sustain drops 60 dB in that many seconds, release, and `duracion`: the note releases itself after that many seconds) and how much of the sound goes to the reverb (0 to 1). |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Stop or adjust sounds. |
| `soltarSonido(h)` | Releases the note: the envelope moves to its release. |
| `reverb(sala, amortiguacion, nivel)` | The global reverb: room size, damping and level (0 to 1 each; level 0 turns it off). |
| `silenciar(bool)`, `estaMudo()` | Mute everything. |
