#ifndef ROUGELIKE_GAME_OBJECTS_MAP_MAP_H_
#define ROUGELIKE_GAME_OBJECTS_MAP_MAP_H_

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include "../Factory/Factory.h"
#include "../objects/Character/Character.h"
#include "../objects/Knight/Knight.h"

using Characters = std::vector<std::shared_ptr<Character>>;
// Вывод карты без мерцания
// http://vsokovikov.narod.ru/New_MSDN_API/Console/con_fn.htm
//http://vsokovikov.narod.ru/New_MSDN_API/Console/scrbuf.htm
//https://ru.stackoverflow.com/questions/811009/c-vs-Мини-игра-в-консоли

// Цвет в консоли
//std::cout << "\x1b[33m" << "" << "\x1b[0m" << std::endl;

class Map {
 private:
  std::vector<std::string> map;
  Characters *characters;
  Factory *factory_;

  void ReadFile();
  void FillMap();
  void CreateCharacters();
 public:
  Map() = default;
  Map(Characters *characters, Factory *factory);
  void Draw();
  std::size_t Width();
  std::size_t Height();
};

#endif //ROUGELIKE_GAME_OBJECTS_MAP_MAP_H_
