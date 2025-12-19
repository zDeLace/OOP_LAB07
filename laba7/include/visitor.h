#pragma once

class NPC;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void fight(NPC& a, NPC& b) = 0;
};
