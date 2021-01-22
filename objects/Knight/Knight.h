#ifndef ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
#define ROUGELIKE_GAME_OBJECTS_KNIGHT_H_

#include <iostream>

#include "../Character/Character.h"
#include "../Point.h"


class Knight : public Character {
 public:
  Knight();
  Knight(std::int32_t x, std::int32_t y);
  Point Move(std::int32_t x, std::int32_t y) override;

  bool Collide(Character *character) override;
  bool Collide(Knight *knight) override;
  bool Collide(Dragon *dragon) override;
  bool Collide(Princess *princess) override;
  bool Collide(Wall *wall) override;
  bool Collide(Zombie *zombie) override;
};

#endif //ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
