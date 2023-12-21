/**
 * @file UnitItemGroup.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <GUI/Item/Unit/UnitItemGroup.h>

using namespace krw::gui;

UnitItemGroup::UnitItemGroup(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent) {
  setZValue(kUnitItemZ);
}

UnitItemGroup::~UnitItemGroup() {}

void UnitItemGroup::AddUnitItem(AbstractUnitItem *unit_item) {
  this->addToGroup(unit_item);
}