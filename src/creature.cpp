#include <cfloat>
#include <math.h>

#include "evo_math.h"
#include "creature.h"

evo_sim::Creature::Creature(Food* init_food)
    : food_ {init_food}
{ }

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
    for (std::pair<point, features> creature : creatures_) {
        perform_day_action(creature.first);
    }
    clean();

    update_energy();
    clean();
}

void evo_sim::Creature::perform_day_action(point key) {
    creatures_[key].energy -= 1.5; // TODO - make this a function of max_visable_distance_
    creatures_[key].closest_visable_food = food_->closest_food(
        key,
        creatures_[key].max_visable_distance
    );

    move(key);
}

void evo_sim::Creature::update_energy() {
    for (std::pair<point, features> creature : creatures_) {
        point key = creature.first;
        uint16_t id = creature.second.food_request_id;
        if (id == 0) { continue; }

        float energy = food_->get_energy(creature.first, id);
        creatures_[key].energy -= energy;

        if (creatures_[key].energy <= 0.0) {
            to_erase_.push(key);
        }
    }
}

void evo_sim::Creature::move(point key) {
    update_next_location(key);
    
    float distance_traveled = update_next_location(key);
    if (distance_traveled == 0.0) { return; }

    creatures_[key].energy -= 0.5 * distance_traveled;
    
    creatures_.emplace(creatures_[key].next_location, creatures_[key]);
    to_erase_.push(key);
}

float evo_sim::Creature::update_next_location(point key) {
    if (!creatures_[key].closest_visable_food.has_value()) { 
        creatures_[key].next_location = key;
        creatures_[key].food_request_id = 0;
        return 0.0;
    }

    const point target_food = creatures_[key].closest_visable_food.value();
    const uint16_t speed = creatures_[key].speed;
    const float distance_to_food = distance(key, target_food);

    if (distance_to_food > static_cast<float>(speed)) {
        uint16_t x_dif = target_food.first - key.first;
        uint16_t y_dif = target_food.second - key.second;
        float distance_ratio = speed / distance_to_food;
        creatures_[key].next_location.first = key.first + (x_dif * distance_ratio);
        creatures_[key].next_location.second = key.second + (y_dif * distance_ratio);
        creatures_[key].food_request_id = 0;
    } else {
        creatures_[key].next_location = target_food;
        creatures_[key].food_request_id = food_->request(creatures_[key].next_location);
    }

    return distance(key, creatures_[key].next_location);
}

void evo_sim::Creature::clean() {
    while (!to_erase_.empty()) {
        creatures_.erase(to_erase_.front());
        to_erase_.pop();
    }
}