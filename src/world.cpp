#include <algorithm>
#include <optional>

#include "world.h"

evo_sim::World::World()
    : rand_ {{width_, height_}}
    , food_ {&rand_}
    , creatures_ {&food_}
{
    uint16_t creaure_count = rand_.random_between(min_init_creatures_, max_init_creatures_);
    for (uint16_t i=0; i<creaure_count; i++) {
        creatures_.add_creature(i, 10.0, rand_.random_point());
    }
}

void evo_sim::World::update_state() {
    creatures_.perform_day_actions();
    food_.perform_day_actions();
}