#include "creature.h"

evo_sim::Creature::Creature(uint16_t init_id)
    : current_location_ {0, 0}
    , id_ {init_id}
{}