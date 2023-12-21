/**
 * @file MapScene.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <GUI/GUI.h>

#include <QGraphicsWidget>
#include <QGraphicsGridLayout>

namespace krw::gui {

class MapItem;

class MapScene : public QGraphicsWidget {
    Q_OBJECT
public:
  MapScene(QGraphicsItem *parent = nullptr);
  //   MapScene(const Xaxis x, const Yaxis y, const Width width, const Height
  //   height,
  //            QGraphicsItem *parent = nullptr);
  ~MapScene() = default;

  //   void setMapItems();

  // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
  //            QWidget *widget) override;

  // QRectF boundingRect() const override {
  //   return QRectF(0, 0, kWindowWidth, kWindowHeight);
  // }

  void readMapFile(const std::string &path);

private:
  //   std::unique_ptr<core::AbstractModel> model_;
  int width_;
  int height_;
  std::vector<MapItem *> map_items_;

//   QGraphicsGridLayout *grid_layout_;
};

} // namespace krw::gui

#endif // MAPSCENE_H