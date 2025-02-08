#include <cfloat>
#include <math.h>

//#include "evo_math.h"
#include "creature.h"

evo_sim::Creature::Creature(uint16_t init_id, float init_energy, Food* init_food)
    : id_ {init_id}
    , energy_ {init_energy}
    , food_ {init_food}
    , current_location_ {0, 0}
    , next_location_ {0, 0}
    , last_food_eaten_ {std::nullopt}
    , closest_visable_food_ {food_->closest_food(current_location_, max_visable_distace_)}
{ }

void evo_sim::Creature::perform_day_actions() {    
    energy_ -= 1.5; // TODO - make this a function of max_visable_distance_
    closest_visable_food_ = food_->closest_food(current_location_, max_visable_distace_);
    update_location();
}

float distance(evo_sim::point a, evo_sim::point b) {
    uint32_t x = pow(a.first - b.first , 2);
    uint32_t y = pow(a.second - b.second, 2);
    return sqrt(x + y);
}

void evo_sim::Creature::update_location() {
    // Calculate next location
    if (!closest_visable_food_.has_value()) { return; }

    float distance_to_food = distance(current_location_, closest_visable_food_.value());
    if (distance_to_food > static_cast<float>(speed_)) {
        uint16_t x_dif = closest_visable_food_->first - current_location_.first;
        uint16_t y_dif = closest_visable_food_->second - current_location_.second;
        float distance_ratio = speed_ / distance_to_food;
        next_location_.first = current_location_.first + (x_dif * distance_ratio);
        next_location_.second = current_location_.second + (y_dif * distance_ratio);
    } else {
        next_location_ = closest_visable_food_.value();
    }

    // Energy cost for moving
    float distance_traveled = distance(current_location_, next_location_);
    energy_ -= 0.5 * distance_traveled;
    
    current_location_ = next_location_;

    // Energy gain if new location is food
    if (current_location_ == closest_visable_food_) {
        last_food_eaten_ = closest_visable_food_;
        energy_ += 1;
    }
}

std::optional<evo_sim::point> evo_sim::Creature::last_food_eaten() {
    if (!last_food_eaten_.has_value()) { return std::nullopt; }
    evo_sim::point food = last_food_eaten_.value();
    last_food_eaten_ = std::nullopt;
    return food;
}