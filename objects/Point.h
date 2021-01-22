#ifndef ROUGELIKE_GAME_OBJECTS_POINT_H_
#define ROUGELIKE_GAME_OBJECTS_POINT_H_

#include <iostream>

struct Point {
  std::int32_t x;
  std::int32_t y;

  Point(std::int32_t x = 0, std::int32_t y = 0) : x(x), y(y) {}

  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << p.x << " " << p.y;
    return os;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_POINT_H_
