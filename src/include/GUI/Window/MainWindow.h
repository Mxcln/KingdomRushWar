/**
 * @file MainWindow.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>

namespace krw::gui {

class StartupWindow;
class GameWindow;

/// @brief Main window of kingdom rush war

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void initUI();

  void initConnections();

  void startGame();

private:
  QStackedWidget *stacked_widget_;
  StartupWindow *startup_window_;
  GameWindow *game_window_;

}; // class MainWindow

} // namespace krw::gui

#endif // MAINWINDOW_H