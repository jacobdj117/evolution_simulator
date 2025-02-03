#include <iostream>

#include "world.h"

evo_sim::World::World() {
    creatures_.push_back(Creature{0});
    food_locations_.push_back({5, 5});
}

void evo_sim::World::print_creature_stats() {
    std::cout << "Creature Stats:\n";
    std::cout << "| ID | location (x, y)\n";
    for (Creature creature : creatures_) {
        std::cout << "| " << creature.id() << "  | " << creature.location().first << ", " << creature.location().second << "\n";
    }
}