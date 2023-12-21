/**
 * @file GameModeWindow.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GAMEMODEWINDOW_H
#define GAMEMODEWINDOW_H

#include <QLabel>

namespace krw::gui {

class KRWButton;
class CancelButton;

/// @brief Game mode window of kingdom rush war.
/// user can choose game mode in this window : single player or multiplayer.
/// also user can choose to play online or offline.
/// also user can choose the difficulty of game : easy, normal, hard, impossible. But 
/// only if user choose single player mode and offline mode.

class GameModeWindow : public QWidget {
  Q_OBJECT

 public:
  GameModeWindow(QWidget* parent = nullptr);
  ~GameModeWindow();

 signals:

  void startGame();

  
 private:
  void initUI();
  void initConnections();

 private slots:

  void onStartButtonClicked();
  void onCancelButtonClicked();

 private:

  QLabel *bg_label_;

  KRWButton* start_button_;
  CancelButton* cancel_button_;

};  // class GameModeWindow


}  // namespace krw::gui

#endif  // GAMEMODEWINDOW_H