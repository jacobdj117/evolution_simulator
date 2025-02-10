#include "creature.h"
#include "logger.h"
#include "world.h"

int main() {
    evo_sim::World world{};
    evo_sim::Logger logger(&world);

    logger.log_world_state();
    while (world.creatures().size() > 0) {
        world.update_state();
        logger.log_world_state();
    }
}