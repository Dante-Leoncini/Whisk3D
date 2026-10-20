# Som

| Função | O que faz |
|---|---|
| `beep(freq [, ms, vol])` | Um bipe (sem arquivo). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Reproduz um som; devolve um identificador. |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Interromper ou ajustar sons. |
| `silenciar(bool)`, `estaMudo()` | Silêncio geral. |
