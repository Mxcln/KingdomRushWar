/**
 * @file UnitItemGroup.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UNITITEMGROUP_H
#define UNITITEMGROUP_H

#include <QGraphicsItemGroup>

#include <GUI/Item/Unit/AbstractUnitItem.h>

namespace krw::gui {

class UnitItemGroup : public QGraphicsItemGroup {
public:

  UnitItemGroup(QGraphicsItem* parent = nullptr);
  ~UnitItemGroup();

  void AddUnitItem(AbstractUnitItem* unit_item);

private:

}; // class UnitItemGroup

} // namespace krw::gui

#endif // UNITITEMGROUP_H