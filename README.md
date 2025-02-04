# About

Evolution Simulator is a just-for-fun project that aims to simulate some of the basic mechanisims of biological evolution.  It is overly simplified and is not a serious scientific simulation.  It aims only to model a few simplified basic points such as expending energy to search for food.

# Build notes

This repo is build on Windows 10 using MIN GW and CMake.  Siply install these dependancies and ensure the appropriate environment varibles have been set, then run the build.bat script from the to level repo directory.

# Structure

## Current State:

The world is a coordinate grid.  Multiple food items and a single creature are placed at hardcoded locations in the world.  The creature will look at all the food within it's sight range and move to the nearest piece of food.  When the creature arrives at the food, it is eaten.

## Next Goals:
1. Add starvation deaths by making creatures expend energy for motion and gain energy from food.  The creature dies when energy hits 0.

1. Define an end state when all creatures are dead.  Replace the hardcoded world state updates with a check on this end state.

1. Add a speed stat to creatures.  The speed is the distance they may travel in a single time period

1. Define interaction when multiple creatures end a time period in the same location.

1. Randomize the start.  This should be the first stage where multiple creatures are searching for multiple food items.

1. Add the first variable features to the creatures.  Moving faster will require more energy, but should allow the creature to get more food.

1. Add an evaluation criterea for which creatures get to reproduce at the end of a time period.

1. Finally add the evolution!  At the end of each simulation, make the next simulation create creatures based on random variants of the previous sim's best creatures