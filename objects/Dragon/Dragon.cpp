#include "Dragon.h"
#include "../../Config/Config.h"



Dragon::Dragon() {
  Config conf("config.json");
  hp = conf.Get<std::int32_t>("Dragon", "hp");
  damage = conf.Get<std::int32_t>("Dragon", "damage");
  symbol = conf.Get<std::string>("Dragon", "symbol")[0];
  priority = conf.Get<std::int32_t>("Dragon", "priority");
}
Dragon::Dragon(std::int32_t x, std::int32_t y) : Dragon() {
  cur_location = Point{x, y};
  prev_location = cur_location;
}
Point Dragon::Move(std::int32_t x, std::int32_t y) {
  return cur_location;
}

bool Dragon::Collide(Character *character) {
  return true;
}
bool Dragon::Collide(Knight *knight) {
  return true;
}
bool Dragon::Collide(Dragon *dragon) {
  return true;
}
bool Dragon::Collide(Princess *princess) {
  return true;
}
bool Dragon::Collide(Zombie *zombie) {
  return true;
}
bool Dragon::Collide(Wall *wall) {
  return true;
}
