#ifndef ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_
#define ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_


#include <conio.h>
#include "../objects/Map/Map.h"
#include "../Factory/Factory.h"
#include "../objects/Character.h"
#include "../objects/Dragon.h"
#include "../objects/Knight.h"
#include "../objects/Princess.h"
#include "../objects/Wall.h"
#include "../objects/Zombie.h"

class GameLoop {
 private:
  Factory factory_;
  Map map;
  std::vector<std::shared_ptr<Character>> characters;

 public:
  GameLoop();
  void addMobs();
  void start();
};

#endif //ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_
