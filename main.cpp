#include "creature.h"
#include "logger.h"
#include "world.h"

int main() {
    evo_sim::World world{};
    evo_sim::Logger logger(&world);

    logger.log_world_state();

    uint16_t iterations {0};

    while (world.creatures()->count() > 0) {
        world.update_state();
        logger.log_world_state();

        if (++iterations >= 2000) break;
    }
}