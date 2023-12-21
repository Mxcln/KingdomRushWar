/**
 * @file StartupWindow.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <GUI/Window/StartupWindow.h>
#include <GUI/Window/GameModeWindow.h>
#include <Basic.h>

#include <QHBoxLayout>

using namespace krw::gui;

StartupWindow::StartupWindow(QWidget* parent) : QWidget(parent) {
  initUI();
  initConnections();
}

StartupWindow::~StartupWindow() {}

void StartupWindow::initUI() {

//   this->setGeometry(0, 0, kWindowWidth, kWindowHeight);

  auto layout = new QHBoxLayout(this);

  // load startup image
  bg_label_ = new QLabel(this);
  QPixmap startup_image("./assets/image/startup.png");
  bg_label_->setPixmap(startup_image);
//   bg_label_->setGeometry(0, 0, kWindowWidth, kWindowHeight);
  bg_label_->setScaledContents(true);

  // TODO : set button size and position and image
  // button
  start_button_ = new QPushButton(this);
  start_button_->setText("Start");
  start_button_->setGeometry(kStartButtonX, kStartButtonY, kButtonWidth, kButtonHeight);

  exit_button_ = new QPushButton(this);
  exit_button_->setText("Exit");
  exit_button_->setGeometry(kExitButtonX, kExitButtonY, kButtonWidth, kButtonHeight);

  setting_button_ = new QPushButton(this);
  setting_button_->setText("Setting");
  setting_button_->setGeometry(kSettingButtonX, kSettingButtonY, kButtonWidth, kButtonHeight);

  // dialog
  game_mode_window_ = new GameModeWindow(this);
  game_mode_window_->hide();
//   game_mode_window_->setModal(true);

  layout->addWidget(bg_label_);
  
}

void StartupWindow::initConnections() {
  // TODO : connect button to slot
  connect(start_button_, &QPushButton::clicked, this, &StartupWindow::onStartButtonClicked);
  connect(exit_button_, &QPushButton::clicked, this, &StartupWindow::onExitButtonClicked);
  connect(setting_button_, &QPushButton::clicked, this, &StartupWindow::onSettingButtonClicked);
  
  connect(game_mode_window_, &GameModeWindow::startGame, this, &StartupWindow::startGame);
}

void StartupWindow::onStartButtonClicked() {
  // TODO : start game
  game_mode_window_->show();
  
}

void StartupWindow::onExitButtonClicked() {
  // TODO : exit game
//   QApplication::exit();
}

void StartupWindow::onSettingButtonClicked() {
  // TODO : setting game
}

void StartupWindow::onGameModeWindowClosed() {
  // TODO : close game mode window
//   game_mode_window_->close();
}