/**
 * @file Location.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LOCATION_H
#define LOCATION_H

#include <Basic.h>
#include <initializer_list>

namespace krw {

class Location {
public:
  Location() = default;
  Location(Xaxis x, Yaxis y) : x_(x), y_(y) {}
  Location(Xaxis x, Yaxis y, Width width, Height height)
      : x_(x), y_(y), width_(width), height_(height) {}
  Location(std::initializer_list<int> list)
      : x_(*list.begin()), y_(*(list.begin() + 1)), width_(*(list.begin() + 2)),
        height_(*(list.begin() + 3)) {}
  ~Location() = default;

  const Xaxis x() const { return x_; }
  const Yaxis y() const { return y_; }
  const Width width() const { return width_; }
  const Height height() const { return height_; }

  void setX(Xaxis x) { x_ = x; }
  void setY(Yaxis y) { y_ = y; }
  void setWidth(Width width) { width_ = width; }
  void setHeight(Height height) { height_ = height; }

private:
  Xaxis x_;
  Yaxis y_;
  Width width_;
  Height height_;
};

} // namespace krw

#endif // LOCATION_H