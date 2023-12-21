/**
 * @file ModelFactory.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include <Core/Model/Unit/AbstractUnit.h>
#include <memory>
#include <utility>

namespace krw::core {

class ModelFactory {
 public:
  ModelFactory() = default;
  ~ModelFactory() = default;

  template<typename ModelType, typename... Args>
  static AbstractModel* createModel(Args&&... args) {
    return new ModelType(std::forward<Args>(args)...);
    // return new UnitType(std::forward<Args>(args)...);
  }

  template<typename ModelType, typename... Args>
  static AbstractUnit* createUnit(Args&&... args) {
    return new ModelType(std::forward<Args>(args)...);
    // return new UnitType(std::forward<Args>(args)...);
  }

  // template<typename ModelType, typename... Args>
  // static AbstractModel* createModel(Args&&... args) {
  //   return new ModelType(std::forward<Args>(args)...);
  //   // return new UnitType(std::forward<Args>(args)...);
  // }
};

}  // namespace krw::core

#endif  // MODELFACTORY_H