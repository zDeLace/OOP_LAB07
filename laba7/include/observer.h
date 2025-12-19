#pragma once
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onFight(const std::string& msg) = 0;
};
