#include "factory.h"
#include "elf.h"
#include "bear.h"
#include "rogue.h"
#include <cstdlib>

std::shared_ptr<NPC> Factory::createRandom() {
    int x = rand() % 100;
    int y = rand() % 100;
    int t = rand() % 3;

    if (t == 0) return std::make_shared<Elf>(x, y);
    if (t == 1) return std::make_shared<Bear>(x, y);
    return std::make_shared<Rogue>(x, y);
}
