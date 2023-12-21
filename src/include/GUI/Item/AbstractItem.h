/**
 * @file AbstractItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <Basic.h>
#include <Core/Model/Unit/AbstractUnit.h>

#include <QGraphicsItem>

namespace krw::gui {

class AbstractUnit;
class AbstractAdditionalItem;

class AbstractItem : public QGraphicsItem {
public:
  AbstractItem(QGraphicsItem *parent = nullptr);
  AbstractItem(const Xaxis x, const Yaxis y, const Width width,
               const Height height, QGraphicsItem *parent = nullptr);
  virtual ~AbstractItem() = default;

  QRectF boundingRect() const override;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

  virtual void setModel(const Xaxis x, const Yaxis y, const Width width,
                        const Height height) = 0;

  virtual void setCurrentPixmapItem() = 0;

  virtual void setPixmapItems() = 0;

  virtual void setAdditionalItems() = 0;

  virtual void paintAdditionalItems() = 0;

protected:
  core::AbstractModel* model_;
  // core::AbstractModel* model_;
  std::vector<QGraphicsPixmapItem *> pixmap_items_;
  QGraphicsPixmapItem *current_pixmap_item_;

  std::vector<AbstractAdditionalItem *> additional_items_;
};

} // namespace krw::gui

#endif // ABSTRACTITEM_H