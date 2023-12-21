/**
 * @file SoldierUnitItem.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Core/Model/AbstractModel.h"
#include <Core/Model/ModelFactory.h>
#include <GUI/Item/Unit/SoldierUnitItem.h>

#include <QPainter>

using namespace krw::gui;

SoldierUnitItem::SoldierUnitItem(QGraphicsItem *parent)
    : AbstractUnitItem(parent) {
  // setModel(0, 0, 0, 0);
  // setPixmapItems();
  // setCurrentPixmapItem();
  // setAdditionalItems();
}

SoldierUnitItem::SoldierUnitItem(const Xaxis x, const Yaxis y,
                                 const Width width, const Height height,
                                 QGraphicsItem *parent)
    : AbstractUnitItem(x, y, width, height, parent) {
  // setModel(x, y, width, height);
  // setPixmapItems();
  // setCurrentPixmapItem();
  // setAdditionalItems();
}

// void SoldierUnitItem::setModel(const Xaxis x, const Yaxis y, const Width width,
//                                const Height height) {
//   //   model_ =
//   //       core::ModelFactory::createModel<core::AbstractModel>(x, y, width,
//   //       height);
// }

// void SoldierUnitItem::setCurrentPixmapItem() {
//   //   current_pixmap_item_ = pixmap_items_[0];
// }

// void SoldierUnitItem::setPixmapItems() {}

// void SoldierUnitItem::paintAdditionalItems() {
//   // QGraphicsPixmapItem *pixmap_item = new QGraphicsPixmapItem(
//   //     QPixmap(QString(":/character/wizard/wizard_walk%1.png").arg(0))
//   //         .scaled(model_->width(), model_->height(), Qt::IgnoreAspectRatio,
//   //                 Qt::SmoothTransformation),
//   //     this);
//   // pixmap_item->setPos(model_->x(), model_->y());
//   // pixmap_items_.push_back(pixmap_item);
// }

// void SoldierUnitItem::setAdditionalItems() {
//   // QGraphicsPixmapItem *pixmap_item = new QGraphicsPixmapItem(
//   //     QPixmap(QString(":/character/wizard/wizard_walk%1.png").arg(0))
//   //         .scaled(model_->width(), model_->height(), Qt::IgnoreAspectRatio,
//   //                 Qt::SmoothTransformation),
//   //     this);
//   // pixmap_item->setPos(model_->x(), model_->y());
//   // pixmap_items_.push_back(pixmap_item);
// }

// void SoldierUnitItem::paint(QPainter *painter,
//                             const QStyleOptionGraphicsItem *option,
//                             QWidget *widget) {
//   // painter->drawPixmap(model_->x(), model_->y(), model_->width(),
//   //                     model_->height(), *move_behavior_.currentPixmap());
// }
