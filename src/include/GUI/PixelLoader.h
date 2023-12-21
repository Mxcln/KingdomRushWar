/**
 * @file PixelLoader.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PIXELLOADER_H
#define PIXELLOADER_H

#include <QPixmap>
#include <qpixmap.h>

namespace krw::gui {

class PixelLoader {
 public:

  static PixelLoader* instance();

  static const QPixmap& load(const QString& path);
  
  static const QPixmap& load(const QString& path, const int width, const int height);

private:
  PixelLoader() = default;
  ~PixelLoader() = default;

//   void loadAll();
  
  std::unordered_map<QString, QPixmap> pixmaps_;

};

} // namespace krw::gui

#endif // PIXELLOADER_H