#include "world.h"
#include <iostream>
#include <limits>

int main() {
    try {
        std::cout << "=== LAB 7 - Multithreaded RPG ===\n\n";

        std::cout << "Creating world and NPCs...\n";

        World world;

        std::cout << "Starting simulation (30 seconds)...\n\n";

        world.start();

        std::cout << "\nSimulation finished successfully.\n";
        std::cout << "Dead NPCs were not displayed during simulation.\n";
        std::cout << "Remaining NPCs are survivors.\n";

        std::cout << "\nPress ENTER to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        std::cout << "\nPress ENTER to exit...";
        std::cin.get();
        return 1;
    }

    return 0;
}
