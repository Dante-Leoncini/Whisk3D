# ライトとカメラ

| 関数 | 説明 |
|---|---|
| `color(luz) → r, g, b`、`setColor(luz, r, g, b)` | ライトの色。 |
| `energia(luz) → e`、`setEnergia(luz, e)` | 明るさ。0〜1（ちらつかせたり、少しずつ消したりするため）。 |
| `setCamaraActiva(cam)` | ゲームを映すカメラを切り替えます。 |
| `lenteDe(cam) → fov, cerca, lejos`、`setLente(cam [, fov, cerca, lejos])` | 視野角とクリッピング距離。 |
| `camaraXZ() → fx, fz, rx, rz` | カメラが床の上でどちらを向いているか（カメラに合わせてキャラクターを動かすため）。 |
| `pantallaDe(obj) → x, y, delante` | 3Dオブジェクトが画面上のどこに表示されるか（その上に2Dのラベルを置くため）。 |
| `setRiel(cam, curva [, offset])`、`setRielNodo`、`setMiradaRiel`、`rielDe` | カメラをカーブ（レール）に沿って動かします。 |
| `resolucion() → ancho, alto` | 3D画像の実際のピクセルサイズ。 |
