#include "observer.h"
#include <iostream>

class ConsoleObserver : public Observer {
public:
    void onFight(const std::string& msg) override {
        std::cout << msg << std::endl;
    }
};
