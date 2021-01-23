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
#include "../Config/Config.h"

using std::shared_ptr;
using Characters = std::vector<shared_ptr<Character>>;


// Вывод карты без мерцания
// http://vsokovikov.narod.ru/New_MSDN_API/Console/con_fn.htm
//http://vsokovikov.narod.ru/New_MSDN_API/Console/scrbuf.htm
//https://ru.stackoverflow.com/questions/811009/c-vs-Мини-игра-в-консоли

// Цвет в консоли
//std::cout << "\x1b[33m" << "" << "\x1b[0m" << std::endl;

class Map {
 private:
  std::vector<std::string> map;
  shared_ptr<Characters> characters_;
  shared_ptr<Factory> factory_;
  char fog_symbol = 'A';
  std::int32_t fog_radius = 2;

  void ReadFile() {
    std::string line;
    std::ifstream fin("map.txt");

    if (fin.is_open()) {
      while (getline(fin, line)) {
        map.push_back(line);
      }
    }

    fin.close();
  }
  void FogUp(std::shared_ptr<Character> &knight_) {
    for (int i = 0; i < Height(); i++) {
      for (int j = 0; j < Width(); j++) {
        std::int32_t x = knight_->X() - j;
        std::int32_t y = knight_->Y() - i;
        if (x * x + y * y >= fog_radius * fog_radius)
          map[i][j] = fog_symbol;
      }
    }
  }
  void FillMap(std::shared_ptr<Character> &knight_) {
    map = std::vector<std::string>(Height(), std::string(Width(), '.'));
    for (auto &i : (*characters_)) {
      map[i->Y()][i->X()] = i->Symbol();
    }

    FogUp(knight_);
  }
  void CreateCharacters() {
    for (int i = 0; i < map.size(); i++) {
      for (int j = 0; j < map[i].size(); j++) {
        if (map[i][j] != '.') {
          characters_->push_back(shared_ptr<Character>(factory_->create(map[i][j], j, i)));
        }
      }
    }

    std::sort(characters_->begin(), characters_->end(),
              [](shared_ptr<Character> &x, shared_ptr<Character> &y) {
                return x->Priority() < y->Priority();
              });
  }
 public:
  Map() = default;
  Map(shared_ptr<Characters> &characters, shared_ptr<Factory> &factory)
      : characters_(characters), factory_(factory) {
    ReadFile();
    CreateCharacters();

    Config conf("config.json");
    fog_symbol = conf.Get<std::string>("Fog", "symbol")[0];
    fog_radius = conf.Get<std::int32_t>("Fog", "radius");
  }
  void Draw(std::shared_ptr<Character> &knight_) {
    FillMap(knight_);
    for (auto &i : map) {
      std::cout << i << std::endl;
    }
  }
  std::size_t Width() {
    return (!map.empty()) ? map[0].size() : 0;
  }
  std::size_t Height() {
    return map.size();
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_MAP_MAP_H_
