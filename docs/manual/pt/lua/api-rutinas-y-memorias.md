# Rotinas e memórias

As rotinas (listas de passos de desenho montadas no painel de Propriedades) podem ler valores que o Lua define. Cada memória é um bloco de 256 números com nome, e os passos a leem como `@nombre[i]`.

| Função | O que faz |
|---|---|
| `setMemoria(nombre, i, v)`, `memoria(nombre, i)`, `setMemorias(nombre, i, v1, v2, ...)` | Escrever e ler memórias (o índice vai de **0** a 255). |
| `setPaso(rutina, i, campo, ...)`, `leerPaso(rutina, i, campo)` | Mudar ou ler um passo de uma rotina (campos: `"on"`, `"n"`, `"color"`, `"ref"`, `"modo"`, `"entero"`). |
| `paso(nombre, ...)` | Executa um passo de desenho; só vale dentro de uma função chamada pelo passo "Chamar Lua" de uma rotina. |

Em uma rotina com **Repetir** maior que 1, a memória `bucle` diz em qual volta ela está: `@bucle[0]` é a volta atual (a partir de 0) e `@bucle[1]` o total.
