/**
 * @file SoldierUnitItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SOLDIERUNITITEM_H
#define SOLDIERUNITITEM_H

#include <GUI/Item/Unit/AbstractUnitItem.h>
#include <Core/Behavior/MoveBehavior.h>
#include <Core/Behavior/HealthBehavior.h>

namespace krw::gui {

class SoldierUnitItem : public AbstractUnitItem {
 public:
  SoldierUnitItem(QGraphicsItem *parent = nullptr);
  SoldierUnitItem(const Xaxis x, const Yaxis y, const Width width,
                  const Height height, QGraphicsItem *parent = nullptr);
  virtual ~SoldierUnitItem() = default;

  // QRectF boundingRect() const override;
  // virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
  //            QWidget *widget) override;

  // void setModel(const Xaxis x, const Yaxis y, const Width width,
  //               const Height height) override;

  // void setCurrentPixmapItem() override;

  // void setPixmapItems() override;

  // void paintAdditionalItems() override;

  // void setAdditionalItems() override;

  

 protected:
  core::MoveBehavior move_behavior_;
  core::HealthBehavior health_behavior_;
};

} // namespace krw::gui

#endif // SOLDIERUNITITEM_H


