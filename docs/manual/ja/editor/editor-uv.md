# UV Editor

テクスチャがメッシュにどう貼られているかを表示します。編集するには、メッシュが**3D ViewportでEdit Mode**になっている必要があります。そうでない場合、エディターはテクスチャを表示するだけです。UV Editorのモードは独自のもので、3D Viewportのモードは変わりません。UVを展開・投影するツールは3D Viewportにあります（Edit Mode、<kbd>U</kbd>キー）。

## ナビゲーションと上部バー

| 機能 | 説明 | 使い方 |
|---|---|---|
| ズーム / パン | ポインターに向かってズームします / ビューを動かします。 | ホイール / 中ボタンまたは方向キー。タッチ：1本指でパン、2本指でズーム |
| Mode | Object Mode、Edit Mode、Weight Paint、Edit Bones、Pose Mode（最後の2つは、メッシュに2Dアーマチュアがある場合）。 | モードボタン、<kbd>Tab</kbd> |
| Vertex / Edge / Face | Edit Modeで何を選択するかを決めます。 | ボタン |
| Pivot | Cursor、Individual Origins、Median Point。 | ボタン |
| Cursor | Cursor to Selection、Selection to Cursor、Cursor to Center。 | メニュー |
| View | Sync Selection（UVの選択がメッシュの選択と同じになります）、Repeat Texture（タイル表示）、Show Chrome UV、Frame Selected、Frame All。 | メニュー。<kbd>Num.</kbd> |
| Texture | 表示するテクスチャ：New Texture…、Auto（アクティブなパーツのもの）、またはプロジェクト内の任意のテクスチャ。 | メニュー |
| New Texture | 画像を作成し（名前、サイズ、色、透明度。Blank、UV Grid、Color Grid）、プロジェクトに保存してマテリアルに割り当てます。 | Texture → New Texture… |
| Mipmap | 特定のミップマップレベルを表示して確認します。 | Mipボタン |
| Edit | 画像上でのテクスチャペイントを開始・終了します。 | Editボタン |
| Save（フロッピーディスク、常に表示） | Save、Save As…、Save outside the .w3d…、Save inside the .w3d、Export UV Layout… | メニュー |
| Export UV Layout | 背景が透明なPNGを保存します：面は半透明（重なる所ほど不透明）、線は不透明です。名前、フォルダー、解像度を選びます（初期値は512、N95では256、または表示中のテクスチャのサイズ）。 | Save → Export UV Layout… |
| Animation | UVレイヤーまたは2Dポーズのキーフレームを挿入、削除、クリアします。 | メニュー |

## Object Mode（UV）

クリックで編集する対象を選びます：2Dアーマチュア（ボーンに触れた場合）またはジオメトリ。<kbd>Tab</kbd>で、選んだものの編集に入ります。

## Edit Mode（UV）

| 機能 | 説明 | ショートカット |
|---|---|---|
| Select | UVの頂点、辺、面。同期していない場合は3D Viewportで絞り込みが行われ、3Dで選択した面だけが表示されます。 | クリック。<kbd>Shift</kbd>+クリック |
| All / None / Invert | 表示されているものに対して働きます。 | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | ポインターの下にあるUVアイランド（<kbd>Shift</kbd>で追加）。 | <kbd>L</kbd> |
| Box Select | 四角形で選択します。<kbd>Shift</kbd>で追加します。 | <kbd>B</kbd> |
| Move / Rotate / Scale | UVをトランスフォームします。<kbd>X</kbd> / <kbd>Y</kbd>で軸を固定します。値を入力することもできます（1.0 = タイル1枚分）。 | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| 2Dカーソルの配置 | クリックした位置にカーソルを置きます。 | 右クリック |
| Insert Keyframe | アクティブな頂点アニメーションにUVレイヤーを保存します。 | <kbd>I</kbd> |

## Weight Paint（UV）

UVマップ上で2Dボーンのウェイトをペイントします。操作は3D Viewportと同じです（+/−/=のモード、グループ、Markers、Falloff、Selected only）。ボーンを<kbd>Ctrl</kbd>+クリックすると、ペイントする対象として選択されます。

## Edit BonesとPose Mode（2Dアーマチュア）

| 機能 | 説明 | ショートカット |
|---|---|---|
| Add Armature 2D / Bone | メッシュの2Dアーマチュアを（UVグループとともに）作成する、またはボーンを追加します。 | Addメニュー |
| Select | 先端の1つ、またはボーン全体を選択します。ドラッグで移動します。 | クリック。<kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | Edit Bonesでは静止位置を変え、Poseではポーズを付けます（ウェイトが付いたUVはボーンについていきます）。 | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | Edit Bonesのみです。 | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | オフセットを保持、または接続 / 切り離し。 | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | Poseで使います：チャンネルのメニュー、または<kbd>Shift+I</kbd>ですべて。 | <kbd>I</kbd> |

## Texture Paint（UV）

**Edit**ボタンで、色、Falloff、Radius、強さを指定して画像に直接ペイントします。保存はフロッピーディスクのアイコンから行います。
