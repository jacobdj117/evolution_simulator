#include <math.h>

#include "creature.h"

evo_sim::Creature::Creature(uint16_t init_id, std::vector<point> init_food)
    : id_ {init_id}
    , current_location_ {0, 0}
    , next_location_ {0, 0}
{
    update_visable_food_(init_food);
}

void evo_sim::Creature::update_visable_food_(std::vector<point> all_food) {
    uint16_t distance_to_closest_food = UINT16_MAX;
    const point target_food = current_location_;

    for (point food : all_food) {
        
    }

    next_location_ = target_food;
}