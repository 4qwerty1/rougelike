#ifndef ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
#define ROUGELIKE_GAME_OBJECTS_KNIGHT_H_

#include <iostream>
#include "Character.h"

class Knight : public Character {
 public:
  Knight(std::int32_t x, std::int32_t y) {
    hp = 10;
    damage = 3;
    symbol = 'K';
    location = Point{x, y};
  }
  Point Move() {
    location.y += 1;
    return location;
  }
  // todo write MoveDown, MoveLeft, MoveRight
};

#endif //ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
