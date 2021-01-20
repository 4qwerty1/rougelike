#ifndef ROUGELIKE_GAME_FACTORY_FACTORY_H_
#define ROUGELIKE_GAME_FACTORY_FACTORY_H_

#include <map>
#include "../objects/Character/Character.h"

struct abstractCreator {
  virtual Character *create(std::int32_t x, std::int32_t y) const = 0;
};

template<typename T>
struct Creator : abstractCreator {
  Character *create(std::int32_t x, std::int32_t y) const override {
    return new T(x, y);
  }
};

class Factory {
 private:
  std::map<char, abstractCreator *> creators;
 public:
  template<typename T>
  void add(char key) {
    if (creators.find(key) == creators.end()) {
      creators[key] = new Creator<T>();
    }
  }

  Character *create(char key, std::int32_t x, std::int32_t y) {
    auto creator = creators.find(key);
    if (creator != creators.end()) {
      return creator->second->create(x, y);
    }
    throw "no creator";
  }
};

#endif //ROUGELIKE_GAME_FACTORY_FACTORY_H_
