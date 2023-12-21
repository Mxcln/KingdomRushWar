/**
 * @file WizardUnitItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WIZARDUNITITEM_H
#define WIZARDUNITITEM_H

#include "Basic.h"
#include "GUI/Item/Unit/SoldierUnitItem.h"
#include <GUI/Item/Unit/AbstractUnitItem.h>

namespace krw::gui {

class WizardUnitItem : public SoldierUnitItem {
public:
  WizardUnitItem(QGraphicsItem *parent = nullptr);
  WizardUnitItem(const Xaxis x, const Yaxis y, const Width width,
                 const Height height, QGraphicsItem *parent = nullptr);
  ~WizardUnitItem() = default;

  // void setModel(const Xaxis x, const Yaxis y, const Width width,
  //               const Height height) override;

  // void setCurrentPixmapItem() override;

  // void setPixmapItems() override;

  // void paintAdditionalItems() override;

  // void setAdditionalItems() override;

    void setModel(const Xaxis x, const Yaxis y, const Width width,
                const Height height);

  void setCurrentPixmapItem();

  void setPixmapItems();

  void paintAdditionalItems();

  void setAdditionalItems();

  void move(const int speed, const Direction direction) {
    move_behavior_.move(speed, direction);
  }

  void move(const Direction direction) { move_behavior_.move(direction); }

  void move() { move_behavior_.move(); }

  void setSpeed(const int speed) { move_behavior_.setSpeed(speed); }

  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

private:


};

} // namespace krw::gui

#endif // WIZARDUNITITEM_H