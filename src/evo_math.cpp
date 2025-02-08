#include "evo_math.h"

float evo_sim::distance(point a, point b) {
    uint32_t x = pow(a.first - b.first , 2);
    uint32_t y = pow(a.second - b.second, 2);
    return sqrt(x + y);
}