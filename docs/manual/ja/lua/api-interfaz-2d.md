# 2Dインターフェースと画面

| 関数 | 説明 |
|---|---|
| `pantalla() → ancho, alto` | キャンバスのサイズ。 |
| `areaSegura() → x, y, w, h` | ノッチを除いた画面の部分（`inicio`では使わないでください）。 |
| `escala() → f` | 引数なしの場合：サイズを画面に合わせるための係数（短い辺 / 480）。 |
| `posPx(obj) → x, y`、`setPosPx(obj, x, y)` | 2D要素の位置（`nil`を渡した軸は変わりません）。 |
| `tamPx(obj) → w, h`、`setTamPx(obj, w, h)` | 2D要素のサイズ。 |
| `cajaUI(obj) → x, y, w, h` | 実際に占めている矩形（x, y = 中心）。 |
| `setTexto(obj, valor)`、`setTam(texto, px)` | テキストまたはボタンの文字列と、文字のサイズを変えます。 |
| `setTextura(img, "ruta.png")`、`setUVRect`、`setFlipbook` | 画像を変える、一部を切り抜く、またはコマのシートでアニメーションします。 |
| `setOpacidad(obj, 0..1)`、`fundir(obj, objetivo, paso)` | 透明度とフェード。 |
| `setRot2D(obj, grados)` | 2D要素を回転します。 |
| `chocan(a, b) → bool` | 2つの2D要素が画面上で重なっているかどうか。 |
| `limitar(obj, area [, eje])`、`dentro(area, x [, y])` | 要素を別の要素の内側に収める、または点が内側にあるかを調べます。 |
| `salir()` | ゲームを終了します（エディターでは何もしません）。 |
