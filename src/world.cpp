#include "world.h"

evo_sim::World::World() {
    creatures_.push_back(Creature{});
    food_locations_.push_back({5, 5});
}