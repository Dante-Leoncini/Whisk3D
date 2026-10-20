# Modo Edição (malhas)

Entra-se com <kbd>Tab</kbd> sobre uma malha. Você trabalha sobre **vértices**, **arestas** ou **faces**, conforme o botão da barra superior.

## Selecionar

| Função | Descrição | Atalho |
|---|---|---|
| Selecionar | Escolhe um vértice, aresta ou face. | Clique; <kbd>Shift</kbd>+clique alterna |
| Selecionar vinculado | Toda a ilha conectada sob o ponteiro. | <kbd>L</kbd> |
| Selecionar loop | Um anel de arestas ou de faces. | <kbd>Shift+Alt</kbd>+clique |
| Caminho mais curto | Seleciona o caminho entre o ativo e o clicado. | <kbd>Ctrl</kbd>+clique |
| Caminho mais curto (preencher região) | Seleciona toda a região entre os dois. | <kbd>Ctrl+Shift</kbd>+clique |
| Tudo / Nenhum / Inverter / Caixa | Como no Modo Objeto, sobre os elementos da malha. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## Modelar

| Função | Descrição | Atalho |
|---|---|---|
| Mover / Rotacionar / Escalar | Transforma o que está selecionado. Com um mover em andamento, outro <kbd>G</kbd> passa a deslizar. | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Encolher / Engrossar | Move cada vértice pela sua normal (infla ou desinfla). | <kbd>Alt+S</kbd> |
| Extrudar | Cria geometria nova a partir do que está selecionado (as faces saem pela sua normal). | <kbd>E</kbd> |
| Loop Cut e Deslizar | Corta um anel de arestas. A roda muda a quantidade de cortes; o clique aplica e depois desliza. | <kbd>Ctrl+R</kbd> |
| Nova aresta / face dos vértices | Une os vértices selecionados com uma aresta ou uma face. | <kbd>F</kbd> |
| Conectar caminho de vértices | Corta em linha reta entre dois vértices. | <kbd>J</kbd> |
| Deslizar vértices | Desliza os vértices ao longo das suas arestas. | <kbd>Shift+V</kbd> |
| Rasgar | Separa a malha pela seleção. | <kbd>V</kbd> |
| Duplicar | Copia o que está selecionado e o deixa preso ao ponteiro. | <kbd>Shift+D</kbd> |
| Separar | Passa as faces selecionadas para um objeto novo. | <kbd>P</kbd> |
| Mesclar | Solda vértices: no centro, no cursor, colapsar ou por distância. | <kbd>M</kbd> |
| Auto mesclar | Ao terminar de mover, solda os vértices que ficaram mais perto que o limite. | Menu Malha |
| Excluir | Vértices, arestas, faces ou loops de arestas. | <kbd>X</kbd> ou <kbd>Delete</kbd> |
| Recalcular normais / Virar | Corrige para onde as faces apontam, ou as vira ao contrário. | <kbd>Shift+N</kbd> |
| Triangular faces | Divide em triângulos as faces com mais de 3 lados. | <kbd>Ctrl+T</kbd> |
| Sombreamento suave / plano | Como a superfície é iluminada. | Menu Face |
| Marcar / limpar aguda | Arestas que aparecem duras mesmo que a malha seja suave. | Menu Aresta |
| Marcar / limpar costura | Por onde a malha é cortada ao desdobrar as UV. | Menu Aresta ou UV |
| Menu de contexto | As operações do submodo atual (vértice, aresta ou face) no ponteiro. | <kbd>W</kbd> ou clique direito |
| Inserir keyframe | Salva a forma da malha no quadro atual (animação de vértices). | <kbd>I</kbd> |

## Menu UV

| Função | Descrição | Atalho |
|---|---|---|
| Desdobrar | Baseado em ângulos, conforme ou de mínimo estiramento: abre a malha pelas suas costuras. | <kbd>U</kbd> |
| Projeção UV inteligente | Corta e desdobra sozinha conforme os ângulos entre as faces. | <kbd>U</kbd> |
| Empacotar lightmap / Seguir quads ativos | Ilhas organizadas sem se sobrepor / UV organizadas seguindo a face ativa. | <kbd>U</kbd> |
| Projeção de cubo, cilindro, esfera, da vista | Projeções simples. | <kbd>U</kbd> |
| Redefinir | Cada face ocupa a imagem inteira. | <kbd>U</kbd> |

## Edição de curvas (caminhos)

Com <kbd>Tab</kbd> sobre uma curva, você edita os seus nós como se fosse uma malha de pontos: <kbd>G</kbd> move, <kbd>E</kbd> adiciona o nó seguinte, <kbd>X</kbd> exclui.
