/**
 * @file AbstractUnit.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ABSTRACTUNIT_H
#define ABSTRACTUNIT_H

#include <Utils/Location.h>
#include <Core/Model/AbstractModel.h>


namespace krw::core {

class AbstractUnit : public AbstractModel  {
 public:
  AbstractUnit() = default;
  AbstractUnit(const Xaxis x, const Yaxis y, const Width width,
               const Height height)
      : AbstractModel(x, y, width, height) {}
  ~AbstractUnit() = default;
  
};

}  // namespace krw::core

#endif  // ABSTRACTUNIT_H