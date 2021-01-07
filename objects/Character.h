#ifndef ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
#define ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_

#include <iostream>

struct Point {
  std::int32_t x;
  std::int32_t y;
};

class Character {
 private:
  std::size_t hp;
  std::int32_t damage;
  Point location;
  char symbol;
 public:
  virtual Point GetPos() const = 0;
  virtual std::size_t GetHp() const = 0;
  virtual std::int32_t GetDamage() const = 0;
  virtual char GetSymbol() const = 0;
};

#endif //ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
