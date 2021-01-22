#include <algorithm>
#include "Map.h"

void Map::ReadFile() {
  std::string line;
  std::ifstream fin("map.txt");

  if (fin.is_open()) {
    while (getline(fin, line)) {
      map.push_back(line);
    }
  }

  fin.close();
}
void Map::FillMap() {
  map = std::vector<std::string>(Height(), std::string(Width(), '.'));
  for (auto &i : *characters) {
    map[i->Y()][i->X()] = i->Symbol();
  }
}
Map::Map(Characters *characters, Factory *factory) : characters(characters), factory_(factory) {
  ReadFile();
  CreateCharacters();
}
void Map::Draw() {
  FillMap();
  for (auto &i : map) {
    std::cout << i << std::endl;
  }
}
std::size_t Map::Width() {
  return (!map.empty()) ? map[0].size() : 0;
}
std::size_t Map::Height() {
  return map.size();
}

bool comp(std::shared_ptr<Character> &x, std::shared_ptr<Character> &y) {
  return x->Priority() < y->Priority();
}

void Map::CreateCharacters() {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      if (map[i][j] != '.') {
        characters->push_back(std::shared_ptr<Character>(factory_->create(map[i][j], j, i)));
      }
    }
  }

  std::sort(characters->begin(), characters->end(), comp);
}