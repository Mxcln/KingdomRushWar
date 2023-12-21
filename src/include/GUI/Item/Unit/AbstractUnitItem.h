/**
 * @file AbstractUnitItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ABSTRACTUNITITEM_H
#define ABSTRACTUNITITEM_H

#include <GUI/Item/AbstractItem.h>
#include <QGraphicsItem>
#include <qpixmap.h>

namespace krw::gui {

/// @brief Abstract class of unit item.
/// Each unit item presents a unit in the game.

class AbstractUnitItem : public AbstractItem {
 public:
  AbstractUnitItem(QGraphicsItem* parent = nullptr);
  AbstractUnitItem(const Xaxis x, const Yaxis y, const Width width,
                   const Height height, QGraphicsItem* parent = nullptr);
  virtual ~AbstractUnitItem() = default;

protected:

  // std::vector<QPixmap> pixmaps_;
  // QPixmap* current_pixmap_;

};

}   // namespace krw::gui

#endif  // ABSTRACTUNITITEM_H