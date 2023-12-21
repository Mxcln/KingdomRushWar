/**
 * @file GameWindow.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Basic.h"
#include <GUI/GuiUpdater.h>
#include <GUI/Item/Unit/UnitItemGroup.h>
#include <GUI/Item/Map/MapScene.h>
#include <GUI/Window/GameWindow.h>

#include <GUI/Item/Unit/WizardUnitItem.h>

#include <QFile>
#include <qgraphicsview.h>

using namespace krw::gui;

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {

  setCacheMode(CacheBackground);

  gui_updater_ = new GuiUpdater(this);
  connect(gui_updater_, &GuiUpdater::update, this, &GameWindow::update);

  // set scene
  scene_ = new QGraphicsScene(this);
  this->setScene(scene_);

  // set background
  QPixmap background(":/background.png");
  scene_->setBackgroundBrush(background.scaled(kWindowWidth, kWindowHeight,
                                               Qt::IgnoreAspectRatio,
                                               Qt::SmoothTransformation));

  initMapScene();

  // testing wizard

  // testing unit item group
  player1_unit_item_group_ = new UnitItemGroup();
  scene_->addItem(player1_unit_item_group_);
  player2_unit_item_group_ = new UnitItemGroup();
  scene_->addItem(player2_unit_item_group_);

  // wizard_unit_item_player1_ =
  //     new WizardUnitItem(200, 600, 50, 50, player1_unit_item_group_);
  // wizard_unit_item_player1_->setSpeed(10);
  // player1_unit_item_group_->AddUnitItem(wizard_unit_item_player1_);
  // WizardUnitItem *wizard_unit_item_player2 =
  //     new WizardUnitItem(1180, 620, 50, 50, player2_unit_item_group_);
  // player2_unit_item_group_->AddUnitItem(wizard_unit_item_player2);

  wizard_unit_item_player1_ =
      new WizardUnitItem(200, 500, 50, 50, nullptr);
  wizard_unit_item_player1_->setSpeed(10);
  scene_->addItem(wizard_unit_item_player1_);

  my_item_ = new MyItem();
  scene_->addItem(my_item_);

  // set view
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setSceneRect(0, 0, kWindowWidth, kWindowHeight);

  gui_updater_->start();
}

GameWindow::~GameWindow() {
  gui_updater_->stop();
  
}

void GameWindow::initMapScene() {
  map_scene_ = new MapScene();
  scene_->addItem(map_scene_);
}

void GameWindow::keyPressEvent(QKeyEvent *event) {
  // up, down, left, right
  if (event->key() == Qt::Key_W) {
    wizard_unit_item_player1_->move(Direction::UP);
    my_item_->model.y -= 10;
  } else if (event->key() == Qt::Key_S) {
    wizard_unit_item_player1_->move(Direction::DOWN);
    my_item_->model.y += 10;
  } else if (event->key() == Qt::Key_A) {
    wizard_unit_item_player1_->move(Direction::LEFT);
  } else if (event->key() == Qt::Key_D) {
    wizard_unit_item_player1_->move(Direction::RIGHT);
  }
  QGraphicsView::keyPressEvent(event);
}

void GameWindow::update() {
  // QGraphicsView::update();
  QGraphicsView::viewport()->update();
}