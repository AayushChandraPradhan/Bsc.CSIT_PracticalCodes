# 7. Write a Program to Implement Monkey Banana Problem using Python.

from typing import Set

class Position:
    def __init__(self, locname="unknown"):
        self.locname = locname

    def __str__(self):
        return self.locname

class HasHeight:
    height: int

class HasPosition:
    at: Position

class Monkey(HasHeight, HasPosition):
    pass

class PalmTree(HasHeight, HasPosition):
    def __init__(self, locname="unknown", *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.height = 2
        self.at = Position(locname)

class Box(HasHeight, HasPosition):
    def __init__(self, locname="unknown", *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.height = 2
        self.at = Position(locname)

class Banana(HasHeight, HasPosition):
    owner: Monkey
    attached: PalmTree

    def __init__(self, locname="unknown", *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.at = Position(locname)

w = {"A", "B", "C"}

p1 = Position("A")
p2 = Position("B")
p3 = Position("C")

m = Monkey()
m.height = 0  # ground
m.at = p1

box = Box()
box.at = p2

p = PalmTree()
p.at = p3

b = Banana()
b.attached = p

actions = [
    lambda: m.at == p1 and m.height == 0 and go(m, p2),
    lambda: m.at == p2 and m.height == 0 and push(m, box, p3),
    lambda: m.at == p3 and m.height == 0 and climb_up(m, box),
    lambda: m.at == p3 and m.height == 2 and grasp(m, b)
]

def go(monkey: Monkey, where: Position):
    monkey.at = where
    return f"Monkey moved to {where}"

def push(monkey: Monkey, box: Box, where: Position):
    monkey.at = where
    box.at = where
    return f"Monkey moved box to {where}"

def climb_up(monkey: Monkey, box: Box):
    monkey.height += box.height
    return "Monkey climbs the box"

def grasp(monkey: Monkey, banana: Banana):
    banana.owner = monkey
    return "Monkey takes the banana"

for action in actions:
    print(action())