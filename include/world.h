#pragma once

#include <vector>

#include "creature.h"
#include "evo_random.h"
#include "food.h"
#include "types.h"

namespace evo_sim {

class World{
private:
    static constexpr uint16_t width_ = 20;
    static constexpr uint16_t height_ = 20;

    static constexpr uint16_t min_init_creatures_ = 10;
    static constexpr uint16_t max_init_creatures_ = 20;

    Creature creatures_;
    Evo_Random rand_;
    Food food_;

public:

    World();
    ~World() = default;

    void update_state();

    Creature* creatures() { return &creatures_; }
    Food* food()          { return &food_; }
    uint16_t width()      { return width_; }
    uint16_t height()     { return height_; }

}; // End class World

}; // End namespace evo_sim