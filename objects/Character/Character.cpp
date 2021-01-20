#include "../Point.h"
#include "Character.h"


Point Character::GetPos() const { return cur_location; }
std::int32_t Character::X() const { return cur_location.x; }
std::int32_t Character::Y() const { return cur_location.y; }
std::size_t Character::GetHp() const { return hp; }
std::int32_t Character::GetDamage() const { return damage; }
char Character::GetSymbol() const { return symbol; }
void Character::GoBack() {
  Point tmp = prev_location;
  prev_location = cur_location;
  cur_location = tmp;
}