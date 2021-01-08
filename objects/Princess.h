#ifndef ROUGELIKE_GAME_OBJECTS_PRINCESS_H_
#define ROUGELIKE_GAME_OBJECTS_PRINCESS_H_

#include <iostream>
#include "Character.h"

class Princess : Character {
 public:
  Princess(std::int32_t x, std::int32_t y) : Character(x, y) {
    hp = 1;
    damage = 0;
    symbol = 'P';
  }
  Point Move() override {
    return location;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_PRINCESS_H_
