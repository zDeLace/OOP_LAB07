#pragma once
#include "npc.h"

class Rogue : public NPC {
public:
    Rogue(int x, int y);
    void accept(Visitor& v, NPC& other) override;
};
