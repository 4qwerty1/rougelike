#ifndef ROUGELIKE_GAME_OBJECTS_WALL_H_
#define ROUGELIKE_GAME_OBJECTS_WALL_H_

#include <iostream>
#include <random>
#include <limits>
#include "../Character/Character.cpp"

class Wall : public Character {
 public:
  Wall(std::int32_t x, std::int32_t y) {
    hp = std::numeric_limits<std::size_t>::infinity();
    damage = 0;
    symbol = '#';
    cur_location = Point{x, y};
  }
  Point Move(std::int32_t x, std::int32_t y) override {
    return cur_location;
  }
  bool Fight(Character *character) override {
    return character->Fight(this);
  }
  bool Fight(Knight *knight) override {
    return true;
  }
  bool Fight(Dragon *dragon) override {
    return true;
  }
  bool Fight(Princess *princess) override {
    return true;
  }
  bool Fight(Zombie *zombie) override {
    return true;
  }
  bool Fight(Wall *wall) override {
    return true;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_WALL_H_
