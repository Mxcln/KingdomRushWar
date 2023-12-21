/**
 * @file KRWButton.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef KRWBUTTON_H
#define KRWBUTTON_H

#include <QMediaPlayer>
#include <QPixmap>
#include <QPushButton>
#include <qpixmap.h>

namespace krw::gui {

/// @brief Button of kingdom rush war.
/// Every button in kingdom rush war should inherit this class.
/// Each button show a image and can be clicked. When clicked, it will emit a signal.
/// Also, when clicked, it will show a different image and play a sound.

class KRWButton : public QPushButton {
  Q_OBJECT

 public:
  KRWButton(QWidget* parent = nullptr);
  ~KRWButton();

  /// @brief Set the image of button.
  /// @param image_path The path of image.
  void setImage(const QString& image_path);

  /// @brief Set the image of button when clicked.
  /// @param image_path The path of image.
  void setClickedImage(const QString& image_path);

  /// @brief Set the sound of button.
  /// @param sound_path The path of sound.
  void setSound(const QString& sound_path);

private slots:

  void onButtonClicked();


private:
  QString sound_path_;

  QPixmap normal_image_;
  QPixmap clicked_image_;

  QPushButton* button_;
  QMediaPlayer* player_;

};  // class KRWButton

}  // namespace krw::gui

#endif  // KRWBUTTON_H