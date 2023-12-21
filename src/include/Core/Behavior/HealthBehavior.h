/**
 * @file HealthBehavior.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HEALTHBEHAVIOR_H
#define HEALTHBEHAVIOR_H

#include <Core/Behavior/AbstractBehavior.h>

namespace krw::core {

class AbstractUnit;

class HealthBehavior : public AbstractBehavior {
public:
  HealthBehavior() = default;
  HealthBehavior(AbstractModel *model) : AbstractBehavior(model) {}
  ~HealthBehavior() = default;

  void setHealth(const int health) { health_ = health; }
  void setMaxHealth(const int max_health) { max_health_ = max_health; }

  void increaseHealth(const int health) {
    health_ += health;
    health_ = health_ > max_health_ ? max_health_ : health_;
  }
  void decreaseHealth(const int health) {
    health_ -= health;
    health_ = health_ < 0 ? 0 : health_;
  }

  int health() const { return health_; }
  int maxHealth() const { return max_health_; }

private:
  int health_;
  int max_health_;
};

} // namespace krw::core

#endif // HEALTHBEHAVIOR_H