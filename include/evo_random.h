#pragma once

#include <random>

#include "types.h"

namespace evo_sim {

class Evo_Random {
private:
    
public:
    Evo_Random();
    Evo_Random(int init_seed);
    ~Evo_Random() = default;

    point random_point();

}; // End class Evo_Random

}; // End namespace evo_sim