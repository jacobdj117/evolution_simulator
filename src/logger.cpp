#include "logger.h"

evo_sim::Logger::Logger(World* world_ref)
    : world_ {world_ref}
    , file_ {file_name_}
{
    if (!file_.is_open()) throw "could not open output file";
}

evo_sim::Logger::~Logger() {
    if (file_.is_open()) file_.close();
}

void evo_sim::Logger::log_world_state() {

}