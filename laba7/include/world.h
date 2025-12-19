#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <atomic>

#include "npc.h"
#include "visitor.h"
#include "observer.h"

constexpr int MAP_SIZE = 100;
constexpr int NPC_COUNT = 50;
constexpr int GAME_TIME = 30;

class World {
private:
    std::vector<std::shared_ptr<NPC>> npcs;

    std::shared_mutex npc_mutex;
    std::mutex cout_mutex;

    std::atomic<bool> running{true};

public:
    World();

    void start();
    void stop();

private:
    void movementThread();
    void fightThread();
    void printThread();

    double distance(const NPC& a, const NPC& b);
};
