#ifndef ROUGELIKE_GAME_OBJECTS_MAP_MAP_H_
#define ROUGELIKE_GAME_OBJECTS_MAP_MAP_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../Character.h"
#include "../Knight.h"


// Вывод карты без мерцания
// http://vsokovikov.narod.ru/New_MSDN_API/Console/con_fn.htm
//http://vsokovikov.narod.ru/New_MSDN_API/Console/scrbuf.htm
//https://ru.stackoverflow.com/questions/811009/c-vs-Мини-игра-в-консоли

// Цвет в консоли
//std::cout << "\x1b[33m" << "" << "\x1b[0m" << std::endl;

class Map {
 private:
  std::vector<std::string> map;
  std::vector<std::shared_ptr<Character>> characters;
  std::size_t width;
  std::size_t height;

  void readFile() {
    std::string line;
    std::ifstream fin("map.txt");

    if (fin.is_open()) {
      while (getline(fin, line)) {
        map.push_back(line);
      }
    }

    fin.close();
  }
  void fillMap() {
    // заполнить карту в соответствии со смещением героев
  }
  void createCharacters() {
    for (int i = 0; i < map.size(); i++) {
      for (int j = 0; j < map[i].size(); j++) {
        switch (map[i][j]) {
          case 'K':
              Knight test(4, 1);
            characters.push_back(std::shared_ptr<Character>(&test));
            characters.push_back(std::make_shared<Knight>(&test));
        }
      }
    }
  }
 public:
  Map() {
    readFile();
    createCharacters();
  }
  void Draw() {
    fillMap();
    for (auto &i : map) {
      std::cout << i << std::endl;
    }
  }
  std::size_t Width() {
    return (map.size() > 0) ? map[0].size() : 0;
  }
  std::size_t Height() {
    return map.size();
  }
  auto getCharacters() {
    return characters;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_MAP_MAP_H_
