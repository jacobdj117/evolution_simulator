#include <algorithm>
#include <optional>

#include "world.h"

evo_sim::World::World()
    : rand_ {{width_, height_}}
    , food_ {}
{
    uint16_t creaure_count = rand_.random_between(min_init_creatures_, max_init_creatures_);
    for (uint16_t i=0; i<creaure_count; i++) {
        creatures_.add_creature(i, 10.0, rand_.random_point());
    }
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
    std::vector<Creature>::iterator iter = creatures_.begin();
    while (iter < creatures_.end()) {
        if (iter->energy() > 0.0) {
            iter++;
            continue;
        }

        iter = creatures_.erase(iter);
    }
}