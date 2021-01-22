#ifndef ROUGELIKE_GAME_CONFIGS_CONFIG_H_
#define ROUGELIKE_GAME_CONFIGS_CONFIG_H_

#include <iostream>
#include <fstream>
#include "json.hpp"

using nlohmann::json;

class Config {
  json j;

 public:
  explicit Config(const std::string &file_name = "config.json") {
    std::ifstream(file_name) >> j;
  }

  template<class T>
  T Get(const std::string &class_name, const std::string &param_name) {
    return j[class_name][param_name].get<T>();
  }
};

#endif //ROUGELIKE_GAME_CONFIGS_CONFIG_H_
