# UV Editor

显示纹理是如何贴在网格上的。要进行编辑，网格必须**在 3D Viewport 中处于 Edit Mode**；否则编辑器只会显示纹理。UV Editor 有自己独立的模式：它不会改变 3D Viewport 的模式。展开和投影 UV 的工具位于 3D Viewport 中（Edit Mode，按 <kbd>U</kbd> 键）。

## 导航和顶部栏

| 功能 | 说明 | 使用方法 |
|---|---|---|
| 缩放 / 平移 | 朝指针方向拉近 / 移动视图。 | 滚轮 / 中键或方向键；触屏：单指平移，双指缩放 |
| Mode | Object Mode、Edit Mode、Weight Paint、Edit Bones 和 Pose Mode（后两者仅当网格有 2D 骨架时可用）。 | 模式按钮，<kbd>Tab</kbd> |
| Vertex / Edge / Face | 在 Edit Mode 中选择哪种元素。 | 按钮 |
| Pivot | Cursor、Individual Origins 或 Median Point。 | 按钮 |
| Cursor | Cursor to Selection、Selection to Cursor、Cursor to Center。 | 菜单 |
| View | Sync Selection（UV 选择与网格选择相同）、Repeat Texture（平铺）、Show Chrome UV、Frame Selected、Frame All。 | 菜单；<kbd>Num.</kbd> |
| Texture | 显示哪张纹理：New Texture…、Auto（活动部分的纹理），或项目中的任意一张纹理。 | 菜单 |
| New Texture | 创建一张图像（名称、尺寸、颜色、透明度；纯色、UV 网格或彩色网格），把它保存到项目中并指定给材质。 | Texture → New Texture… |
| Mipmap | 显示某一级 mipmap，方便检查。 | Mip 按钮 |
| Edit | 进入或退出在图像上的纹理绘制。 | Edit 按钮 |
| Save（软盘图标，始终可见） | Save、Save As…、Save outside the .w3d…、Save inside the .w3d、Export UV Layout… | 菜单 |
| Export UV Layout | 保存一张透明背景的 PNG：半透明的面（重叠处更不透明）和不透明的线条。可以选择名称、文件夹和分辨率（默认 512，N95 上为 256，或当前显示纹理的尺寸）。 | Save → Export UV Layout… |
| Animation | 插入、删除或清除 UV 层或 2D 姿势的关键帧。 | 菜单 |

## Object Mode（UV）

单击选择要编辑的内容：2D 骨架（如果点到的是骨骼）或几何体。<kbd>Tab</kbd> 进入所选内容的编辑。

## Edit Mode（UV）

| 功能 | 说明 | 快捷键 |
|---|---|---|
| Select | UV 顶点、边或面。未同步时，3D Viewport 会进行过滤：只显示在 3D 中选中的面。 | 单击；<kbd>Shift</kbd>+单击 |
| All / None / Invert | 作用于可见的部分。 | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | 指针下方的 UV 岛（<kbd>Shift</kbd> 加选）。 | <kbd>L</kbd> |
| Box Select | 矩形框选；<kbd>Shift</kbd> 加选。 | <kbd>B</kbd> |
| Move / Rotate / Scale | 变换 UV。<kbd>X</kbd> / <kbd>Y</kbd> 锁定一个轴；可以直接输入数值（1.0 = 一块平铺）。 | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| 放置 2D Cursor | 把光标放到单击的位置。 | 右键单击 |
| Insert Keyframe | 把 UV 层保存到当前活动的顶点动画中。 | <kbd>I</kbd> |

## Weight Paint（UV）

在 UV 贴图上绘制 2D 骨骼的权重，控件与 3D Viewport 中相同（+/−/= 模式、组、标记、衰减、仅限所选）。<kbd>Ctrl</kbd>+单击某根骨骼，即可选中它来绘制。

## Edit Bones 和 Pose Mode（2D 骨架）

| 功能 | 说明 | 快捷键 |
|---|---|---|
| Add Armature 2D / Bone | 为网格创建 2D 骨架（连同其 UV 组），或添加一根骨骼。 | Add 菜单 |
| Select | 一个端点或整根骨骼；拖动可以移动它。 | 单击；<kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | 在 Edit Bones 中改变静止位置；在 Pose 中摆姿势（加权的 UV 会跟随骨骼）。 | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | 仅在 Edit Bones 中可用。 | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | Keep Offset 或 Connected / Disconnect。 | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | 在 Pose 中：通道菜单，或用 <kbd>Shift+I</kbd> 插入全部。 | <kbd>I</kbd> |

## Texture Paint（UV）

用 **Edit** 按钮可以直接在图像上绘制，可设置颜色、衰减、半径和力度。通过软盘图标保存。
