/**
 * @file MoveBehavior.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MOVEBEHAVIOR_H
#define MOVEBEHAVIOR_H

#include <QPixmap>

#include "Basic.h"
#include <Core/Behavior/AbstractBehavior.h>
#include <Core/Model/Unit/AbstractUnit.h>
#include <qgraphicsitem.h>
#include <qpixmap.h>

namespace krw::core {

class MoveBehavior : public AbstractBehavior {
public:
  MoveBehavior() = default;
  MoveBehavior(AbstractModel *model)
      : AbstractBehavior(model), is_moving_(false), speed_(1), direction_(Direction::UP) {}
  ~MoveBehavior() = default;


  static constexpr int kWalkPixNum = 5;
  static constexpr int kStandPixIndex = 0;

  void addPixmap(const QPixmap &pixmap) { pixmaps_.push_back(pixmap.scaled(model_->x(), model_->y())); }

  int currentPixmapIndex() const { return current_pixmap_index_; }
  QPixmap& currentPixmap() { return pixmaps_[current_pixmap_index_]; }
  void setCurrentPixmap(int index) { current_pixmap_index_ = index; }

  // void addPixmapItem(QGraphicsPixmapItem *pixmap_item) {
  //   pixmap_items_.push_back(pixmap_item);
  // }
  // QGraphicsPixmapItem *currentPixmapItem() const { return current_pixmap_item_; }
  // void setCurrentPixmapItem(QGraphicsPixmapItem *pixmap_item) { current_pixmap_item_ = pixmap_item; }

  void setSpeed(const int speed) { speed_ = speed; }
  void setDirection(const Direction direction) { direction_ = direction; }

  void move(const int speed, const Direction direction) {
    speed_ = speed;
    direction_ = direction;
    move();
  }

  void move(const Direction direction) {
    direction_ = direction;
    move();
  }

  void move() {
    qDebug() << "move";
    switch (direction_) {
    case Direction::UP:
      model_->setY(model_->y() - speed_);
      break;
    case Direction::DOWN:
      model_->setY(model_->y() + speed_);
      break;
    case Direction::LEFT:
      model_->setX(model_->x() - speed_);
      break;
    case Direction::RIGHT:
      model_->setX(model_->x() + speed_);
      break;
    default:
      break;
    }
  }

private:

  std::vector<QPixmap> pixmaps_;
  int current_pixmap_index_;
  // std::vector<QGraphicsPixmapItem *> pixmap_items_;
  // QGraphicsPixmapItem *current_pixmap_item_;

  bool is_moving_;

  int speed_;
  Direction direction_;

  // AbstractUnit *unit_;
};

} // namespace krw::core

#endif // MOVEBEHAVIOR_H