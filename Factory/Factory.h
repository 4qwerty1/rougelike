#ifndef ROUGELIKE_GAME_FACTORY_FACTORY_H_
#define ROUGELIKE_GAME_FACTORY_FACTORY_H_

#include <map>
#include <string>
#include "../objects/Character.h"


class abstractCreator {
 public:
  virtual Character *create() const = 0;
};

template<typename T>
struct Creator : abstractCreator {
  Character *create() const override {
    return new T();
  }
};


class Factory {
 private:
  std::map<std::string, abstractCreator *> creators;
 public:
  template<typename T>
  void add(const std::string &key) {
    if (creators.find(key) == creators.end()) {
      creators[key] = new Creator<T>();
    }
  }

  Character *create(const std::string &key) {
    auto creator = creators.find(key);
    if (creator != creators.end()) {
      return creator->second->create();
    }
    return nullptr;
  }
};

#endif //ROUGELIKE_GAME_FACTORY_FACTORY_H_
