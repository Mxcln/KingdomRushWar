/**
 * @file GameWindow.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "GUI/Item/Unit/WizardUnitItem.h"
#include <Basic.h>

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace krw::gui {

class UnitItemGroup;
class MapScene;
class GuiUpdater;

class MyModel {
public:
  MyModel() {}
  ~MyModel() {}

  int x;
  int y;
  int w;
  int h;
};

class MyItem : public QGraphicsItem {
public:
  MyItem(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent) {
    model.x = 100;
    model.y = 100;
    model.w = 50;
    model.h = 50;
    // pixmaps[0].load("./assets/wizard_walk0.png");
    // pixmaps[1].load("./assets/wizard_walk2.png");
    pixmaps.push_back(QPixmap(":/character/wizard/wizard_walk0.png")
                          .scaled(model.w, model.h));
    pixmaps.push_back(QPixmap(":/character/wizard/wizard_walk2.png")
                          .scaled(model.w, model.h));
  }

  QRectF boundingRect() const override {
    return QRectF(model.x, model.y, model.w, model.h);
  }

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override {
    // painter->drawRect(model.x, model.y, 100, 100);
    painter->drawPixmap(model.x, model.y, model.w, model.h,
                        pixmaps[currentPixmapIndex]);
  }

  MyModel model;
  std::vector<QPixmap> pixmaps;
  int currentPixmapIndex = 0;
};

/// @brief Game window of kingdom rush war
class GameWindow : public QGraphicsView {
  Q_OBJECT

public:
  GameWindow(QWidget *parent = nullptr);
  ~GameWindow();

  void keyPressEvent(QKeyEvent *event) override;

  void update();

private:
  void initMapScene();

private:
  GuiUpdater *gui_updater_;

  QGraphicsScene *scene_;

  MapScene *map_scene_;
  UnitItemGroup *player1_unit_item_group_;
  UnitItemGroup *player2_unit_item_group_;

  WizardUnitItem *wizard_unit_item_player1_;
  MyItem *my_item_;

}; // class GameWindow

} // namespace krw::gui

#endif // GAMEWINDOW_H