#include <algorithm>
#include <optional>

#include "world.h"

evo_sim::World::World() {
    food_locations_.push_back({1, 1});
    food_locations_.push_back({3, 3});
    food_locations_.push_back({7, 7});
    creatures_.push_back(Creature{0, 10.0, food_locations_});
}

void evo_sim::World::update_state() {
    for (Creature& creature : creatures_) {
        creature.perform_day_actions(food_locations_);

        std::optional<point> eaten_food = creature.last_food_eaten();
        if (eaten_food == std::nullopt) { continue; }

        food_locations_.erase(
            std::remove(food_locations_.begin(), food_locations_.end(), eaten_food),
            food_locations_.end()
        );
    }
}