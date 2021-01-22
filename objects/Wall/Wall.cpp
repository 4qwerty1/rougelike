#include "Wall.h"
#include "../Knight/Knight.h"
#include "../Dragon/Dragon.h"
#include "../Princess/Princess.h"
#include "../Zombie/Zombie.h"
#include "../../Config/Config.h"

Wall::Wall() {
  Config conf("config.json");
  hp = conf.Get<std::int32_t>("Wall", "hp");
  damage = conf.Get<std::int32_t>("Wall", "damage");
  symbol = conf.Get<std::string>("Wall", "symbol")[0];
  priority = conf.Get<std::int32_t>("Wall", "priority");
}
Wall::Wall(std::int32_t x, std::int32_t y) : Wall() {
  cur_location = Point{x, y};
  prev_location = cur_location;
}
Point Wall::Move(std::int32_t x, std::int32_t y) {
  return cur_location;
}

bool Wall::Collide(Character *character) {
  return character->Collide(this);
}
bool Wall::Collide(Knight *knight) {
  knight->GoBack();
  return false;
}
bool Wall::Collide(Dragon *dragon) {
  dragon->GoBack();
  return false;
}
bool Wall::Collide(Princess *princess) {
  princess->GoBack();
  return false;
}
bool Wall::Collide(Zombie *zombie) {
  zombie->GoBack();
  return false;
}
bool Wall::Collide(Wall *wall) {
  return false;
}