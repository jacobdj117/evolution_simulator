#include <cfloat>
#include <math.h>

#include "food.h"
#include "evo_math.h"

evo_sim::Food::Food() {
    food_pieces_.emplace(std::pair{3, 1}, 0);
    // food_pieces_.emplace(std::pair{2, 2}, 0);
    // food_pieces_.emplace(std::pair{2, 5}, 0);
    // food_pieces_.emplace(std::pair{2, 12}, 0);
}

uint16_t evo_sim::Food::request(point location) {
    if (food_pieces_.count(location) == 0) { return 0; }
    return ++food_pieces_[location];
}

float evo_sim::Food::get_energy(point location, uint16_t id) {
    if (food_pieces_.count(location) == 0) { return 0.0; }

    food_eaten_.push(location);

    if (food_pieces_[location] == 1) { return energy_; }

    uint32_t portions = triangular_number(food_pieces_[location]);
    float portion_size = energy_ / portions;
    return portion_size * (id - (id - 1));
}

std::optional<evo_sim::point> evo_sim::Food::closest_food(point ref, uint16_t max_visable_disatnce) {
    float distance_to_closest_food = FLT_MAX;
    std::optional<point> closest_food = std::nullopt;

    for (const std::pair<point, uint16_t> food : food_pieces_) {
        // Filter food outside visable range
        if (abs(food.first.first - ref.first) > max_visable_disatnce) { continue; }
        if (abs(food.first.second - ref.second) > max_visable_disatnce) { continue; }

        // Get distance to food
        float distance_to_food = distance(food.first, ref);

        // Track closest food
        if (distance_to_food > distance_to_closest_food) { continue; }
        distance_to_closest_food = distance_to_food;
        closest_food = food.first;
    }

    return closest_food;
}

void evo_sim::Food::remove_eaten_food() {
    while (!food_eaten_.empty()) {
        point food = food_eaten_.front();

        if (food_pieces_.count(food) > 0) {
            food_pieces_.erase(food);
        }

        food_eaten_.pop();
    }
}

bool evo_sim::Food::is_food(point ref) {
    return !food_pieces_.count(ref) == 0;
}