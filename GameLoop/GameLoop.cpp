#include <iostream>
#include <conio.h>
#include <memory>

#include "GameLoop.h"

GameLoop::GameLoop() {
  AddMobs();
  map = Map(&characters, &factory_);
}

void GameLoop::AddMobs() {
  factory_.add<Dragon>('D');
  factory_.add<Knight>('K');
  factory_.add<Princess>('P');
  factory_.add<Wall>('#');
  factory_.add<Zombie>('Z');
}

void GameLoop::MoveMobs() {
  for (auto &i : characters) {
    if (i != knight_) {
      i->Move(knight_->X(), knight_->Y());
    }
  }
}
void GameLoop::ValidateMoves() {
  for (int i = 0; i < characters.size(); i++) {
    for (int j = i + 1; j < characters.size(); j++) {
      if (characters[i]->GetPos() == characters[j]->GetPos()) {
        characters[i]->Fight(characters[j].get());
      }
    }
  }
}
void GameLoop::RemoveDead() {
  std::vector<std::shared_ptr<Character>> alive;
  for (auto &i : characters) {
    if (i->GetHp() > 0) {
      alive.push_back(i);
    }
  }
  characters = alive;
}

void GameLoop::FindKnight() {
  for (auto &i : characters) {
    if (i->GetSymbol() == 'K') {
      knight_ = i;
      return;
    }
  }
}

void GameLoop::Start() {
  FindKnight();
  int key;
  std::cout << "game loop Start" << std::endl;
  std::cout << "press a key" << std::endl;
  map.Draw();
  do {
    key = getch();
//    std::cin >> key;
//    system("cls");
//    std::cout << key << std::endl;

    switch (key) {
      case 72:  // up
        knight_->Move(0, -1);
        break;
      case 75:  // left
        knight_->Move(-1, 0);
        break;
      case 80:  // down
        knight_->Move(0, 1);
        break;
      case 77:  // right
        knight_->Move(1, 0);
        break;
      default:continue;
    }
    MoveMobs();
    ValidateMoves();
    RemoveDead();
    system("cls");
//    std::cout << std::endl;
    map.Draw();
  } while (key != 27);
}