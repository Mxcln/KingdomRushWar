/**
 * @file CancelButton.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <GUI/UI/CancelButton.h>

using namespace krw::gui;

CancelButton::CancelButton(QWidget* parent) : KRWButton(parent) {
  setImage("./assets/pic/cancel_button.png");
  setClickedImage("./assets/pic/cancel_button.png");

  setFixedSize(50, 50);
}

CancelButton::~CancelButton() {}