#include <iostream>

#include "world.h"

evo_sim::World::World() {
    food_locations_.push_back({1, 1});
    food_locations_.push_back({3, 3});
    food_locations_.push_back({7, 7});
    creatures_.push_back(Creature{0, food_locations_});
}

void evo_sim::World::update_state() {
    for (Creature& creature : creatures_) {
        creature.update_visable_food_(food_locations_);
        creature.update_location();
    }
}

void evo_sim::World::print_creature_stats() {
    std::cout << "Creature Stats:\n";
    std::cout << "| ID | location (x, y) | next\n";
    for (Creature creature : creatures_) {
        std::cout << "|  "   << creature.id()
                  << " | " << creature.location().first << ", "   << creature.location().second 
                  << "            |    " << creature.next_location().first << ", " << creature.next_location().second << "\n";
    }
}