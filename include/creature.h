#pragma once

#include <vector>

#include "types.h"

namespace evo_sim {

class Creature {
private:
    point current_location_;
    std::vector<point> food_in_sight_;

public:
    Creature();
    ~Creature() = default;
    
}; // End class Creature

}; // End namespace evo_sim