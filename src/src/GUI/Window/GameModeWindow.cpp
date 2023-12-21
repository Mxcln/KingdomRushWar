/**
 * @file GameModeWindow.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <GUI/Window/GameModeWindow.h>
#include <GUI/UI/CancelButton.h>

#include <QGridLayout>

using namespace krw::gui;

GameModeWindow::GameModeWindow(QWidget* parent) : QWidget(parent) {
  initUI();
  initConnections();
}

GameModeWindow::~GameModeWindow() {}

void GameModeWindow::initUI() {
  setFixedSize(800, 400);

  auto layout = new QGridLayout(this);

  bg_label_ = new QLabel(this);
  // bg_label_->setGeometry(0, 0, width(), height());
  QPixmap startup_image("./assets/pic/game_options.png");
  bg_label_->setPixmap(startup_image);
  bg_label_->setScaledContents(true);

  start_button_ = new KRWButton(this);
  start_button_->setText("Start");
//   start_button_->setImage(":/images/start_button.png");
//   start_button_->setClickedImage(":/images/start_button_clicked.png");
//   start_button_->setSound(":/sounds/button_clicked.wav");
  // start_button_->setGeometry(300, 400, 200, 100);

  cancel_button_ = new CancelButton(this);

  // layout->addWidget(start_button_, 0, 0, 1, 1, Qt::AlignCenter);
  // layout->addWidget(cancel_button_, 1, 0, 1, 1, Qt::AlignCenter);

}

void GameModeWindow::initConnections() {
  connect(start_button_, &KRWButton::clicked, this, &GameModeWindow::onStartButtonClicked);
}

void GameModeWindow::onStartButtonClicked() {
  // TODO : start game
  emit startGame();
  // this->close();
}

void GameModeWindow::onCancelButtonClicked() {
  // this->close();
}