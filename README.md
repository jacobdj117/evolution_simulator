# Requirements

CMake
MIN GW

# Structure

## Current goal:

The world is a coordinate grid.  Food and createures exist in the world.  Creatures can see food and move towards the food.  When the creature is in the same grid locatino as the food, the food is eaten.

The World Object maintains an array of locations that contain food.  Creatures can request food locations from the world.  The creatures will then move towards the nearest food.

## Next Goals:
1. Creatures have a maximum sight distance that will be passed to the world with the food requests.  The world will only provide food within the line of sight.

1. The world state will be repeatedly updated.  Each update is called a tick.  This will cause a creature to visit multiple foods

1. The creature will visit a random coordinate if no food is in view

1. The world will exist over multiple days, with each day ending after either a set number of ticks, or all the food being eaten.

1. features to come - the creatures reproduce or die at the end of each day