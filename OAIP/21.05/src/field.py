__FIELD_SIZE__ = 10

class Cell():
    empty: bool = True
    bombed: bool = False


class Field():
    cells: list[list[Cell]]

    def __init__(self) -> None:
        cells = []
        for i in 0..__FIELD_SIZE__:
            cells.append([])
            for j in 0..__FIELD_SIZE__:
                cells[i].append(Cell())

        

class Ship():
    length: int

    def __init__(self, length: int) -> None:
        self.length = length

    def put(field: Field):
        ...

SHIPS = [
    Ship(4),

    Ship(3),
    Ship(3),

    Ship(2),
    Ship(2),
    Ship(2),

    Ship(1),
    Ship(1),
    Ship(1),
    Ship(1),
]
