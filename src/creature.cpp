#include <cfloat>
#include <math.h>

#include "evo_math.h"
#include "creature.h"

evo_sim::Creature::Creature(uint16_t init_id, float init_energy, Food* init_food, point init_location)
    : food_ {init_food}
{ }

// evo_sim::Creature::Creature(const Creature& other)
//     : creatures_ {other.creatures_}
//     , food_ {other.food_}
// { }

// evo_sim::Creature::Creature(Creature&& other)
//     : creatures_ {other.creatures_}
//     , food_ {other.food_}
// {
//     other.food_ = nullptr;
// }

void evo_sim::Creature::add_creature(uint16_t id, float init_energy, point init_location) {
    features new_creature_feats = {
        id,
        init_energy,
        8,
        4,
        init_location,
        std::nullopt,
        std::nullopt,
        0
    };

    creatures_.emplace(init_location, new_creature_feats);
}

void evo_sim::Creature::perform_day_actions() {   
    auto iter = creatures_.begin();
    while (iter != creatures_.end()) {
        iter->second.energy -= 1.5; // TODO - make this a function of max_visable_distance_
        iter->second.closest_visable_food = food_->closest_food(
            iter->first,
            iter->second.max_visable_distace
        );
        ++iter;
        //update_location();
    }
}

void evo_sim::Creature::update_energy() {
    energy_ += food_->get_energy(current_location_, food_request_id_);
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
        food_request_id_ = food_->request(next_location_);
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