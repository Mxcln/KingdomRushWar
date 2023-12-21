/**
 * @file CancelButton.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CANCEL_BUTTON_H
#define CANCEL_BUTTON_H

#include <GUI/UI/KRWButton.h>

namespace krw::gui {

class CancelButton : public KRWButton {
  Q_OBJECT

 public:
  CancelButton(QWidget* parent = nullptr);
  ~CancelButton();

};  // class CancelButton

}  // namespace krw::gui

#endif  // CANCEL_BUTTON_H