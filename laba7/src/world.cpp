#include "world.h"
#include "factory.h"
#include <thread>
#include <cmath>
#include <iostream>
#include <chrono>
#include <algorithm>

World::World() {
    for (int i = 0; i < NPC_COUNT; ++i)
        npcs.push_back(Factory::createRandom());
}

double World::distance(const NPC& a, const NPC& b) {
    int dx = a.getX() - b.getX();
    int dy = a.getY() - b.getY();
    return std::sqrt(dx * dx + dy * dy);
}

void World::movementThread() {
    while (running) {
        std::unique_lock lock(npc_mutex);
        for (auto& n : npcs) {
            if (!n->isAlive()) continue;
            n->move(rand() % 3 - 1, rand() % 3 - 1);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void World::fightThread() {
    while (running) {
        std::unique_lock lock(npc_mutex);
        for (size_t i = 0; i < npcs.size(); ++i)
            for (size_t j = i + 1; j < npcs.size(); ++j)
                if (npcs[i]->isAlive() && npcs[j]->isAlive() &&
                    distance(*npcs[i], *npcs[j]) <= npcs[i]->getKillDist())
                    npcs[j]->kill();

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

void World::printThread() {
    while (running) {
        std::shared_lock lock(npc_mutex);
        std::lock_guard out(cout_mutex);

        system("cls");
        for (auto& n : npcs)
            if (n->isAlive())
                std::cout << n->getType()
                          << " (" << n->getX() << "," << n->getY() << ")\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void World::start() {
    std::thread t1(&World::movementThread, this);
    std::thread t2(&World::fightThread, this);
    std::thread t3(&World::printThread, this);

    std::this_thread::sleep_for(std::chrono::seconds(GAME_TIME));
    running = false;

    t1.join(); t2.join(); t3.join();
}
