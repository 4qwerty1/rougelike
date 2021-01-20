#ifndef ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
#define ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_

#include "../Character/Character.cpp"
#include "../Knight/Knight.h"
#include "../Point.h"
#include "../Dragon/Dragon.h"
#include "../Princess/Princess.h"
#include "../Wall/Wall.h"

class Zombie : public Character {
 private:
  bool isInView(Point &vector) const {
    if (vector.x == 0 || std::abs(vector.x) == 1) return std::abs(vector.y) <= 3;
    if (vector.y == 0 || std::abs(vector.y) == 1) return std::abs(vector.x) <= 3;
    return std::abs(vector.x * vector.y) <= 9;
  }
 public:
  Zombie(std::int32_t x, std::int32_t y) {
    hp = 3;
    damage = 1;
    symbol = 'Z';
    cur_location = Point{x, y};
  }
  Point Move(std::int32_t x, std::int32_t y) override {
    if (x == cur_location.x && y == cur_location.y) return cur_location;
    Point vector{x - this->X(), y - this->Y()};
    if (!isInView(vector)) return cur_location;  // область видимости

    prev_location = cur_location;
    if (std::abs(vector.x) > std::abs(vector.y)) {
      std::int32_t step = (vector.x < 0) ? -1 : 1;
      cur_location.x += step;
      return cur_location;
    }

    std::int32_t step = (vector.y < 0) ? -1 : 1;
    cur_location.y += step;
    return cur_location;
  }

  bool Fight(Character *character) override {
    return character->Fight(this);
  }
  bool Fight(Knight *knight) override {
    this->hp -= knight->GetDamage();
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

#endif //ROUGELIKE_GAME_OBJECTS_ZOMBIE_H_
