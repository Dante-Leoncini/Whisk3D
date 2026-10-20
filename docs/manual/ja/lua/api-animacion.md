# アニメーション

| 関数 | 説明 |
|---|---|
| `animEscena(nombre [, loop])`、`pararEscena()`、`animEscenaFrame(f)` | シーン全体のアニメーション。 |
| `animObjeto(raiz, "clip" [, loop])`、`animObjetoParar`、`animObjetoTermino`、`animObjetoVelocidad` | オブジェクトとその子のアニメーションクリップ。 |
| `animClip(esqueleto, clip [, loop])`、`animTermino`、`animVelocidad`、`animTransicion` | アーマチュアのアニメーション（歩く、ジャンプする…）と、その間のなめらかな切り替え。 |
| `animCapa(esq, n, clip [, peso, modo])`とその関連関数 | 複数のアニメーションをレイヤー（1〜16）で同時にブレンドします。たとえば、走る + 撃つ。 |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | ボーンの位置（手に武器を持たせるときなど）。 |
| `animar(malla, n [, frame])` | メッシュの頂点アニメーションを切り替えます。 |
