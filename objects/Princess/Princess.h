#ifndef ROUGELIKE_GAME_OBJECTS_PRINCESS_H_
#define ROUGELIKE_GAME_OBJECTS_PRINCESS_H_

#include <iostream>
#include "../Point.h"
#include "../Character/Character.h"

class Princess : public Character {
 public:
  Princess();
  Princess(std::int32_t x, std::int32_t y);
  Point Move(std::int32_t x, std::int32_t y) override;
  bool Collide(Character *character) override;
  bool Collide(Knight *knight) override;
  bool Collide(Dragon *dragon) override;
  bool Collide(Princess *princess) override;
  bool Collide(Zombie *zombie) override;
  bool Collide(Wall *wall) override;
};

#endif //ROUGELIKE_GAME_OBJECTS_PRINCESS_H_
