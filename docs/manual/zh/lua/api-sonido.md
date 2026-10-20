# 声音

| 函数 | 作用 |
|---|---|
| `beep(freq [, ms, vol])` | 一声蜂鸣（不需要文件）。 |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | 播放一个声音；返回一个标识符。 |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | 停止或调整声音。 |
| `silenciar(bool)`, `estaMudo()` | 全局静音。 |
