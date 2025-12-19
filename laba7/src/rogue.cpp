#include "rogue.h"
#include "visitor.h"

Rogue::Rogue(int x, int y)
    : NPC("Rogue", x, y,
          10,   // ход
          10,   // убийство
          3,    // атака
          2) {} // защита

void Rogue::accept(Visitor& v, NPC& other) {
    v.fight(*this, other);
}
