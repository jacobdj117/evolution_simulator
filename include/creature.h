#pragma once

#include <map>
#include <memory>
#include <optional>

#include "food.h"
#include "types.h"

namespace evo_sim {

class Creature {
public:
    struct features {
        uint16_t id;
        float energy;
        uint16_t max_visable_distance;
        uint16_t speed;
        point next_location;
        std::optional<point> closest_visable_food;
        std::optional<point> last_food_eaten;
        uint16_t food_request_id;
    };

    Creature(uint16_t init_id, float init_energy, Food* init_food, point init_location);
    // Creature(const Creature& other);
    // Creature(Creature&& other);
    ~Creature() = default;

    Creature& operator=(const Creature& other) {
        if (this == &other) { return *this; }

        return *this;
    }

    // bool operator==(const Creature& other) {
    //     return creatures_ == other.creatures_;
    // }

    void add_creature(uint16_t id, float init_energy, point init_location);
    void perform_day_actions();
    
    features creature_at(point location) { return creatures_[location]; }
    uint16_t count() { return creatures_.size(); }

private:
    std::map<point, features> creatures_;
    std::unique_ptr<Food> food_;

    void perform_day_action(point key);
    void move(point key);
    float update_next_location(point key);

}; // End class Creature

}; // End namespace evo_sim