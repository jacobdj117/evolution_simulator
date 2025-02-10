#include <algorithm>
#include <optional>

#include "world.h"

#include <iostream>

evo_sim::World::World()
    : rand_ {{width_, height_}}
    , food_ {}
{
    std::cout << "world ctor" << std::endl;
    uint16_t creaure_count = rand_.random_between(min_init_creatures_, max_init_creatures_);
    for (int i=0; i<creaure_count; i++) {
        creatures_.push_back(Creature{i, 10.0, &food_, rand_.random_point()});
    }
    std::cout << "end world ctor with " << creatures_.size() << std::endl;
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