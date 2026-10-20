# 時間、乱数、ユーティリティ

| 関数 | 説明 |
|---|---|
| `azar() → 0..1`、`azar(min, max) → entero` | 乱数。 |
| `relojMs() → ms` | ミリ秒。処理にかかる時間を測るのに使います。 |
| `perfilLua(cuadros [, etiqueta])` | スクリプトのどの部分が遅いかを計測します（`perfilLua(0)`で停止します）。 |
| `lineaCrear(nombre, puntos)`、`lineaPunto(id, s)` | エンジンが計算する、なめらかな閉じたカーブ（移動ルート）。 |

「開始からの経過時間」を返す関数はありません。変数に`dt`を足していってください。
