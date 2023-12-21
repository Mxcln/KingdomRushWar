/**
 * @file GuiUpdater.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GUIUPDATER_H
#define GUIUPDATER_H

#include <QTimer>
#include <qtmetamacros.h>

namespace krw::gui {

class GuiUpdater : public QObject {
  Q_OBJECT

public:
  GuiUpdater(QObject *parent = nullptr);
  ~GuiUpdater() = default;

  void start();

  void stop();
signals:

  void update();

private:
  QTimer *timer_;

  int interval_;

}; // class GuiUpdater

} // namespace krw::gui

#endif // GUIUPDATER_H