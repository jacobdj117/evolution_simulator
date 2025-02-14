#pragma once

#include <map>
#include <memory>
#include <optional>
#include <queue>

#include "food.h"
#include "types.h"

namespace evo_sim {

class Creature {
public:
    struct features {
        uint16_t id;
        float energy;
        uint16_t max_visable_distance;
        uint16_t speed;
        point next_location;
        std::optional<point> closest_visable_food;
        std::optional<point> last_food_eaten;
        uint16_t food_request_id;
    };

    Creature(Food* init_food);
    ~Creature() = default;

    void add_creature(uint16_t id, float init_energy, point init_location);
    void perform_day_actions();
    
    std::optional<features> creature_at(point location);
    uint16_t count() { return creatures_.size(); }

private:
    std::map<point, features> creatures_;
    std::unique_ptr<Food> food_;
    std::queue<point> to_erase_;

    void perform_day_action(point key);
    void move(point key);
    float update_next_location(point key);
    void update_energy();
    void clean();

}; // End class Creature

}; // End namespace evo_sim