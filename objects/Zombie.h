#ifndef ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
#define ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_

#include <iostream>
#include <random>
#include "Character.h"

class Zombie : Character {
 private:
  std::random_device rd;
  std::mt19937 gen;

  Zombie(std::int32_t x, std::int32_t y) : Character(x, y) {
    hp = 3;
    damage = 1;
    symbol = 'Z';

    gen = std::mt19937(rd());
  }
  Point Move() override {
    std::uniform_int_distribution<> dist(-1,1);
    location.x += dist(gen);
    location.y += dist(gen);

    return location;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
