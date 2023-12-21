/**
 * @file MainWindow.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <Basic.h>
#include <GUI/Window/MainWindow.h>
#include <GUI/Window/StartupWindow.h>
#include <GUI/Window/GameWindow.h>


#include <QApplication>

using namespace krw::gui;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  initUI();
  initConnections();
}

MainWindow::~MainWindow() {}

void MainWindow::initUI() {

  // set window size
  this->setFixedSize(kWindowWidth, kWindowHeight);

  // set the startup window
  startup_window_ = new StartupWindow(this);

  // set the game window
  game_window_ = new GameWindow(this);

  // add to stacked widget
  stacked_widget_ = new QStackedWidget(this);
  stacked_widget_->addWidget(startup_window_);
  stacked_widget_->addWidget(game_window_);
  stacked_widget_->setCurrentWidget(game_window_);
  // stacked_widget_->setGeometry(0, 0, kWindowWidth, kWindowHeight);
  this->setCentralWidget(stacked_widget_);
}

void MainWindow::initConnections() {
  // TODO : connect button to slot
  
}

void MainWindow::startGame() {
  // TODO : start game
  // this->close();
}
