/**
 * @file WizardUnitItem.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Core/Behavior/MoveBehavior.h"
#include "Core/Model/AbstractModel.h"
#include "GUI/Item/Unit/SoldierUnitItem.h"
#include <Core/Model/ModelFactory.h>
#include <Core/Model/Unit/WizardUnit.h>
#include <GUI/Item/Unit/WizardUnitItem.h>

#include <QPainter>
#include <qdebug.h>

using namespace krw::gui;

WizardUnitItem::WizardUnitItem(QGraphicsItem *parent)
    : SoldierUnitItem(parent) {
  model_ = core::ModelFactory::createModel<core::WizardUnit>();
}

WizardUnitItem::WizardUnitItem(const Xaxis x, const Yaxis y, const Width width,
                               const Height height, QGraphicsItem *parent)
    : SoldierUnitItem(x, y, width, height, parent) {

  // model_ = core::ModelFactory::createModel<core::WizardUnit>(x, y, width,
  // height); model_->setLoc(x, y, width, height);
  setModel(x, y, width, height);
  setPos(x, y);
  setPixmapItems();
  setCurrentPixmapItem();
}

void WizardUnitItem::setModel(const Xaxis x, const Yaxis y, const Width width,
                              const Height height) {
  model_ =
      core::ModelFactory::createModel<core::AbstractModel>(x, y, width, height);
  move_behavior_.setModel(model_);
  health_behavior_.setModel(model_);
}

void WizardUnitItem::setPixmapItems() {
  // QPixmap pixmap("./assets/pic/character/wizard/2_WALK_000.png");
  // QGraphicsPixmapItem *pixmap_item = new QGraphicsPixmapItem(
  //     pixmap.scaled(model_->width(), model_->height(), Qt::IgnoreAspectRatio,
  //                   Qt::SmoothTransformation),
  //     this);

  // // pixmap_item->setPos(x, y);

  // pixmap_items_.push_back(pixmap_item);
  for (int i = 0; i < 5; i++) {
    auto path = QString(":/character/wizard/wizard_walk%1.png").arg(i);
    auto pixmap_ptr =
        QPixmap(path).scaled(model_->width(), model_->height(),
                             Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    move_behavior_.addPixmap(pixmap_ptr);
    // pixmaps_.push_back(PixelLoader::load(":/character/wizard/wizard_walk%1.png").scaled(model_->width(),
    // model_->height(), Qt::IgnoreAspectRatio,
    //                   Qt::SmoothTransformation));
    // pixmaps_.push_back(pixmap_ptr);
  }
}

void WizardUnitItem::setCurrentPixmapItem() {
  // current_pixmap_item_ = pixmap_items_.at(0);
  // current_pixmap_ =
  move_behavior_.setCurrentPixmap(core::MoveBehavior::kStandPixIndex);
}

void WizardUnitItem::setAdditionalItems() {}

void WizardUnitItem::paintAdditionalItems() {}

void WizardUnitItem::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget) {
  painter->drawPixmap(model_->x(), model_->y(), model_->width(),
                      model_->height(), move_behavior_.currentPixmap());
}