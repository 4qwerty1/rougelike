#ifndef ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
#define ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_

#include <iostream>
#include "../Point.h"


class Dragon;
class Knight;
class Princess;
class Wall;
class Zombie;

class Character {
 protected:
  std::int32_t hp;
  std::int32_t damage;
  Point cur_location;
  Point prev_location;
  char symbol;
  std::size_t priority;

 public:
  Point GetPos() const;
  std::int32_t X() const;
  std::int32_t Y() const;
  void GoBack();
  std::int32_t Hp() const;
  std::int32_t Damage() const;
  std::size_t Priority() const;
  void TakeDamage(std::int32_t x);
  char Symbol() const;
  virtual Point Move(std::int32_t x, std::int32_t y) = 0;
  virtual bool Collide(Character *character) = 0;
  virtual bool Collide(Knight *knight) = 0;
  virtual bool Collide(Dragon *dragon) = 0;
  virtual bool Collide(Princess *princess) = 0;
  virtual bool Collide(Zombie *zombie) = 0;
  virtual bool Collide(Wall *wall) = 0;
};

#endif //ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
