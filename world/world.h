#pragma once

#include <vector>

#include "types.h"

namespace evo_sim {

class World{
private:
    static constexpr uint16_t width_ = 20;
    static constexpr uint16_t height_ = 20;

    std::vector<food> food_locations_;

public:

    std::vector<food> get_food() { return food_locations_; }

}; // End class World

}; // End namespace evo_sim