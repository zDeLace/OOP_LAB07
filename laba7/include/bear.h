#pragma once
#include "npc.h"

class Bear : public NPC {
public:
    Bear(int x, int y);
    void accept(Visitor& v, NPC& other) override;
};
