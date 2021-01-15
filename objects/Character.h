#ifndef ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
#define ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_

#include <iostream>

struct Point {
  std::int32_t x;
  std::int32_t y;
};

class Character {
 protected:
  std::size_t hp;
  std::int32_t damage;
  Point location;
  char symbol;

 public:
  Point GetPos() const { return location; }
  std::size_t GetHp() const { return hp; }
  std::int32_t GetDamage() const { return damage; }
  char GetSymbol() const { return symbol; }
  virtual Point Move() = 0;
};

#endif //ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
