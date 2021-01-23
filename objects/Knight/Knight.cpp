#include "Knight.h"
#include "../../GameLoop/GameLoop.h"
#include "../../Config/Config.h"
#include "../Dragon/Dragon.h"
#include "../Princess/Princess.h"
#include "../Wall/Wall.h"
#include "../Zombie/Zombie.h"

using std::int32_t;

Knight::Knight() {
  Config conf("config.json");
  hp = conf.Get<std::int32_t>("Knight", "hp");
  damage = conf.Get<std::int32_t>("Knight", "damage");
  symbol = conf.Get<std::string>("Knight", "symbol")[0];
  priority = conf.Get<std::int32_t>("Knight", "priority");
}
Knight::Knight(std::int32_t x, std::int32_t y) : Knight() {
  cur_location = Point{x, y};
  prev_location = cur_location;
}
Point Knight::Move(std::int32_t x, std::int32_t y) {
  prev_location = cur_location;
  cur_location.x += x;
  cur_location.y += y;
  return cur_location;
}

bool Knight::Collide(Character *character) {
  return character->Collide(this);
}
bool Knight::Collide(Knight *knight) {
  return true;
}
bool Knight::Collide(Dragon *dragon) {
  this->hp -= dragon->Damage();
  dragon->TakeDamage(this->damage);
  return true;
}
bool Knight::Collide(Princess *princess) {
  GameLoop::GameOver(true);
  return true;
}
bool Knight::Collide(Wall *wall) {
  GoBack();
  return true;
}
bool Knight::Collide(Zombie *zombie) {
  this->hp -= zombie->Damage();
  zombie->TakeDamage(this->damage);
  return true;
}