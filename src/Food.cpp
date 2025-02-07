#include "food.h"

evo_sim::Food::Food() {
    food_pieces_.emplace(std::pair{1, 1}, 0);
    food_pieces_.emplace(std::pair{2, 2}, 0);
    food_pieces_.emplace(std::pair{2, 5}, 0);
    food_pieces_.emplace(std::pair{2, 12}, 0);
}

uint16_t evo_sim::Food::request(point location) {
    if (food_pieces_.count(location) == 0) { return 0; }
    return ++food_pieces_[location];
}

float evo_sim::Food::get_energy(point location, uint16_t id) {
    return energy_;
}