# Editor UV

Mostra como a textura se apoia sobre a malha. Para editar, a malha precisa estar em **Modo Edição na Viewport 3D**; se não, o editor só mostra a textura. O modo do Editor UV é próprio: não muda o modo da Viewport 3D. As ferramentas para desdobrar e projetar UVs estão na Viewport 3D (Modo Edição, tecla <kbd>U</kbd>).

## Navegação e barra superior

| Função | Descrição | Como usar |
|---|---|---|
| Zoom / Deslocar | Aproxima em direção ao ponteiro / move a vista. | Roda / botão do meio ou setas; touch: 1 dedo desloca, 2 dedos dão zoom |
| Modo | Modo Objeto, Modo Edição, Pintura de pesos, Editar ossos e Modo Pose (esses dois se a malha tiver armação 2D). | Botão de modo, <kbd>Tab</kbd> |
| Vértice / Aresta / Face | O que é selecionado no Modo Edição. | Botão |
| Pivô | Cursor, origens individuais ou ponto médio. | Botão |
| Cursor | Cursor para seleção, seleção para o cursor, cursor para o centro. | Menu |
| Vista | Sincronizar seleção (a seleção UV é a mesma da malha), Repetir textura (mosaico), Mostrar chrome UV, Enquadrar seleção, Enquadrar tudo. | Menu; <kbd>Num.</kbd> |
| Textura | Qual textura é mostrada: Nova textura…, Auto (a da parte ativa), ou qualquer uma do projeto. | Menu |
| Nova textura | Cria uma imagem (nome, tamanho, cor, transparência; lisa, grade UV ou grade de cores), salva-a no projeto e a atribui ao material. | Textura → Nova textura… |
| Mipmap | Mostra um nível de mipmap específico, para revisá-lo. | Botão Mip |
| Editar | Entra e sai da pintura de textura sobre a imagem. | Botão Editar |
| Salvar (disquete, sempre visível) | Salvar, Salvar como…, Salvar fora do w3d…, Salvar no w3d, Exportar mapa UV… | Menu |
| Exportar mapa UV | Salva um PNG com fundo transparente: faces semitransparentes (mais opacas onde se sobrepõem) e linhas opacas. Você escolhe nome, pasta e resolução (padrão 512, 256 no N95, ou o tamanho da textura mostrada). | Salvar → Exportar mapa UV… |
| Animação | Inserir, excluir ou limpar keyframes da camada UV, ou da pose 2D. | Menu |

## Modo Objeto (UV)

O clique escolhe o que é editado: uma armação 2D (se você tocar em um osso) ou a geometria. <kbd>Tab</kbd> entra para editar o que foi escolhido.

## Modo Edição (UV)

| Função | Descrição | Atalho |
|---|---|---|
| Selecionar | Vértices, arestas ou faces UV. Sem sincronizar, a Viewport 3D filtra: só aparecem as faces selecionadas em 3D. | Clique; <kbd>Shift</kbd>+clique |
| Tudo / Nenhum / Inverter | Sobre o que está visível. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Selecionar vinculado | A ilha UV sob o ponteiro (<kbd>Shift</kbd> adiciona). | <kbd>L</kbd> |
| Seleção por caixa | Retângulo; <kbd>Shift</kbd> adiciona. | <kbd>B</kbd> |
| Mover / Rotacionar / Escalar | Transforma as UV. <kbd>X</kbd> / <kbd>Y</kbd> travam um eixo; dá para digitar o valor (1.0 = um ladrilho). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Posicionar o cursor 2D | Coloca o cursor onde você clica. | Clique direito |
| Inserir keyframe | Salva a camada UV na animação de vértices ativa. | <kbd>I</kbd> |

## Pintura de pesos (UV)

Pinta os pesos dos ossos 2D sobre o mapa UV, com os mesmos controles da Viewport 3D (modo +/−/=, grupo, marcas, queda, só o selecionado). <kbd>Ctrl</kbd>+clique sobre um osso o escolhe para pintar.

## Editar ossos e Modo Pose (armação 2D)

| Função | Descrição | Atalho |
|---|---|---|
| Adicionar armação 2D / osso | Cria a armação 2D da malha (com seu grupo UV) ou adiciona um osso. | Menu Adicionar |
| Selecionar | Uma ponta ou o osso inteiro; arrastar o move. | Clique; <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Mover / Rotacionar / Escalar | Em Editar ossos, muda a posição de repouso; em Pose, posa (as UV com peso seguem o osso). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrudar / Duplicar / Excluir | Só em Editar ossos. | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Parentear / Desparentear | Manter deslocamento ou conectado / desconectar. | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Inserir keyframe | Em Pose: menu de canais, ou tudo com <kbd>Shift+I</kbd>. | <kbd>I</kbd> |

## Pintura de textura (UV)

Com o botão **Editar**, você pinta diretamente sobre a imagem, com cor, queda, raio e força. Salva-se pelo disquete.
