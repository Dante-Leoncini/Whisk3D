# 脚本是对象的一个组件

在 Whisk3D 中，脚本总是属于场景中的某个**对象**（一个网格、一个空物体、一个 2D 按钮……）。一个对象可以有多个脚本；每个脚本独立运行，拥有自己的变量，并按出现的顺序执行。

在脚本中，`yo()` 返回拥有该脚本的对象。要使用*其他*对象，脚本需要声明一个名为 `propiedades` 的全局表。编辑器会读取它，并在 Properties 面板中该脚本的卡片上，为每个条目显示一个字段：

```lua
propiedades = {
  pelota     = "objeto",                          -- 一个字段，用来选择场景中的对象
  dificultad = { "facil", "normal", "dificil" },  -- 一个下拉列表（第一项是默认值）
  velocidad  = 200,                               -- 使用该脚本的每个对象各自的数字
  activo     = true,                              -- 一个是/否开关
  etiqueta   = "caja",                            -- 一段文本
}

function inicio()
  local p   = objeto("pelota")         -- 在 "pelota" 字段中选择的对象
  local dif = opcion("dificultad")     -- "facil"、"normal" 或 "dificil"
  local v   = propiedad("velocidad")   -- 200，或在该对象上设置的值
end
```

这样，同一个脚本就可以用于许多取值不同的对象：一个敌人的 `velocidad` 字段可以是 200，另一个可以是 350。

> [!NOTE]
> 为了读取 `propiedades`，即使游戏没有运行，编辑器也会**执行该文件**。所以在函数之外只放声明（表、常量、`local`），绝不要放会实际做事情的代码。

脚本之间不共享变量。要互相传递数据（分数、玩家是否获胜……），它们使用一个共享空间：`setCompartido("puntos", 10)` 写入，`compartido("puntos")` 读取。它可以保存数字、是/否和文本，游戏停止时会被清空。
