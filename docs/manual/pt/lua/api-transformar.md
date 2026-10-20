# Mover, rotacionar e escalar em 3D

| Função | O que faz |
|---|---|
| `posicion(obj) → x, y, z` | Onde ele está. |
| `setPosicion(obj, x, y, z)` | Coloca-o em um lugar exato (ignora a física). |
| `mover(obj, dx, dy, dz)` | Desloca-o a partir de onde está (use com `dt`). |
| `rotacion(obj) → x, y, z` | A sua rotação em graus. |
| `setRotacion(obj, x, y, z [, orden])` | Rotação exata; `orden` é, por exemplo, `"YXZ"` (padrão `"XYZ"`). |
| `girar(obj, dx, dy, dz)` | Gira-o sobre os seus próprios eixos. |
| `girarHacia(obj, dx, dz [, factor])` | Vai girando-o suavemente em direção a uma direção do chão. |
| `mirarA(obj, x, y, z)` | Aponta-o para um ponto (a frente de uma câmera). |
| `escala(obj) → sx, sy, sz` | A sua escala. |
| `setEscala(obj, s [, sy, sz])` | Escala exata; com um só número, escala por igual. |
| `escalar(obj, f)` | Multiplica a escala atual. |
| `puntoMundo(obj, x, y, z) → x, y, z` | Passa um ponto do objeto para coordenadas do mundo. |
| `visible(obj) → bool`, `setVisible(obj, bool)` | Mostra-o ou oculta-o. Um objeto oculto deixa de receber `actualizar`. |
| `setTinte(obj, r, g, b [, a])` | Muda a sua cor (valores de 0 a 1). |
