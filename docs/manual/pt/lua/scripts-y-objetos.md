# Um script é um componente de um objeto

No Whisk3D, um script sempre pertence a um **objeto** da cena (uma malha, um vazio, um botão 2D…). Um objeto pode ter vários scripts; cada um roda separadamente, com suas próprias variáveis, na ordem em que aparecem.

No script, `yo()` devolve o objeto dono. Para usar *outros* objetos, o script declara uma tabela global chamada `propiedades`. O editor a lê e mostra um campo para cada entrada no cartão do script, no painel de Propriedades:

```lua
propiedades = {
  pelota     = "objeto",                          -- um campo para escolher um objeto da cena
  dificultad = { "facil", "normal", "dificil" },  -- uma lista suspensa (a primeira é a padrão)
  velocidad  = 200,                               -- um número próprio de cada objeto que usar o script
  activo     = true,                              -- um sim/não
  etiqueta   = "caja",                            -- um texto
}

function inicio()
  local p   = objeto("pelota")         -- o objeto escolhido no campo "pelota"
  local dif = opcion("dificultad")     -- "facil", "normal" ou "dificil"
  local v   = propiedad("velocidad")   -- 200, ou o que tiver sido definido nesse objeto
end
```

Assim, o mesmo script serve para muitos objetos com valores diferentes: o campo `velocidad` de um inimigo pode valer 200 e o de outro, 350.

> [!NOTE]
> Para ler `propiedades`, o editor **executa o arquivo** mesmo que o jogo não esteja rodando. Por isso, fora das funções coloque só declarações (tabelas, constantes, `local`), nunca código que faça coisas.

Os scripts não compartilham variáveis entre si. Para passar dados uns aos outros (os pontos, se o jogador ganhou…), eles usam um espaço compartilhado: `setCompartido("puntos", 10)` escreve e `compartido("puntos")` lê. Ele guarda números, sim/não e textos, e é esvaziado ao parar o jogo.
