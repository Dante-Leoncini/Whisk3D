# Animação

| Função | O que faz |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | Animações da cena inteira. |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | Clipes de animação de um objeto e seus filhos. |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | Animações de uma armação (andar, pular…) e a transição suave entre elas. |
| `animCapa(esq, n, clip [, peso, modo])` e família | Misturar várias animações ao mesmo tempo em camadas (1 a 16), por exemplo correr + atirar. |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | Onde está um osso (para colocar uma arma na mão). |
| `animar(malla, n [, frame])` | Muda a animação de vértices de uma malha. |
