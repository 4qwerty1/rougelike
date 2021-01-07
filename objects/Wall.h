#ifndef ROUGELIKE_GAME_OBJECTS_WALL_H_
#define ROUGELIKE_GAME_OBJECTS_WALL_H_

#include <iostream>
#include <random>
#include <limits>
#include "Character.h"

class Wall : Character {
  Wall() {
    hp = std::numeric_limits<std::size_t>::infinity();
    damage = 0;
    location = {3, 4};  // todo random location
    symbol = '#';
  }
  Point Move() override {
    return location;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_WALL_H_
