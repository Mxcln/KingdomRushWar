/**
 * @file InfantryUnitItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef INFANTRYUNITITEM_H
#define INFANTRYUNITITEM_H

#include <Core/Model/Unit/InfantryUnit.h>
#include <GUI/Item/Unit/AbstractUnitItem.h>

namespace krw::gui {

class InfantryUnitItem : public QGraphicsItem {
 public:
  InfantryUnitItem(const core::InfantryUnit& unit);
  ~InfantryUnitItem() = default;

  QRectF boundingRect() const override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

 private:
  const core::InfantryUnit& unit_;
};

}  // namespace krw::gui

#endif  // INFANTRYUNITITEM_H