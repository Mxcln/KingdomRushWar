/**
 * @file Game.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <GUI/Window/MainWindow.h>

namespace krw::core {

class Game {

 public:
  Game(int argc, char* argv[]);
  ~Game();

  int start();

 private:
  QApplication app_;
  gui::MainWindow main_window_;

};  // class Game

}  // namespace krw::core

#endif  // GAME_H