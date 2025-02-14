#pragma once

#include <map>
#include <memory>
#include <optional>
#include <queue>

#include "evo_random.h"
#include "types.h"

namespace evo_sim {

class Food {
private:
    static constexpr float energy_ = 8.0;
    static constexpr uint16_t min_init_food_ = 15;
    static constexpr uint16_t max_init_food_ = 30;
    uint16_t new_food_period_;
    uint16_t new_food_timer_;

    // Key is the food's location in the world.  Value is the number of creatures trying to eat the food.
    std::map<point, uint16_t> food_pieces_;

    std::unique_ptr<Evo_Random> rand_;

    std::queue<point> food_eaten_;

    void remove_eaten_food();

    void create_food(uint16_t count_min, uint16_t count_max);

public:
    Food(Evo_Random* init_rand);
    ~Food() = default;

    // Called when a creature reaches location.  Logs that the creature is trying to eat the food.
    // Returns an ID to be used with get to receive the energy from eating the food.
    // An ID of 0 is returned for invalid requests.
    uint16_t request(point location);

    // Called after all creatures have performed their move. Passed point food is received from andthe ID
    // received from request and returns the amount of energy received from eating the food.  The value
    // of food received decreases for each subsequent request.
    float get_energy(point location, uint16_t id);

    std::optional<point> closest_food(point ref, uint16_t max_visable_disatnce);
    
    bool is_food(point ref);
    void perform_day_actions();
}; // End class Food

}; // End namespace evo_sim