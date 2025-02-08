#ifndef __EVO_MATH_H__
#define __EVO_MATH_H__
#pragma once

#include <math.h>

#include "types.h"

namespace evo_sim {
    float distance(point a, point b) {
        uint32_t x = pow(a.first - b.first , 2);
        uint32_t y = pow(a.second - b.second, 2);
        return sqrt(x + y);
    }
};

#endif