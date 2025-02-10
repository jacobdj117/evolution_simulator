#pragma once

#include <math.h>

#include "types.h"

namespace evo_sim {
    // Returns the distance between two points
    float distance(point a, point b);

    // Returns the summation of an integer and all integrs smaller than it
    uint32_t triangular_number(uint16_t n);
};