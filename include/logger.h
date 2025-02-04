#pragma once

#include <fstream>
#include <memory>
#include <string>

#include "world.h"

namespace evo_sim {

class Logger {
private:
    const std::string file_name_ = "log.txt";

    uint16_t count_;
    std::ofstream file_;
    std::unique_ptr<World> world_;

    void log_point(uint16_t x, uint16_t y);

public:
    Logger(World* world_ref);
    ~Logger();

    void log_world_state();

}; // End class Logger

}; // Endnamespace evo_sim