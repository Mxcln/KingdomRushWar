/**
 * @file AbstractItem.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <GUI/Item/AbstractItem.h>

#include <QPainter>
#include <cassert>

using namespace krw::gui;

AbstractItem::AbstractItem(QGraphicsItem *parent)
    : QGraphicsItem(parent) {
  //   unit_ = std::make_unique<core::AbstractUnit>();
}

AbstractItem::AbstractItem(const Xaxis x, const Yaxis y,
                                   const Width width, const Height height,
                                   QGraphicsItem *parent)
    : QGraphicsItem(parent) {
  
  this->setPos(x, y);
  // unit_ = std::make_unique<core::AbstractUnit>(x, y, width, height);
}

QRectF AbstractItem::boundingRect() const {
  return QRectF(model_->x(), model_->y(), model_->width(), model_->height());
}

void AbstractItem::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget) {
  // Q_UNUSED(option);
  // Q_UNUSED(widget);
  // painter->drawPixmap(QPointF(unit_->x(), unit_->y()), current_pixmap_item_->pixmap());
  // assert(current_pixmap_item_ != nullptr);
  if (current_pixmap_item_ == nullptr) {
    return;
  }
  // current_pixmap_item_->paint(painter, option, widget);
  paintAdditionalItems();
}