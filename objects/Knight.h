#ifndef ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
#define ROUGELIKE_GAME_OBJECTS_KNIGHT_H_

#include <iostream>
#include "Character.h"

class Knight : Character {
 public:
  Knight(std::int32_t x, std::int32_t y) : Character(x, y) {
    hp = 10;
    damage = 3;
    symbol = 'K';
  }
  Point Move() {
    location.y += 1;
    return location;
  }
  // todo write MoveDown, MoveLeft, MoveRight
};

#endif //ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
