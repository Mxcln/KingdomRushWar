/**
 * @file RoadItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ROADITEM_H
#define ROADITEM_H

#include <GUI/GUI.h>
#include <GUI/Item/MapItem.h>
#include <qgraphicsitem.h>

namespace krw::gui {

class RoadItem : public MapItem {

public:
  RoadItem(const RoadItemType type, const Xaxis x, const Yaxis y, const Width width,
           const Height height, QGraphicsItem *parent = nullptr)
      : MapItem(MapItemType::ROAD, x, y, width, height, parent),
        road_type_(type) {
    setRoadPixmapItems(x, y, width, height);
    // current_pixmap_item_ = pixmap_items_[0];
  }
  ~RoadItem() = default;

  void setRoadPixmapItems(const Xaxis x, const Yaxis y, const Width width,
                          const Height height) {
    switch (road_type_) {
    case RoadType::Type::HORIZONTAL:
      setSubRoadItems(x, y, width, height, 2, 2, 8, 8);
      break;
    case RoadType::Type::VERTICAL:
        setSubRoadItems(x, y, width, height, 4, 6, 4, 6);
        break;
    case RoadType::Type::LEFT_UP:
        setSubRoadItems(x, y, width, height, 13, 6, 8, 9);
        break;
    case RoadType::Type::LEFT_DOWN:
        setSubRoadItems(x, y, width, height, 2, 3, 11, 6);
        break;
    case RoadType::Type::RIGHT_UP:
        setSubRoadItems(x, y, width, height, 4, 12, 7, 8);
        break;
    case RoadType::Type::RIGHT_DOWN:
        setSubRoadItems(x, y, width, height, 1, 2, 4, 10);
        break;
    case RoadType::Type::LEFT_UP_BLOCK:
        setSubRoadItems(x, y, width, height, 5, 6, 8, 9);
        break;
    case RoadType::Type::LEFT_DOWN_BLOCK:
        setSubRoadItems(x, y, width, height, 2, 3, 5, 6);
        break;
    case RoadType::Type::RIGHT_UP_BLOCK:
        setSubRoadItems(x, y, width, height, 4, 5, 7, 8);
        break;
    case RoadType::Type::RIGHT_DOWN_BLOCK:
        setSubRoadItems(x, y, width, height, 1, 2, 4, 5);
        break;
    case RoadType::Type::LEFT_BLOCK:
        setSubRoadItems(x, y, width, height, 13, 5, 11, 5);
        break;
    case RoadType::Type::RIGHT_BLOCK:
        setSubRoadItems(x, y, width, height, 5, 12, 5, 10);
        break;
    case RoadType::Type::UP_BLOCK:
        setSubRoadItems(x, y, width, height, 13, 12, 5, 5);
        break;
    case RoadType::Type::DOWN_BLOCK:
        setSubRoadItems(x, y, width, height, 5, 5, 11, 10);
        break;
    case RoadType::Type::MIDDLE:
        setSubRoadItems(x, y, width, height, 5, 5, 5, 5);
        break;
    default:
        std::cerr << "RoadItem::setRoadPixmapItems() error: invalid type: "
                    << std::endl;
        exit(1);
    }
  }

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // painter->drawPixmap(QPointF(unit_->x(), unit_->y()),
    // current_pixmap_item_->pixmap());
    // assert(current_pixmap_item_ != nullptr);
    for (auto &sub_road_item : sub_road_items_) {
    //   sub_road_item->paint(painter, option, widget);
    }
  }

private:
  void setSubRoadItems(const Xaxis x, const Yaxis y, const Width width,
                       const Height height, const int sub_type1,
                       const int sub_type2, const int sub_type3,
                       const int sub_type4) {
    auto sub_width = width / 2;
    auto sub_height = height / 2;
    // setSubRoadPixmapItem(x, y, sub_width, sub_height, sub_type1);
    // setSubRoadPixmapItem(x + sub_width, y, sub_width, sub_height, sub_type2);
    // setSubRoadPixmapItem(x, y + sub_height, sub_width, sub_height, sub_type3);
    // setSubRoadPixmapItem(x + sub_width, y + sub_height, sub_width, sub_height,
    //                      sub_type4);
    setSubRoadPixmapItem(0, 0, sub_width, sub_height, sub_type1);
    setSubRoadPixmapItem(sub_width, 0, sub_width, sub_height, sub_type2);
    setSubRoadPixmapItem(0, sub_height, sub_width, sub_height, sub_type3);
    setSubRoadPixmapItem(sub_width, sub_height, sub_width, sub_height,
                         sub_type4);
  }

  void setSubRoadPixmapItem(const Xaxis x, const Yaxis y, const Width width,
                            const Height height, const int sub_type) {

    auto sub_pix_path = ":/map/road/road_" + std::to_string(sub_type) + ".png";
    auto sub_pix = QPixmap(sub_pix_path.c_str());
    auto sub_pix_item = new QGraphicsPixmapItem(
        sub_pix.scaled(width, height, Qt::IgnoreAspectRatio,
                       Qt::SmoothTransformation),
        this);

    sub_pix_item->setPos(x, y);
    // sub_road_items_.push_back(sub_pix_item);
  }

private:
  RoadItemType road_type_;
  std::vector<QGraphicsPixmapItem *> sub_road_items_;
};

} // namespace krw::gui

#endif // ROADITEM_H