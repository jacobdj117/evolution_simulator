#pragma once

#include <optional>
#include <vector>

#include "types.h"

namespace evo_sim {

class Creature {
private:
    const uint16_t max_visable_distace_ = 5;

    point current_location_;
    point next_location_;

    uint16_t id_;
    float energy_;
    std::vector<point> visable_food_;
    point closest_visable_food_;
    std::optional<point> last_food_eaten_;

    void update_visable_food(std::vector<point> all_food);
    void update_location();

public:
    Creature(uint16_t init_id, std::vector<point> init_food);
    ~Creature() = default;

    std::optional<point> last_food_eaten();
    void perform_day_actions(std::vector<point> all_food);
    
    uint16_t id()         { return id_; }
    point location()      { return current_location_; }
    point next_location() { return next_location_; }
    
}; // End class Creature

}; // End namespace evo_sim