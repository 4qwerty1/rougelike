#ifndef ROUGELIKE_GAME_OBJECTS_POINT_H_
#define ROUGELIKE_GAME_OBJECTS_POINT_H_

struct Point {
  std::int32_t x;
  std::int32_t y;

  Point(std::int32_t x = 0, std::int32_t y = 0) : x(x), y(y) {}

  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

#endif //ROUGELIKE_GAME_OBJECTS_POINT_H_
