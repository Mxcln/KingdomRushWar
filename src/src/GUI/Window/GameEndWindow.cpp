/**
 * @file GameEndWindow.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <GUI/UI/KRWButton.h>
#include <GUI/Window/GameEndWindow.h>

using namespace krw::gui;

GameEndWindow::GameEndWindow(QWidget *parent) : QDialog(parent) {
  initUI();
  initConnections();
}

GameEndWindow::~GameEndWindow() {}

void GameEndWindow::initUI() {
  setFixedSize(800, 600);

  restart_button_ = new KRWButton(this);
  restart_button_->setText("Restart");

  exit_button_ = new KRWButton(this);
  exit_button_->setText("Exit");

  restart_button_->setGeometry(300, 400, 200, 100);
  exit_button_->setGeometry(300, 500, 200, 100);
}

void GameEndWindow::initConnections() {
  connect(restart_button_, &KRWButton::clicked, this, &GameEndWindow::onRestartButtonClicked);
  connect(exit_button_, &KRWButton::clicked, this, &GameEndWindow::onExitButtonClicked);
}

void GameEndWindow::onRestartButtonClicked() {
  // TODO : restart game
  this->close();
}

void GameEndWindow::onExitButtonClicked() {
  // TODO : exit game
//   QApplication::exit();
  this->close();
}