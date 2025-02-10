#include <algorithm>
#include <optional>

#include "world.h"

evo_sim::World::World()
    : food_ {}
{
    creatures_.push_back(Creature{0, 10.0, &food_});
}

void evo_sim::World::update_state() {
    // Creature actions
    for (Creature& creature : creatures_) {
        creature.perform_day_actions();
    }

    // Update food
    for (Creature& creature : creatures_) {
        creature.update_energy();
        food_.remove_eaten_food();
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