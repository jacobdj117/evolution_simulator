#include <algorithm>
#include <optional>

#include "world.h"

#include <iostream>

evo_sim::World::World()
    : rand_ {{width_, height_}}
    , food_ {}
{
    uint16_t creaure_count = rand_.random_between(min_init_creatures_, max_init_creatures_);
    for (uint16_t i=0; i<creaure_count; i++) {
        creatures_.push_back(Creature{i, 10.0, &food_, rand_.random_point()});
    }
}

void evo_sim::World::update_state() {
    std::cout << "world begin update state" << std::endl;
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
    std::vector<Creature>::iterator iter = creatures_.begin();
    for (iter; iter != creatures_.end(); ) {
        std::cout << "    " << iter->id() << std::endl;
        if (iter->energy() > 0.0) {
            ++iter;
            continue;
        }

        iter = creatures_.erase(iter);
    }
}