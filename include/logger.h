#pragma once

#include <memory>

#include "world.h"

namespace evo_sim {

class Logger {
private:
    std::unique_ptr<World> world_;

public:
    Logger(World* world_ref);
    ~Logger() = default;

}; // End class Logger

}; // Endnamespace evo_sim