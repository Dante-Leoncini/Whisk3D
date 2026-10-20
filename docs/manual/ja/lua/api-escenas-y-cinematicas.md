# シーンとカットシーン

| 関数 | 説明 |
|---|---|
| `cambiarEscena(nombre [, reiniciar])` | フレームの終わりに、別のシーン（メニュー、レベル2…）に移ります。 |
| `reproducirEscena(nombre [, "funcion"])` | ゲームを一時停止して、3Dシーンをカットシーンとして再生します。終わるとその関数を呼び出します。 |
| `pararEscena3D()`、`escenaReproduciendo()` | カットシーンを中断します / 再生中のカットシーンを返します。 |
| `dibujar3D([on])` | 3D全体の描画をオフ・オンにします（たとえば、不透明なメニューの裏側）。 |
