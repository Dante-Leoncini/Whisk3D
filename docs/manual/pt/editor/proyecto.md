# O projeto (.w3d) e os arquivos

| Função | Descrição | Onde |
|---|---|---|
| Abrir projeto | Abre um .w3d (também com clique duplo pelo sistema). | Propriedades → Arquivo/Render → Arquivo |
| Salvar / Salvar como | Salva na pasta e com o nome do cartão; Salvar como pede outro. Se faltar o nome, o campo fica vermelho. | Cartão Arquivo, <kbd>Ctrl+S</kbd> |
| Salvar versão | Salva e, além disso, deixa uma cópia numerada (`proyecto_v03.w3d`). | Cartão Arquivo |
| Extrair assets | Copia tudo o que está dentro para uma pasta (as cópias não mudam o projeto). | Cartão Arquivo |
| Malhas em texto | Salva as malhas como texto legível em vez de binário. | Cartão Arquivo |
| Importar | OBJ, FBX, glTF, GLB e interfaces .w3dui. O que é importado é copiado para dentro do projeto (sem duplicados). | Viewport 3D → Adicionar → Importar |
| Exportar | OBJ, glTF ou GLB do objeto selecionado (com ou sem modificadores e transformações). | Propriedades → Exportar |
| Mudanças não salvas | O que foi editado e não salvo (scripts, texturas pintadas) é marcado com `*`. Ao fechar ou abrir outro projeto, um aviso lista o que seria perdido. | Automático |
| Recurso dentro ou fora | Um recurso externo não é copiado: o seu caminho é salvo e há um aviso se ele faltar. | Cartão Recurso; "Salvar no / fora do w3d" no IDE e no Editor UV |

O salvamento nunca deixa o arquivo pela metade: primeiro escreve uma cópia temporária e depois a renomeia.
