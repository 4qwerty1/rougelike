#ifndef ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_
#define ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_


#include <conio.h>
#include <map>
#include "../Config/Config.h"
#include "../Map/Map.h"
#include "../Factory/Factory.h"
#include "../objects/Character/Character.h"
#include "../objects/Dragon/Dragon.h"
#include "../objects/Knight/Knight.h"
#include "../objects/Princess/Princess.h"
#include "../objects/Wall/Wall.h"
#include "../objects/Zombie/Zombie.h"

using Characters = std::vector<std::shared_ptr<Character>>;

class GameLoop {
 private:
  std::shared_ptr<Factory> factory_;
  std::shared_ptr<Map> map_;
  std::shared_ptr<Characters> characters_;
  std::shared_ptr<Character> knight_;


 public:
  GameLoop();
  void AddMobs();
  void MoveMobs();
  void ValidateMoves();
  void RemoveDead();
  static void GameOver(bool);
  void StartMenu();
  void StartGame();
  void FindKnight();
};

#endif //ROUGELIKE_GAME_GAMELOOP_GAMELOOP_H_
