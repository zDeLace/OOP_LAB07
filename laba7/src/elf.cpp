#include "elf.h"
#include "visitor.h"

Elf::Elf(int x, int y)
    : NPC("Elf", x, y,
          10,   // расстояние хода
          50,   // расстояние убийства
          3,    // атака
          1) {} // защита

void Elf::accept(Visitor& v, NPC& other) {
    v.fight(*this, other);
}
