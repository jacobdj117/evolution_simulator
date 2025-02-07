#pragma once

#include <map>

#include "types.h"

namespace evo_sim {

class Food {
private:
    static constexpr float energy_ = 2.0;

    // Key is the food's location in the world.  Value is the number of creatures trying to eat the food.
    std::map<point, uint16_t> food_pieces_;

public:
    Food();
    ~Food() = default;

    // Called when a creature reaches location.  Logs that the creature is trying to eat the food.
    // Returns an ID to be used with get to receive the energy from eating the food.
    // An ID of 0 is returned for invalid requests.
    uint16_t request(point location);

    // Called after all creatures have performed their move. Passed point food is received from andthe ID
    // received from request and returns the amount of energy received from eating the food. 
    float get_energy(point location, uint16_t id);

}; // End class Food

}; // End namespace evo_sim