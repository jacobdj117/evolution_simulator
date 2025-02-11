#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "food.h"
#include "types.h"

namespace evo_sim {

class Creature {
private:
    const uint16_t max_visable_distace_ = 10;
    const uint16_t speed_ = 4;

    uint16_t id_;
    float energy_;
    point current_location_;
    point next_location_;
    Food* food_;
    std::optional<point> closest_visable_food_;
    std::optional<point> last_food_eaten_;
    uint16_t food_request_id_;

    void update_location();

public:
    Creature(uint16_t init_id, float init_energy, Food* init_food, point init_location);
    Creature(const Creature& other);
    Creature(Creature&& other);
    ~Creature() = default;

    Creature& operator=(const Creature& other) {
        if (this == &other) { return *this; }

        return *this;
    }

    bool operator==(const Creature& other) {
        if (id_ != other.id_) { return false; }
        if (energy_ != other.energy_) { return false; }
        if (current_location_ != other.current_location_) { return false; }

        return true;
    }

    std::optional<point> last_food_eaten();
    void perform_day_actions();
    void update_energy();
    
    uint16_t id()         { return id_; }
    float energy()        { return energy_; }
    point location()      { return current_location_; }
    point next_location() { return next_location_; }
    
}; // End class Creature

}; // End namespace evo_sim