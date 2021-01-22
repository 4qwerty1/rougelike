#include "Princess.h"
#include "../../Config/Config.h"


Princess::Princess() {
  Config conf("config.json");
  hp = conf.Get<std::int32_t>("Princess", "hp");
  damage = conf.Get<std::int32_t>("Princess", "damage");
  symbol = conf.Get<std::string>("Princess", "symbol")[0];
  priority = conf.Get<std::int32_t>("Princess", "priority");
}
Princess::Princess(std::int32_t x, std::int32_t y) : Princess() {
  cur_location = Point{x, y};
  prev_location = cur_location;
}
Point Princess::Move(std::int32_t x, std::int32_t y) {
  return cur_location;
}

bool Princess::Collide(Character *character) {
  return true;
}
bool Princess::Collide(Knight *knight) {

  return true;
}
bool Princess::Collide(Dragon *dragon) {
  return true;
}
bool Princess::Collide(Princess *princess) {
  return true;
}
bool Princess::Collide(Zombie *zombie) {
  return true;
}
bool Princess::Collide(Wall *wall) {
  return true;
}