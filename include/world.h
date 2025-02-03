#pragma once

#include <vector>

#include "creature.h"
#include "types.h"

namespace evo_sim {

class World{
private:
    static constexpr uint16_t width_ = 20;
    static constexpr uint16_t height_ = 20;

    std::vector<Creature> creatures_;
    std::vector<point> food_locations_;

public:

    World();
    ~World() = default;

    std::vector<point> get_food_locations() { return food_locations_; }

}; // End class World

}; // End namespace evo_sim