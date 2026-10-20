# UV Editor

Показывает, как текстура ложится на меш. Чтобы редактировать, меш должен быть в **Edit Mode в 3D Viewport**; иначе редактор только показывает текстуру. У UV Editor свой собственный режим: он не меняет режим 3D Viewport. Инструменты развёртки и проецирования UV находятся в 3D Viewport (Edit Mode, клавиша <kbd>U</kbd>).

## Навигация и верхняя панель

| Функция | Описание | Как использовать |
|---|---|---|
| Зум / Панорамирование | Приближает к указателю / сдвигает вид. | Колесо / средняя кнопка или стрелки; на сенсорном экране: 1 палец сдвигает, 2 пальца — зум |
| Mode | Object Mode, Edit Mode, Weight Paint, Edit Bones и Pose Mode (последние два — если у меша есть 2D-скелет). | Кнопка режима, <kbd>Tab</kbd> |
| Vertex / Edge / Face | Что выделяется в Edit Mode. | Кнопка |
| Pivot | 3D Cursor, Individual Origins или Median Point. | Кнопка |
| Cursor | Cursor to Selection, Selection to Cursor, Cursor to Center. | Меню |
| View | Sync Selection (UV-выделение совпадает с выделением меша), Repeat Texture (мозаика), Show Chrome UV, Frame Selected, Frame All. | Меню; <kbd>Num.</kbd> |
| Texture | Какая текстура показывается: New Texture…, Auto (active part) или любая текстура проекта. | Меню |
| New Texture | Создаёт изображение (имя, размер, цвет, прозрачность; Blank, UV Grid или Color Grid), сохраняет его в проекте и назначает материалу. | Texture → New Texture… |
| Mipmap | Показывает конкретный уровень mipmap, чтобы его проверить. | Кнопка Mip |
| Edit | Включает и выключает рисование текстуры прямо на изображении. | Кнопка Edit |
| Save (дискета, видна всегда) | Save, Save As…, Save outside the .w3d…, Save inside the .w3d, Export UV Layout… | Меню |
| Export UV Layout | Сохраняет PNG с прозрачным фоном: полупрозрачные грани (плотнее там, где они перекрываются) и непрозрачные линии. Можно выбрать имя, папку и разрешение (по умолчанию 512, 256 на N95, или размер показанной текстуры). | Save → Export UV Layout… |
| Animation | Вставка, удаление или очистка ключевых кадров UV-слоя или 2D-позы. | Меню |

## Object Mode (UV)

Клик выбирает, что редактировать: 2D-скелет (если коснуться кости) или геометрию. <kbd>Tab</kbd> входит в редактирование выбранного.

## Edit Mode (UV)

| Функция | Описание | Сочетание |
|---|---|---|
| Select | Вершины, рёбра или грани UV. Без синхронизации 3D Viewport фильтрует: видны только грани, выделенные в 3D. | Клик; <kbd>Shift</kbd>+клик |
| All / None / Invert | Для видимого. | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | UV-остров под указателем (<kbd>Shift</kbd> добавляет). | <kbd>L</kbd> |
| Box Select | Прямоугольник; <kbd>Shift</kbd> добавляет. | <kbd>B</kbd> |
| Move / Rotate / Scale | Трансформирует UV. <kbd>X</kbd> / <kbd>Y</kbd> фиксируют ось; значение можно ввести с клавиатуры (1.0 = одна плитка). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Установка 2D-курсора | Ставит курсор туда, где кликнули. | Правый клик |
| Insert Keyframe | Сохраняет UV-слой в активную вершинную анимацию. | <kbd>I</kbd> |

## Weight Paint (UV)

Рисует веса 2D-костей на UV-развёртке, с теми же элементами управления, что и в 3D Viewport (режим +/−/=, группа, метки, спад, только выделенное). <kbd>Ctrl</kbd>+клик по кости выбирает её для рисования.

## Edit Bones и Pose Mode (2D-скелет)

| Функция | Описание | Сочетание |
|---|---|---|
| Добавить Armature 2D / Bone | Создаёт 2D-скелет меша (с его UV-группой) или добавляет кость. | Меню Add |
| Select | Конец кости или вся кость; перетаскивание её перемещает. | Клик; <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | В Edit Bones меняет положение покоя; в Pose Mode ставит позу (взвешенные UV следуют за костью). | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | Только в Edit Bones. | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | Keep Offset или Connected / Disconnect. | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | В Pose Mode: меню каналов или всё сразу с <kbd>Shift+I</kbd>. | <kbd>I</kbd> |

## Texture Paint (UV)

Кнопкой **Edit** можно рисовать прямо на изображении, с цветом, спадом, радиусом и силой. Сохраняется через дискету.
