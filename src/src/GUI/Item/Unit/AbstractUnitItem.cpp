/**
 * @file AbstractUnitItem.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <GUI/Item/Unit/AbstractUnitItem.h>

#include <QPainter>

using namespace krw::gui;

AbstractUnitItem::AbstractUnitItem(QGraphicsItem *parent)
    : AbstractItem(parent) {
  //   unit_ = std::make_unique<core::AbstractUnit>();
}

AbstractUnitItem::AbstractUnitItem(const Xaxis x, const Yaxis y,
                                   const Width width, const Height height,
                                   QGraphicsItem *parent)
    : AbstractItem(x, y, width, height, parent) {
  
  this->setPos(x, y);
  // unit_ = std::make_unique<core::AbstractUnit>(x, y, width, height);
}

// QRectF AbstractUnitItem::boundingRect() const {
//   return QRectF(unit_->x(), unit_->y(), unit_->width(), unit_->height());
// }

// void AbstractUnitItem::paint(QPainter *painter,
//                              const QStyleOptionGraphicsItem *option,
//                              QWidget *widget) {
//   // Q_UNUSED(option);
//   // Q_UNUSED(widget);
//   // painter->drawPixmap(QPointF(unit_->x(), unit_->y()), current_pixmap_item_->pixmap());
//   current_pixmap_item_->paint(painter, option, widget);
// }