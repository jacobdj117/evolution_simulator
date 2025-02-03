#pragma once

#include <vector>

#include "types.h"

namespace evo_sim {

class Creature {
private:
    point current_location_;
    std::vector<point> food_in_sight_;
    uint16_t id_;

public:
    Creature(uint16_t init_id);
    ~Creature() = default;

    uint16_t id()    { return id_; }
    point location() { return current_location_; }
    
}; // End class Creature

}; // End namespace evo_sim