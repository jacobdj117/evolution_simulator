#include <cfloat>
#include <math.h>

#include "creature.h"

#include <iostream>

evo_sim::Creature::Creature(uint16_t init_id, std::vector<point> init_food)
    : id_ {init_id}
    , current_location_ {0, 0}
    , next_location_ {0, 0}
{
    update_visable_food_(init_food);
}

void evo_sim::Creature::update_visable_food_(std::vector<point> all_food) {
    float distance_to_closest_food = FLT_MAX;
    const point target_food = current_location_;

    next_location_ = current_location_;

    for (point food : all_food) {
        // Filter food outside visable range
        if (abs(food.first - current_location_.first) > max_visable_distace_) { continue; }
        if (abs(food.second - current_location_.second) > max_visable_distace_) { continue; }

        // Get distance to food
        uint16_t x = pow(food.first - current_location_.first , 2);
        uint16_t y = pow(food.second - current_location_.second, 2);
        float distance = sqrt(x + y);

        // Track closest food
        if (distance > distance_to_closest_food) { continue; }
        distance_to_closest_food = distance;
        next_location_.first = food.first;
        next_location_.second = food.second;
    }
}