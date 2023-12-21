/**
 * @file GameEndWindow.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GAMEENDWINDOW_H
#define GAMEENDWINDOW_H

#include <QDialog>

namespace krw::gui {

class KRWButton;

class GameEndWindow : public QDialog {
  Q_OBJECT

 public:
  GameEndWindow(QWidget* parent = nullptr);
  ~GameEndWindow();

 private:
  void initUI();
  void initConnections();

 private slots:

  void onRestartButtonClicked();
  void onExitButtonClicked();

 private:
  KRWButton* restart_button_;
  KRWButton* exit_button_;
};


}  // namespace krw::gui

#endif  // GAMEENDWINDOW_H