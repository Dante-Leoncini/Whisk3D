# Edit Mode（网格）

在网格上按 <kbd>Tab</kbd> 进入。根据顶部栏按钮的选择，你可以操作**顶点**、**边**或**面**。

## Select

| 功能 | 说明 | 快捷键 |
|---|---|---|
| Select | 选择一个顶点、边或面。 | 单击；<kbd>Shift</kbd>+单击切换选择 |
| Select Linked | 选中指针下方整个相连的岛。 | <kbd>L</kbd> |
| Loop Select | 选中一圈边或面。 | <kbd>Shift+Alt</kbd>+单击 |
| Pick Shortest Path | 选中活动元素与单击元素之间的路径。 | <kbd>Ctrl</kbd>+单击 |
| Shortest Path (Fill Region) | 选中两者之间的整个区域。 | <kbd>Ctrl+Shift</kbd>+单击 |
| All / None / Invert / Box Select | 与 Object Mode 中相同，但作用于网格元素。 | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## 建模

| 功能 | 说明 | 快捷键 |
|---|---|---|
| Move / Rotate / Scale | 变换所选内容。移动过程中再按一次 <kbd>G</kbd> 会切换为滑动。 | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Shrink/Fatten | 让每个顶点沿自身法线移动（膨胀或收缩）。 | <kbd>Alt+S</kbd> |
| Extrude | 从所选内容挤出新的几何体（面沿其法线方向挤出）。 | <kbd>E</kbd> |
| Loop Cut and Slide | 切出一圈边。滚轮改变切割数量；单击应用，之后再滑动。 | <kbd>Ctrl+R</kbd> |
| New Edge/Face from Vertices | 用一条边或一个面连接所选的顶点。 | <kbd>F</kbd> |
| Connect Vertex Path | 在两个顶点之间沿直线切割。 | <kbd>J</kbd> |
| Vertex Slide | 让顶点沿着边滑动。 | <kbd>Shift+V</kbd> |
| Rip | 沿所选部分把网格撕开。 | <kbd>V</kbd> |
| Duplicate | 复制所选内容，并保持抓取状态。 | <kbd>Shift+D</kbd> |
| Separate | 把所选的面移到一个新对象中。 | <kbd>P</kbd> |
| Merge | 焊接顶点：到中心、到光标、塌陷或按距离。 | <kbd>M</kbd> |
| Auto Merge | 移动结束时，把距离小于阈值的顶点焊接起来。 | Mesh 菜单 |
| Delete | 顶点、边、面或循环边。 | <kbd>X</kbd> 或 <kbd>Delete</kbd> |
| Recalculate Normals / Flip | 修正面的朝向，或将其翻转。 | <kbd>Shift+N</kbd> |
| Triangulate Faces | 把超过 3 条边的面拆分成三角形。 | <kbd>Ctrl+T</kbd> |
| Shade Smooth / Shade Flat | 表面的光照方式。 | Face 菜单 |
| Mark Sharp / Clear Sharp | 即使网格是平滑的，这些边看起来也是硬边。 | Edge 菜单 |
| Mark Seam / Clear Seam | 展开 UV 时网格从哪里切开。 | Edge 或 UV 菜单 |
| Context menu | 在指针处显示当前子模式（顶点、边或面）的操作。 | <kbd>W</kbd> 或右键单击 |
| Insert Keyframe | 在当前帧保存网格的形状（顶点动画）。 | <kbd>I</kbd> |

## UV 菜单

| 功能 | 说明 | 快捷键 |
|---|---|---|
| Unwrap | 基于角度、保角或最小拉伸：沿缝合线把网格展开。 | <kbd>U</kbd> |
| Smart UV Project | 根据面与面之间的角度，自动切割并展开。 | <kbd>U</kbd> |
| Lightmap Pack / Follow Active Quads | 岛整齐排列且互不重叠 / UV 按活动面的走向整齐排列。 | <kbd>U</kbd> |
| Cube Projection、Cylinder Projection、Sphere Projection、Project from View | 简单的投影。 | <kbd>U</kbd> |
| Reset | 每个面都占满整张图像。 | <kbd>U</kbd> |

## 编辑曲线（路径）

在曲线上按 <kbd>Tab</kbd>，就可以像编辑由点组成的网格一样编辑它的节点：<kbd>G</kbd> 移动，<kbd>E</kbd> 添加下一个节点，<kbd>X</kbd> 删除。
