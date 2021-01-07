#ifndef ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
#define ROUGELIKE_GAME_OBJECTS_KNIGHT_H_

#include <iostream>
#include "Character.h"

class Knight : Character {
 public:
  Knight() {
    hp = 10;
    damage = 3;
    location = Point{0, 0}; //todo random location
    symbol = 'K';
  }
  Point MoveUp() {
    location.y + 1;
    return location;
  }
  // todo write MoveDown, MoveLeft, MoveRight
};

#endif //ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
