#include "Zombie.h"
#include "../Knight/Knight.h"
#include "../Dragon/Dragon.h"
#include "../Princess/Princess.h"
#include "../Wall/Wall.h"
#include "../../Config/Config.h"



Zombie::Zombie() {
  Config conf("config.json");
  hp = conf.Get<std::int32_t>("Zombie", "hp");
  damage = conf.Get<std::int32_t>("Zombie", "damage");
  symbol = conf.Get<std::string>("Zombie", "symbol")[0];
  priority = conf.Get<std::int32_t>("Zombie", "priority");
  vision = conf.Get<std::int32_t>("Zombie", "vision");
}
Zombie::Zombie(int32_t x, int32_t y) : Zombie() {
  cur_location = Point{x, y};
  prev_location = cur_location;
}
Point Zombie::Move(int32_t x, int32_t y) {
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

bool Zombie::Collide(Character *character) {
  return character->Collide(this);
}
bool Zombie::Collide(Knight *knight) {
  this->hp -= knight->Damage();
  knight->TakeDamage(this->damage);
  return true;
}
bool Zombie::Collide(Dragon *dragon) {
  (cur_location == prev_location) ? dragon->GoBack() : this->GoBack();
  return true;
}
bool Zombie::Collide(Princess *princess) {
  GoBack();
  return true;
}
bool Zombie::Collide(Zombie *zombie) {
  (cur_location == prev_location) ? zombie->GoBack() : this->GoBack();
  return true;
}
bool Zombie::Collide(Wall *wall) {
  GoBack();
  return true;
}

bool Zombie::isInView(Point &vector) const {
  std::int32_t x = std::abs(vector.x);
  std::int32_t y = std::abs(vector.y);

  return x * x + y * y <= vision * vision;
}