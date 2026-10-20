# Анимация

| Функция | Что делает |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | Анимации всей сцены. |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | Клипы анимации объекта и его потомков. |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | Анимации скелета (ходьба, прыжок…) и плавный переход между ними. |
| `animCapa(esq, n, clip [, peso, modo])` и родственные функции | Смешивание нескольких анимаций одновременно по слоям (от 1 до 16), например бег + стрельба. |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | Где находится кость (чтобы вложить оружие в руку). |
| `animar(malla, n [, frame])` | Меняет вершинную анимацию меша. |
