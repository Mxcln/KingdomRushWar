/**
 * @file KRWWidget.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <GUI/UI/KRWButton.h>

#include <QPixmap>

using namespace krw::gui;

KRWButton::KRWButton(QWidget* parent) : QPushButton(parent) {
  // hide the border
  this->setFlat(true);
  // when clicked, also hide the border
  this->setFocusPolicy(Qt::NoFocus);
}

KRWButton::~KRWButton() {}

void KRWButton::setImage(const QString& image_path) {
  // normal_image_ = QPixmap(image_path);
  // this->setIcon(QIcon(normal_image_));
  this->setStyleSheet("QPushButton{border-image: url(" + image_path + ")}");
  // scale the image to fit the button
}

void KRWButton::setClickedImage(const QString& image_path) {
  QPixmap* pixmap = new QPixmap(image_path);
  this->setStyleSheet("QPushButton:pressed {border-image: url(" + image_path + ");}");
  this->setIcon(QIcon(*pixmap));
  this->setIconSize(QSize(pixmap->width(), pixmap->height()));
  this->setFixedSize(pixmap->width(), pixmap->height());
}

void KRWButton::setSound(const QString& sound_path) {
  sound_path_ = sound_path;
}

void KRWButton::onButtonClicked() {
  // play sound

  

}