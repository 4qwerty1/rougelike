#include "Dragon.h"
#include "../../Config/Config.h"
#include "../Knight/Knight.h"
#include "../Princess/Princess.h"
#include "../Wall/Wall.h"
#include "../Zombie/Zombie.h"

Dragon::Dragon() {
  Config conf("config.json");
  hp = conf.Get<std::int32_t>("Dragon", "hp");
  damage = conf.Get<std::int32_t>("Dragon", "damage");
  symbol = conf.Get<std::string>("Dragon", "symbol")[0];
  priority = conf.Get<std::int32_t>("Dragon", "priority");
  vision = conf.Get<std::int32_t>("Dragon", "vision");
}
Dragon::Dragon(std::int32_t x, std::int32_t y) : Dragon() {
  cur_location = Point{x, y};
  prev_location = cur_location;
}
Point Dragon::Move(std::int32_t x, std::int32_t y) {
  if (x == cur_location.x && y == cur_location.y) return cur_location;
  Point vector{x - this->X(), y - this->Y()};
  if (!IsInView(vector)) return cur_location;  // область видимости

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

bool Dragon::Collide(Character *character) {
  return true;
}
bool Dragon::Collide(Knight *knight) {
  this->hp -= knight->Damage();
  knight->TakeDamage(this->damage);
  return true;
}
bool Dragon::Collide(Dragon *dragon) {
  (cur_location == prev_location) ? dragon->GoBack() : this->GoBack();
  return true;
}
bool Dragon::Collide(Princess *princess) {
  GoBack();
  return true;
}
bool Dragon::Collide(Zombie *zombie) {
  (cur_location == prev_location) ? zombie->GoBack() : this->GoBack();
  return true;
}
bool Dragon::Collide(Wall *wall) {
  GoBack();
  return true;
}

bool Dragon::IsInView(Point &vector) const {
  std::int32_t x = std::abs(vector.x);
  std::int32_t y = std::abs(vector.y);

  return x * x + y * y <= vision * vision;
}
