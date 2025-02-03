#include <algorithm>
#include <iostream>
#include <optional>

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

        std::optional<point> eaten_food = creature.last_food_eaten();
        if (eaten_food == std::nullopt) { continue; }

        food_locations_.erase(
            std::remove(food_locations_.begin(), food_locations_.end(), eaten_food),
            food_locations_.end()
        );
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