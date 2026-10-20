# キーボード、ゲームパッド、タッチ、マウス

| 関数 | 説明 |
|---|---|
| `tecla(nombre) → bool` | キーが押されている（押している間ずっと）。 |
| `teclaApretada(nombre) → bool` | ちょうどこのフレームで押された（1回の押下につき1回だけ）。 |
| `boton(nombre)`、`botonApretado(nombre)` | ゲームパッドのボタンで同じことをします。 |
| `stick(["izq"\|"der"]) → x, y` | ゲームパッドのスティック。-1〜1（上が-1）。 |
| `gatillo(["izq"\|"der"]) → 0..1` | アナログトリガー。 |
| `controles() → n`、`control([n]) → nombre, tipo` | 接続されているゲームパッドの数と種類（`"xbox"`、`"playstation"`、`"nintendo"`、`"generico"`）。 |
| `toque() → x, y, tocando` | 画面上の指（またはマウスのクリック）。 |
| `dedo([n]) → x, y, activo` | マルチタッチ：n番目の指（1〜4）。 |
| `apretado(obj) → bool` | その2D要素が、このフレームでタップまたはクリックされた（ボタン）。 |
| `raton() → x, y, dentro` | マウスの位置。 |
| `capturarRaton(bool)`、`ratonRel() → dx, dy`、`ratonCapturado()` | マウスで視点を動かすためのマウスキャプチャー（一人称のゲーム、PCのみ）。 |
