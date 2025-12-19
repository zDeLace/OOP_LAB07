#include "visitor.h"
#include "npc.h"
#include <random>

class BattleVisitor : public Visitor {
public:
    void fight(NPC& a, NPC& b) override {
        int rollA = rand() % 6 + 1 + a.getAttack();
        int rollB = rand() % 6 + 1 + b.getAttack();

        if (rollA > rollB) b.kill();
        else if (rollB > rollA) a.kill();
    }
};
