# About

Evolution Simulator is a just-for-fun project that aims to simulate some of the basic mechanisims of biological evolution.  It is overly simplified and is not a serious scientific simulation.  It aims only to model a few simplified basic points such as expending energy to search for food.

# Build notes

This repo is build on Windows 10 using MIN GW and CMake.  Siply install these dependancies and ensure the appropriate environment varibles have been set, then run the build.bat script from the to level repo directory.

# Structure

## Current State:

The world is a coordinate grid.  Multiple food items and a single creature are placed at hardcoded locations in the world.  The creature will look at all the food within it's sight range and move to the nearest piece of food.  When the creature arrives at the food, it is eaten.

Eating food provides energy to creatures.  Each creature incurs a daily energy cost and expends energy to move.  When a creature's energy falls below 0, it dies.

## Next Goals:

1. Randomize the start.  This should be the first stage where multiple creatures are searching for multiple food items.

1. Add the first variable features to the creatures.  Moving faster will require more energy, but should allow the creature to get more food.

1. Add the second variable trait to the creatures.  A higher vision distance increases the daily energy cost.

1. Add reproduction and evolution - add an energy cost to reproduce, and split the creature while randomly adjusting the movement speed and vision distance traits.

1. Allow a creature to continue moving after it has eaten if it has not used all of its speed