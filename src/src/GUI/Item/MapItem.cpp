/**
 * @file MapItem.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Core/Model/AbstractModel.h"
#include <GUI/Item/MapItem.h>

#include <cstdlib>

using namespace krw::gui;

MapItem::MapItem(QGraphicsItem *parent) : SimpleItem(parent) {}

MapItem::MapItem(const MapItemType type, const Xaxis x, const Yaxis y,
                 const Width width, const Height height, QGraphicsItem *parent)
    : SimpleItem(x, y, width, height, parent), type_(type) {
  setModel(x, y, width, height);
  setPos(x, y);
  setPixmapItems();
  if (type_ != MapItemType::ROAD) {
    setCurrentPixmapItem();
  }
}

void MapItem::setModel(const Xaxis x, const Yaxis y, const Width width,
                       const Height height) {
  model_ = new core::AbstractModel(x, y, width, height);
}

void MapItem::setPixmapItems() {
  if (type_ == MapItemType::ROAD) {}
  else if (type_ != MapItemType::GRASS) {
    auto pix_path = ":/map/" + MapType::toString(type_) + ".png";
    auto pix = QPixmap(pix_path.c_str());
    auto pix_item = new QGraphicsPixmapItem(
        pix.scaled(model_->width(), model_->height(), Qt::IgnoreAspectRatio,
                   Qt::SmoothTransformation),
        this);
    // pix_item->setPos(model_->x(), model_->y());
    pix_item->setPos(0, 0);
    pixmap_items_.push_back(pix_item);
  } else {
    setDecorationPixmapItems();
  }
}

void MapItem::setCurrentPixmapItem() {
  current_pixmap_item_ = pixmap_items_[0];
}

void MapItem::setDecorationPixmapItems() {
  // random decoration
  auto dec_num = rand() % kMaxRandomDecoration + 1;
  for (int i = 0; i < dec_num; i++) { // random width, keep ratio
    auto model_width = model_->width();
    auto model_height = model_->height();
    auto dec_width = model_width / 6 + rand() % (model_width / 2);
    auto dec_height = dec_width;

    // random x and y
    auto dec_x = rand() % (model_width - dec_width);
    auto dec_y = rand() % (model_height - dec_height);

    // ramdom decoration
    auto dec_catagory = rand() % kDecorationNum + 1;

    // set decoration
    auto dec_pix_path = ":/map/dec/dec" + std::to_string(dec_catagory) + ".png";
    auto dec_pix = QPixmap(dec_pix_path.c_str());
    auto dec_pix_item = new QGraphicsPixmapItem(
        dec_pix.scaled(dec_width, dec_height, Qt::IgnoreAspectRatio,
                       Qt::SmoothTransformation),
        this);
    dec_pix_item->setPos(dec_x, dec_y);
    pixmap_items_.push_back(dec_pix_item);
  }
}

// void MapItem::setRoadPixmapItems(const MapType::RoadType type1,
//                                  const MapType::RoadType type2,
//                                  const MapType::RoadType type3,
//                                  const MapType::RoadType type4) {}


void MapItem::addPixelMapItem(MapItemType type) {
  auto pix_path = ":/map/" + MapType::toString(type) + ".png";
  auto pix = QPixmap(pix_path.c_str());
  auto pix_item = new QGraphicsPixmapItem(
      pix.scaled(model_->width(), model_->height(), Qt::IgnoreAspectRatio,
                 Qt::SmoothTransformation),
      this);
  // pix_item->setPos(model_->x(), model_->y());
  pix_item->setPos(0, 0);
  // pix_item->setZValue(0);
  // pixmap_items_.push_back(pix_item);
}