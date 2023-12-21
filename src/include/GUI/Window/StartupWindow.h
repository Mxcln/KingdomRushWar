/**
 * @file StartupWindow.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef STARTUP_WINDOW_H
#define STARTUP_WINDOW_H

#include <QLabel>
#include <QPushButton>

namespace krw::gui {

class GameModeWindow;

class StartupWindow : public QWidget {
  Q_OBJECT

public:
  StartupWindow(QWidget *parent = nullptr);
  ~StartupWindow();

signals:

  void startGame();

private slots:

  void onStartButtonClicked();
  void onExitButtonClicked();
  void onSettingButtonClicked();

  void onGameModeWindowClosed();

private:
  void initUI();
  void initConnections();

  QLabel *bg_label_;
  QPushButton *start_button_;
  QPushButton *exit_button_;
  QPushButton *setting_button_;

  GameModeWindow *game_mode_window_;

  const int kButtonWidth = 200;
  const int kButtonHeight = 50;

  const int kStartButtonX = 350;
  const int kStartButtonY = 300;

  const int kExitButtonX = 350;
  const int kExitButtonY = 400;

  const int kSettingButtonX = 350;
  const int kSettingButtonY = 500;

}; // class StartupWindow

} // namespace krw::gui

#endif // STARTUP_WINDOW_H