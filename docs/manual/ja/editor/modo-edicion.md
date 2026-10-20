# Edit Mode（メッシュ）

メッシュを選んで<kbd>Tab</kbd>を押すと入ります。上部バーのボタンに応じて、**頂点**、**辺**、**面**のいずれかを対象に作業します。

## 選択

| 機能 | 説明 | ショートカット |
|---|---|---|
| Select | 頂点、辺、面を選択します。 | クリック。<kbd>Shift</kbd>+クリックで切り替え |
| Select Linked | ポインターの下にある、つながったアイランド全体を選択します。 | <kbd>L</kbd> |
| Loop Select | 辺または面のループを選択します。 | <kbd>Shift+Alt</kbd>+クリック |
| Pick Shortest Path | アクティブな要素とクリックした要素の間の経路を選択します。 | <kbd>Ctrl</kbd>+クリック |
| Shortest Path (Fill Region) | 2つの間の領域全体を選択します。 | <kbd>Ctrl+Shift</kbd>+クリック |
| All / None / Invert / Box | Object Modeと同じですが、メッシュの要素に対して働きます。 | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## モデリング

| 機能 | 説明 | ショートカット |
|---|---|---|
| Move / Rotate / Scale | 選択したものをトランスフォームします。移動中にもう一度<kbd>G</kbd>を押すと、スライドに切り替わります。 | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Shrink/Fatten | 各頂点を法線の方向に動かします（膨らませる、またはしぼませる）。 | <kbd>Alt+S</kbd> |
| Extrude | 選択したものから新しいジオメトリを押し出します（面は法線の方向に出ます）。 | <kbd>E</kbd> |
| Loop Cut and Slide | 辺のループをカットします。ホイールでカットの数を変え、クリックで適用したあとスライドします。 | <kbd>Ctrl+R</kbd> |
| New Edge/Face from Vertices | 選択した頂点を辺または面でつなぎます。 | <kbd>F</kbd> |
| Connect Vertex Path | 2つの頂点の間を直線でカットします。 | <kbd>J</kbd> |
| Slide Vertices | 頂点をその辺に沿ってスライドします。 | <kbd>Shift+V</kbd> |
| Rip | 選択した部分でメッシュを切り離します。 | <kbd>V</kbd> |
| Duplicate | 選択したものをコピーして、つかんだ状態にします。 | <kbd>Shift+D</kbd> |
| Separate | 選択した面を新しいオブジェクトに移します。 | <kbd>P</kbd> |
| Merge | 頂点を結合します：At Center、At Cursor、Collapse、By Distance。 | <kbd>M</kbd> |
| Auto Merge | 移動を終えたときに、しきい値より近くにある頂点を結合します。 | Meshメニュー |
| Delete | 頂点、辺、面、または辺ループ。 | <kbd>X</kbd>または<kbd>Delete</kbd> |
| Recalculate Normals / Flip | 面の向きを修正する、または反転します。 | <kbd>Shift+N</kbd> |
| Triangulate Faces | 4辺以上の面を三角形に分割します。 | <kbd>Ctrl+T</kbd> |
| Shade Smooth / Flat | 表面の照らされ方を決めます。 | Faceメニュー |
| Mark Sharp / Clear Sharp | メッシュがスムーズでも、硬く見える辺。 | Edgeメニュー |
| Mark Seam / Clear Seam | UVを展開するときに、メッシュを切り開く場所。 | EdgeメニューまたはUVメニュー |
| Context menu | 現在のサブモード（頂点、辺、面）の操作を、ポインターの位置に表示します。 | <kbd>W</kbd>または右クリック |
| Insert Keyframe | 現在のフレームにメッシュの形状を保存します（頂点アニメーション）。 | <kbd>I</kbd> |

## UVメニュー

| 機能 | 説明 | ショートカット |
|---|---|---|
| Unwrap | Angle Based、Conformal、Minimum Stretch：シームに沿ってメッシュを開きます。 | <kbd>U</kbd> |
| Smart UV Project | 面の間の角度に応じて、自動でカットして展開します。 | <kbd>U</kbd> |
| Lightmap Pack / Follow Active Quads | 重ならないように並べたアイランド / アクティブな面に沿って整列したUV。 | <kbd>U</kbd> |
| Cube Projection、Cylinder Projection、Sphere Projection、Project from View | シンプルな投影です。 | <kbd>U</kbd> |
| Reset | 各面が画像全体を使います。 | <kbd>U</kbd> |

## カーブ（パス）の編集

カーブを選んで<kbd>Tab</kbd>を押すと、点だけのメッシュのようにノードを編集できます：<kbd>G</kbd>で移動、<kbd>E</kbd>で次のノードを追加、<kbd>X</kbd>で削除します。
