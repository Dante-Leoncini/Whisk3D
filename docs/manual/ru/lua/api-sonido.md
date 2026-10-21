# Звук

| Функция | Что делает |
|---|---|
| `beep(freq [, ms, vol])` | Звуковой сигнал (без файла). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Воспроизводит звук; возвращает идентификатор. |
| `sonido("sonidos/x.wav", {vol, tono, loop, pan, ataque, decaimiento, sostenido, caida, liberacion, duracion, reverb}) → h` | То же самое с именами, плюс огибающая (атака, спад, уровень удержания от 0 до 1, `caida`: удержание падает на 60 дБ за столько секунд, затухание и `duracion`: нота отпускается сама через столько секунд) и доля звука, идущая в реверберацию (от 0 до 1). |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Остановить или настроить звуки. |
| `soltarSonido(h)` | Отпускает ноту: огибающая переходит к затуханию. |
| `reverb(sala, amortiguacion, nivel)` | Общая реверберация: размер зала, демпфирование и уровень (каждый от 0 до 1; уровень 0 выключает). |
| `silenciar(bool)`, `estaMudo()` | Общее отключение звука. |
