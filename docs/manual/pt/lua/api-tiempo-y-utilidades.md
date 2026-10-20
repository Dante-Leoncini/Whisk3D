# Tempo, acaso e utilitários

| Função | O que faz |
|---|---|
| `azar() → 0..1`, `azar(min, max) → entero` | Números aleatórios. |
| `relojMs() → ms` | Milissegundos, para medir quanto algo demora. |
| `perfilLua(cuadros [, etiqueta])` | Mede quais partes do script são lentas (`perfilLua(0)` o desliga). |
| `lineaCrear(nombre, puntos)`, `lineaPunto(id, s)` | Uma curva suave fechada calculada pelo motor (percursos). |

Não há uma função de "tempo desde o início": some `dt` em uma variável.
