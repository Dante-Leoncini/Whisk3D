# Sonido

| Función | Qué hace |
|---|---|
| `beep(freq [, ms, vol])` | Un pitido (sin archivo). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Reproduce un sonido; devuelve un identificador. |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Cortar o ajustar sonidos. |
| `silenciar(bool)`, `estaMudo()` | Silencio general. |
