# 剛体、衝突、ヒットボックス

| 関数 | 説明 |
|---|---|
| `fisicaVel`、`fisicaVelAng`、`fisicaImpulso`、`fisicaFuerza` | 剛体の速度、回転、押し出し（インパルス）、力。 |
| `fisicaGravedad([g])`、`fisicaActiva(obj, bool)`、`fisicaDespierto(obj)` | 重力（初期値は9.81）、オブジェクトの物理のオン・オフ。 |
| `fisicaRayo(ox, oy, oz, dx, dy, dz, max) → dist, nx, ny, nz, obj` | レイを飛ばし、何に当たるかを返します。 |
| `contactos() → lista` | このフレームのすべての衝突。 |
| `colSuelo(malla, x, y, z)`、`colPared(...)`、`colRayo(...)` | メッシュの三角形との衝突（地面の上に立つ、壁を通り抜けない）。 |
| `hitboxActivo`、`setHitboxActivo`、`setHitboxTam`、`hitboxDentro`、`hitboxTocando` | ヒットボックスを操作し、中に何があるかを調べます。 |
| `verHitboxes(bool)` | デバッグ用にヒットボックスを描画します。 |
