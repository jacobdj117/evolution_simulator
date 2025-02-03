#include <iostream>

#include "world.h"

int main() {
    evo_sim::World world{};
    
    for (int i=0; i<3; i++) {
        world.update_state();
        world.print_creature_stats();
    }
}