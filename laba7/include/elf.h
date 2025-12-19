#pragma once
#include "npc.h"

class Elf : public NPC {
public:
    Elf(int x, int y);
    void accept(Visitor& v, NPC& other) override;
};
