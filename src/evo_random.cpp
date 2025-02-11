#include "evo_random.h"

evo_sim::Evo_Random::Evo_Random(point init_world_end)
    : device_ {}
    , gen_ {device_()}
    , world_end_ {init_world_end}
{}

uint16_t evo_sim::Evo_Random::random_between(uint16_t low, uint16_t high) {
    std::uniform_int_distribution<> distrib(low, high);
    return distrib(gen_);
}

float evo_sim::Evo_Random::random_between(float low, float high) {
    std::uniform_real_distribution<> distrib(low, high);
    return distrib(gen_);
}

evo_sim::point evo_sim::Evo_Random::random_point() {
    uint16_t x = random_between(0, world_end_.first);
    uint16_t y = random_between(0, world_end_.second);
    return {x, y};
}