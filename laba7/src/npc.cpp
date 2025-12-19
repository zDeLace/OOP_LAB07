#include "npc.h"

NPC::NPC(std::string t, int x, int y, int m, int k, int a, int d)
    : type(t), x(x), y(y), move_dist(m), kill_dist(k), attack(a), defense(d) {}

bool NPC::isAlive() const { return alive; }
void NPC::kill() { alive = false; }

int NPC::getX() const { return x; }
int NPC::getY() const { return y; }
int NPC::getMoveDist() const { return move_dist; }
int NPC::getKillDist() const { return kill_dist; }
int NPC::getAttack() const { return attack; }
int NPC::getDefense() const { return defense; }
std::string NPC::getType() const { return type; }

void NPC::move(int dx, int dy) {
    x += dx;
    y += dy;
}
