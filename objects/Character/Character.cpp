#include "../Point.h"
#include "Character.h"
#include "../Dragon/Dragon.h"
#include "../Knight/Knight.h"
#include "../Princess/Princess.h"
#include "../Wall/Wall.h"
#include "../Zombie/Zombie.h"

Point Character::GetPos() const { return cur_location; }
std::int32_t Character::X() const { return cur_location.x; }
std::int32_t Character::Y() const { return cur_location.y; }
std::int32_t Character::Hp() const { return hp; }
std::int32_t Character::Damage() const { return damage; }
std::size_t Character::Priority() const { return priority; }
void Character::TakeDamage(std::int32_t x) {
  this->hp -= x;
}
char Character::Symbol() const { return symbol; }
void Character::GoBack() {
  cur_location = prev_location;
}