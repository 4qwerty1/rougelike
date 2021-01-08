#include <iostream>
#include <conio.h>
#include <memory>

#include "../objects/Map/Map.h"
#include "../objects/Knight.h"


#include "GameLoop.h"

int main() {
  int key;
  Map map;
  std::vector<std::shared_ptr<Character>> characters;

  do {
    key = getch();
    system("cls");
    std::cout << key << std::endl;
    map.Draw();

    switch (key) {
      case 72:  // up
        std::cout << "its up" << std::endl;
        break;
      case 75:  // left
        std::cout << "its left" << std::endl;
        break;
      case 80:  // down
        std::cout << "its down" << std::endl;
        break;
      case 77:  // right
        std::cout << "its right" << std::endl;
        break;
      default:
        std::cout << "wrong key" << std::endl;
    }

  } while (key != 27);
  return 0;
}