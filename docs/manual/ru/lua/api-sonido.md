# Звук

| Функция | Что делает |
|---|---|
| `beep(freq [, ms, vol])` | Звуковой сигнал (без файла). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Воспроизводит звук; возвращает идентификатор. |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Остановить или настроить звуки. |
| `silenciar(bool)`, `estaMudo()` | Общее отключение звука. |
