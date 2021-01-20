#ifndef ROUGELIKE_GAME_OBJECTS_DRAGON_H_
#define ROUGELIKE_GAME_OBJECTS_DRAGON_H_

#include <iostream>
#include <random>
#include "../Character/Character.cpp"

class Dragon : public Character {
 public:
  Dragon(std::int32_t x, std::int32_t y) {
    hp = 5;
    damage = 3;
    symbol = 'D';
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

#endif //ROUGELIKE_GAME_OBJECTS_DRAGON_H_
