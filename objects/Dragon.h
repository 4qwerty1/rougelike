#ifndef ROUGELIKE_GAME_OBJECTS_DRAGON_H_
#define ROUGELIKE_GAME_OBJECTS_DRAGON_H_

#include <iostream>
#include <random>
#include "Character.h"

class Dragon : public Character {
 public:
  Dragon(std::int32_t x, std::int32_t y) {
    hp = 5;
    damage = 3;
    symbol = 'D';
    location = Point{x, y};
  }
  Point Move() override {
    return location;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_DRAGON_H_
