# サウンド

| 関数 | 説明 |
|---|---|
| `beep(freq [, ms, vol])` | ビープ音（ファイルは不要です）。 |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | サウンドを再生し、識別子を返します。 |
| `pararSonido(h [, fundido])`、`pararSonidos()`、`ajustarSonido(h, vol [, tono])` | サウンドの停止や調整。 |
| `silenciar(bool)`、`estaMudo()` | 全体のミュート。 |
