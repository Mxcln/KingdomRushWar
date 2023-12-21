/**
 * @file PixelLoader.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <GUI/PixelLoader.h>

using namespace krw::gui;

PixelLoader* PixelLoader::instance() {
  static PixelLoader pixel_loader;
  return &pixel_loader;
}

const QPixmap& PixelLoader::load(const QString& path) {
    if (instance()->pixmaps_.find(path) == instance()->pixmaps_.end()) {
        instance()->pixmaps_[path] = QPixmap(path);
    }
    return instance()->pixmaps_[path];
}

const QPixmap& PixelLoader::load(const QString& path, const int width, const int height) {
  if (instance()->pixmaps_.find(path) == instance()->pixmaps_.end()) {
    instance()->pixmaps_[path] = QPixmap(path).scaled(width, height);
  }
  return instance()->pixmaps_[path];
}