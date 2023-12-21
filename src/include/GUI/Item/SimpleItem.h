/**
 * @file SimpleItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SIMPLEITEM_H
#define SIMPLEITEM_H

#include <GUI/Item/AbstractItem.h>

namespace krw::gui {

class SimpleItem : public AbstractItem {
 public:
  SimpleItem(QGraphicsItem* parent = nullptr) : AbstractItem(parent) {}
  SimpleItem(const Xaxis x, const Yaxis y, const Width width, const Height height,
             QGraphicsItem* parent = nullptr) : AbstractItem(x, y, width, height, parent) {}
  ~SimpleItem() = default;

  void paintAdditionalItems() override {}

  void setAdditionalItems() override {}

  void setPixmapItems() override = 0;

  void setCurrentPixmapItem() override = 0;

 private:
  
};

}  // namespace krw::gui

#endif  // SIMPLEITEM_H