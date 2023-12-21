/**
 * @file AbstractModel.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <Utils/Location.h>

namespace krw::core {

class AbstractModel {
 public:
  AbstractModel() = default;
  AbstractModel(const Xaxis x, const Yaxis y, const Width width,
               const Height height)
      : loc_(x, y, width, height) {}
  virtual ~AbstractModel() = default;

  const Location& loc() const { return loc_; }
  const Width width() const { return loc_.width(); }
  const Height height() const { return loc_.height(); }
  const Xaxis x() const { return loc_.x(); }
  const Yaxis y() const { return loc_.y(); }

  void setX(Xaxis x) { loc_.setX(x); }
  void setY(Yaxis y) { loc_.setY(y); }
  void setWidth(Width width) { loc_.setWidth(width); }
  void setHeight(Height height) { loc_.setHeight(height); }
  void setLoc(const Location& loc) { loc_ = loc; }
  void setLoc(const Xaxis& x, const Yaxis& y, const Width& width,
              const Height& height) {
    loc_.setX(x);
    loc_.setY(y);
    loc_.setWidth(width);
    loc_.setHeight(height);
  }
  
 private:
 
  Location loc_;
  
};

}  // namespace krw::core

#endif  // ABSTRACTMODEL_H