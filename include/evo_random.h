#pragma once

#include <random>

#include "types.h"

namespace evo_sim {

class Evo_Random {
private:
    std::random_device device_;
    std::mt19937 gen_;
    point world_end_;

public:
    Evo_Random(point init_world_end);
    ~Evo_Random() = default;

    uint16_t random_between(uint16_t low, uint16_t high);
    float random_between(float low, float high);
    point random_point();

}; // End class Evo_Random

}; // End namespace evo_sim