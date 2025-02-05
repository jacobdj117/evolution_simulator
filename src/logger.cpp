#include "creature.h"
#include "logger.h"

evo_sim::Logger::Logger(World* world_ref)
    : count_ {0}
    , world_ {world_ref}
    , file_ {file_name_}
{
    if (!file_.is_open()) throw "could not open output file";
}

evo_sim::Logger::~Logger() {
    if (file_.is_open()) file_.close();
}

void evo_sim::Logger::log_world_state() {
    file_ << "Time increment " << count_++ << ":\n";

    for (int y=0; y<world_->height(); y++) {
        for (int x=0; x<world_->width(); x++) {
            log_point(x, y);
        }
        file_ << "\n";
    }

    while (!creature_stats_.empty()) {
        std::string next = creature_stats_.front();
        creature_stats_.pop();
        file_ << next << "\n";
    }

    file_ << "\n\n";
}

void evo_sim::Logger::log_point(uint16_t x, uint16_t y) {
    for (Creature creature : world_->creatures()) {
        if (creature.location().first != x) { continue; }
        if (creature.location().second != y) { continue; }

        std::string creature_status = {
            "Creature " + std::to_string(creature.id()) +
            " | location: " + std::to_string( creature.location().first) + 
            "," + std::to_string(creature.location().second) +
            " | energy: " + std::to_string(creature.energy()) +
            " | target location: " + std::to_string(creature.next_location().first) +
            "," + std::to_string(creature.next_location().second)
        };

        creature_stats_.push(creature_status);
        file_ << creature.id() << " ";
        return;
    }

    for (point food : world_->food_locations()) {
        if (food.first != x) { continue; }
        if (food.second != y) { continue; }

        file_ << "f ";
        return;
    }

    file_ << ". ";
}