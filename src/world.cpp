#include <algorithm>
#include <optional>

#include "world.h"

evo_sim::World::World() {
    food_locations_.push_back({1, 1});
    food_locations_.push_back({2, 2});
    food_locations_.push_back({2, 5});
    food_locations_.push_back({2, 12});
    creatures_.push_back(Creature{0, 10.0, food_locations_});
}

void evo_sim::World::update_state() {
    // Creature actions
    for (Creature& creature : creatures_) {
        creature.perform_day_actions(food_locations_);

        std::optional<point> eaten_food = creature.last_food_eaten();
        if (eaten_food == std::nullopt) { continue; }

        food_locations_.erase(
            std::remove(food_locations_.begin(), food_locations_.end(), eaten_food),
            food_locations_.end()
        );
    }

    // Remove dead creatures
    uint16_t index = 0;
    while (index < creatures_.size()) {
        if (creatures_[index].energy() > 0.0) {
            ++index;
            continue;
        }

        creatures_.erase(creatures_.begin() + index);
    }
}