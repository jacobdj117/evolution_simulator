#pragma once

#include <fstream>
#include <memory>
#include <string>

#include "world.h"

namespace evo_sim {

class Logger {
private:
    const std::string file_name_ = "log.txt";

    std::unique_ptr<World> world_;
    std::ofstream file_;

public:
    Logger(World* world_ref);
    ~Logger();

    void log_world_state();

}; // End class Logger

}; // Endnamespace evo_sim