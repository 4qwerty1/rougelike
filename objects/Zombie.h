#ifndef ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
#define ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_

#include <iostream>
#include <random>
#include "Character.h"

class Zombie : public Character {
 public:
  Zombie(std::int32_t x, std::int32_t y) {
    hp = 3;
    damage = 1;
    symbol = 'Z';
    location = Point{x, y};
  }
  Point Move() override {
    return location;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
