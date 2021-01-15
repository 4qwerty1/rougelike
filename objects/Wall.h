#ifndef ROUGELIKE_GAME_OBJECTS_WALL_H_
#define ROUGELIKE_GAME_OBJECTS_WALL_H_

#include <iostream>
#include <random>
#include <limits>
#include "Character.h"

class Wall : public Character {
 public:
  Wall(std::int32_t x, std::int32_t y) {
    hp = std::numeric_limits<std::size_t>::infinity();
    damage = 0;
    symbol = '#';
    location = Point{x, y};
  }
  Point Move() override {
    return location;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_WALL_H_
