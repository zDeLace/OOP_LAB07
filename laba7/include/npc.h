#pragma once
#include <string>

class Visitor;

class NPC {
protected:
    std::string type;
    int x{}, y{};
    int move_dist{};
    int kill_dist{};
    int attack{};
    int defense{};
    bool alive{true};

public:
    NPC(std::string t, int x, int y,
        int m, int k, int a, int d);

    virtual ~NPC() = default;

    virtual void accept(Visitor& v, NPC& other) = 0;

    bool isAlive() const;
    void kill();

    int getX() const;
    int getY() const;
    int getMoveDist() const;
    int getKillDist() const;
    int getAttack() const;
    int getDefense() const;
    std::string getType() const;

    void move(int dx, int dy);
};
