#include <iostream>
#include <conio.h>
#include <memory>

#include "GameLoop.h"

GameLoop::GameLoop() /*: map(&characters, &factory_)*/ {
  addMobs();
  map = Map(&characters, &factory_);
}

void GameLoop::addMobs() {
  factory_.add<Dragon>('D');
  factory_.add<Knight>('K');
  factory_.add<Princess>('P');
  factory_.add<Wall>('#');
  factory_.add<Zombie>('Z');
}


void GameLoop::start() {
  int key;
  std::cout << "game loop start" << std::endl;
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
}