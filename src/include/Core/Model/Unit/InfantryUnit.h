/**
 * @file InfantryUnit.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef INFANTRYUNIT_H
#define INFANTRYUNIT_H

#include <Core/Model/Unit/AbstractUnit.h>
#include <Core/Behavior/MoveBehavior.h>

namespace krw::core {

class InfantryUnit : public AbstractUnit {
 public:
  InfantryUnit() = default;
  ~InfantryUnit() = default;

 private:
  MoveBehavior move_behavior_;
  
};

}  // namespace krw::core

#endif  // INFANTRYUNIT_H