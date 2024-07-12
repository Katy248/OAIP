# Использование всех алгоритмических конструкций, типов данных и модуля `Tkinter` и `Tkinter.ttk`

## Задание (на три пары)

Разработать программу на языке Python, реализующую игру <q>Морской бой</q>. Интерфейс игры – графический. Сетевое решение – приветствуется _(+1 балл)_.

Игровое поле — квадрат 10×10 у каждого игрока, на котором размещается флот кораблей. Горизонтали обычно нумеруются сверху вниз, а вертикали помечаются буквами слева направо. При этом используются буквы русского алфавита от «а» до «к» (буквы «ё» и «й» обычно пропускаются) либо от «а» до «и» (с использованием буквы «ё»), либо буквы латинского алфавита от «a» до «j».

Размещаются:

- 1 корабль — ряд из 4 клеток («четырёхпалубный»)
- 2 корабля — ряд из 3 клеток («трёхпалубные»)
- 3 корабля — ряд из 2 клеток («двухпалубные»)
- 4 корабля — 1 клетка («однопалубные»)

При размещении корабли не могут касаться друг друга сторонами и углами. Рядом со «своим» полем чертится «чужое» такого же размера, только пустое. Это участок моря, где плавают корабли противника.

При попадании в корабль противника — на чужом поле ставится крестик, при холостом выстреле — точка. Попавший стреляет ещё раз.

Самыми уязвимыми являются линкор и торпедный катер: первый из-за крупных размеров, в связи с чем его сравнительно легко найти, а второй из-за того, что топится с одного удара, хотя его найти достаточно сложно.

Создать объект корабль, у которого должно быть свойство цвет и метод прорисовки. От него создать четыре потомка (корабли с соответствующими размерами). От этих потомков создать необходимое количество потомков (в зависимости от размеров корабля, если 4, то 1 корабль, если 3, то 2 корабля и т.д.), которых должны иметь свойство позиция. При попадании в корабль сменить его цвет на другой. Клетки реализовать объектом (со свойствами позиция и методами прорисовки). При попадании в пустую клетку сделать ее отличимой от остальных (например, поставить в ней крест), кроме того не позволять игроку и компьютеру стрелять в нее. На экране отображать поля обоих игроков. Компьютеру задать простую логику: добивать корабль, не стрелять в соседние клетки от затопленного корабля и т.д. На экране отображать счетчик оставшихся кораблей игрока и компьютера.

Этапы решения задания:

1. Проработка необходимых классов для реализации игры
2. Проработка алгоритмов и методов
3. Реализация классов и методов
4. Компоновка приложения
5. Запуск приложения и сбор статистики