#include <iostream>
#include <conio.h>
#include <memory>

#include "GameLoop.h"

GameLoop::GameLoop() {
  characters_ = std::make_shared<Characters>();
  factory_ = std::make_shared<Factory>();
  AddMobs();
  map_ = std::make_shared<Map>(characters_, factory_);
}

void GameLoop::AddMobs() {
  Config conf("config.json");

  factory_->add<Dragon>(conf.Get<std::string>("Dragon", "symbol")[0]);
  factory_->add<Knight>(conf.Get<std::string>("Knight", "symbol")[0]);
  factory_->add<Princess>(conf.Get<std::string>("Princess", "symbol")[0]);
  factory_->add<Wall>(conf.Get<std::string>("Wall", "symbol")[0]);
  factory_->add<Zombie>(conf.Get<std::string>("Zombie", "symbol")[0]);
}
void GameLoop::MoveMobs() {
  for (auto &i : (*characters_)) {
    if (i != knight_) {
      i->Move(knight_->X(), knight_->Y());
    }
  }
}

void GameLoop::ValidateMoves() {
  bool flag1 = knight_->X() < 0;
  bool flag2 = knight_->X() >= map_->Width();
  bool flag3 = knight_->Y() < 0;
  bool flag4 = knight_->Y() >= map_->Height();
  if (flag1 || flag2 || flag3 || flag4) knight_->GoBack();

  for (int i = 0; i < characters_->size(); i++) {
    for (int j = i + 1; j < characters_->size(); j++) {
      if ((*characters_)[i]->GetPos() == (*characters_)[j]->GetPos()) {
        (*characters_)[i]->Collide((*characters_)[j].get());
      }
    }
  }
}
void GameLoop::RemoveDead() {
  if (knight_->Hp() <= 0) GameOver(false);

  for (int i = 0; i < characters_->size(); i++) {
    if ((*characters_)[i]->Hp() <= 0) {
      characters_->erase(std::find(characters_->begin(), characters_->end(), (*characters_)[i]));
      i--;
    }
  }
}

void GameLoop::FindKnight() {
  for (auto &i : (*characters_)) {
    if (i->Symbol() == 'K') {
      knight_ = i;
      return;
    }
  }
}

void GameLoop::StartGame() {
  FindKnight();
  int key;
  map_->Draw(knight_);
  do {
    key = getch();
//    std::cin >> key;

    switch (key) {
      case 119:  // up
      case 87:
      case 230:
      case 150:knight_->Move(0, -1);
        break;

      case 97:  // left
      case 65:
      case 228:
      case 148:knight_->Move(-1, 0);
        break;

      case 115:  // down
      case 83:
      case 235:
      case 155:knight_->Move(0, 1);
        break;

      case 100:  // right
      case 68:  // right
      case 162:  // right
      case 130:  // right
        knight_->Move(1, 0);
        break;
      default:continue;
    }
    MoveMobs();
    ValidateMoves();
    RemoveDead();
    system("cls");
    std::cout << knight_->Hp() << std::endl;
    map_->Draw(knight_);
  } while (key != 27);
}
void GameLoop::GameOver(bool is_win) {
  system("cls");
  if (is_win)
    std::cout << "--- YOU WIN ---" << std::endl;
  else
    std::cout << "--- YOU LOSE ---" << std::endl;

  exit(0);
}
void GameLoop::StartMenu() {
  int key;
  bool is_start = true;

  system("cls");
  std::cout << ">  START  <" << std::endl;
  std::cout << "    END    " << std::endl;
  do {
    key = getch();
//    std::cout << key << std::endl;

    system("cls");
    switch (key) {
      case 119:  // up
      case 87:
      case 230:
      case 150:is_start = !(is_start);
        break;
      case 115:  // down
      case 83:
      case 235:
      case 155:is_start = !(is_start);
        break;
      case 13:if (is_start) StartGame();
        exit(0);
    }
    if (is_start) {
      std::cout << ">  START  <" << std::endl;
      std::cout << "    END    " << std::endl;
    } else {
      std::cout << "   START   " << std::endl;
      std::cout << ">   END   <" << std::endl;
    }

  } while (key != 27);
}
