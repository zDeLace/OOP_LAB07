#pragma once
#include <memory>
#include "npc.h"

class Factory {
public:
    static std::shared_ptr<NPC> createRandom();
};
