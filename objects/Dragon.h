#ifndef ROUGELIKE_GAME_OBJECTS_DRAGON_H_
#define ROUGELIKE_GAME_OBJECTS_DRAGON_H_

#include <iostream>
#include <random>
#include "Character.h"

class Dragon : Character {
 private:
  std::random_device rd;
  std::mt19937 gen;

  Dragon(std::int32_t x, std::int32_t y) : Character(x, y) {
    hp = 5;
    damage = 3;
    symbol = 'D';
  }
  Point Move() override {
    std::uniform_int_distribution<> dist(-2,2);
    location.x += dist(gen);
    location.y += dist(gen);

    return location;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_DRAGON_H_
