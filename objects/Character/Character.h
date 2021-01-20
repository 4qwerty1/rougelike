#ifndef ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
#define ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_

#include "../Point.h"

class Dragon;
class Knight;
class Princess;
class Wall;
class Zombie;

class Character {
 protected:
  std::size_t hp;
  std::int32_t damage;
  Point cur_location;
  Point prev_location;
  char symbol;

 public:
  Point GetPos() const;
  std::int32_t X() const;
  std::int32_t Y() const;
  void GoBack();
  std::size_t GetHp() const;
  std::int32_t GetDamage() const;
  char GetSymbol() const;
  virtual Point Move(std::int32_t x, std::int32_t y) = 0;
  virtual bool Fight(Character *character) = 0;
  virtual bool Fight(Knight *knight) = 0;
  virtual bool Fight(Dragon *dragon) = 0;
  virtual bool Fight(Princess *princess) = 0;
  virtual bool Fight(Zombie *zombie) = 0;
  virtual bool Fight(Wall *wall) = 0;
};

#endif //ROUGELIKE_GAME_OBJECTS_CHARACTER_CPP_
