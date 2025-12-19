#include "bear.h"
#include "visitor.h"

Bear::Bear(int x, int y)
    : NPC("Bear", x, y,
          5,    // ход
          10,   // убийство
          4,    // атака
          2) {} // защита

void Bear::accept(Visitor& v, NPC& other) {
    v.fight(*this, other);
}
