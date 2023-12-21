/**
 * @file AbstractBehavior.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ABSTRACTBEHAVIOR_H
#define ABSTRACTBEHAVIOR_H

namespace krw::core {

/// @brief AbstractBehavior of kingdom rush war unit.
/// This is a abstract class.

class AbstractModel;

class AbstractBehavior {
public:
  AbstractBehavior() = default;
  AbstractBehavior(AbstractModel *model) : model_(model) {}
  ~AbstractBehavior() = default;

  void setModel(AbstractModel *model) { model_ = model; }

protected:
 
  AbstractModel *model_;

}; // class AbstractBehavior

} // namespace krw::core

#endif // ABSTRACTBEHAVIOR_H