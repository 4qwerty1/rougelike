#ifndef ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
#define ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_

#include <iostream>
#include "../Character/Character.h"
#include "../Point.h"


class Zombie : public Character {
 private:
  std::int32_t vision;
  bool isInView(Point &vector) const;
 public:
  Zombie();
  Zombie(std::int32_t x, std::int32_t y);
  Point Move(std::int32_t x, std::int32_t y) override;

  bool Collide(Character *character) override;
  bool Collide(Knight *knight) override;
  bool Collide(Dragon *dragon) override;
  bool Collide(Princess *princess) override;
  bool Collide(Zombie *zombie) override;
  bool Collide(Wall *wall) override;
};

#endif //ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
