#ifndef ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
#define ROUGELIKE_GAME_OBJECTS_KNIGHT_H_

#include "../Character/Character.h"
#include "../Point.h"
#include "../Dragon/Dragon.h"
#include "../Princess/Princess.h"
#include "../Wall/Wall.h"
#include "../Zombie/Zombie.h"

class Knight : public Character {
 public:
  Knight(std::int32_t x, std::int32_t y) {
    hp = 10;
    damage = 3;
    symbol = 'K';
    cur_location = Point{x, y};
  }
  Point Move(std::int32_t x, std::int32_t y) override {
    prev_location = cur_location;
    cur_location.x += y;
    cur_location.y += x;
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
  bool Fight(Wall *wall) override {
    return true;
  }
  bool Fight(Zombie *zombie) override {
    this->hp -= zombie->GetDamage();
    return true;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_KNIGHT_H_
