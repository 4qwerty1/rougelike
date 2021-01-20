#ifndef ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_
#define ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_


#include <conio.h>
#include "../objects/Map/Map.h"
#include "../Factory/Factory.h"
#include "../objects/Character/Character.h"
#include "../objects/Dragon/Dragon.h"
#include "../objects/Knight/Knight.h"
#include "../objects/Princess/Princess.h"
#include "../objects/Wall/Wall.h"
#include "../objects/Zombie/Zombie.h"

class GameLoop {
 private:
  Factory factory_;
  Map map;
  std::vector<std::shared_ptr<Character>> characters;
  std::shared_ptr<Character> knight_;

 public:
  GameLoop();
  void AddMobs();
  void MoveMobs();
  void ValidateMoves();
  void RemoveDead();
  void Start();
  void FindKnight();
};

#endif //ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_
