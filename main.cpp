#include "logger.h"
#include "world.h"

int main() {
    evo_sim::World world{};
    evo_sim::Logger logger(&world);
    
    logger.log_world_state();
    for (int i=0; i<3; i++) {
        world.update_state();
        logger.log_world_state();
    }
}