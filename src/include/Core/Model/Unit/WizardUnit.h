/**
 * @file WizardUnit.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WIZARDUNIT_H
#define WIZARDUNIT_H

#include "Core/Behavior/MoveBehavior.h"
#include <Core/Model/Unit/AbstractUnit.h>

namespace krw::core {

class WizardUnit : public AbstractUnit {
public:
  WizardUnit() = default;
  WizardUnit(const Xaxis x, const Yaxis y, const Width width,
             const Height height)
      : AbstractUnit(x, y, width, height) {}
  ~WizardUnit() = default;


  // move behavior
  void setSpeed(const int speed) { move_behavior_->setSpeed(speed); }
  void setDirection(const Direction direction) {
    move_behavior_->setDirection(direction);
  }
  void move(const int speed, const Direction direction) {
    move_behavior_->move(speed, direction);
  }
  void move(const Direction direction) { move_behavior_->move(direction); }
  void move() { move_behavior_->move(); }

private:

  MoveBehavior* move_behavior_;

};

} // namespace krw::core

#endif // WIZARDUNIT_H