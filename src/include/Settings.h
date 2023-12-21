/**
 * @file Settings.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>

namespace krw {

/// @brief The Settings class
/// This is a singleton class.
class Settings {
public:

  static Settings *instance() {
    static Settings *instance = new Settings();
    return instance;
  }

  Settings(Settings const &) = delete;
  void operator=(Settings const &) = delete;

  void setWindowWidth(const int width) { window_width_ = width; }
  void setWindowHeight(const int height) { window_height_ = height; }
  void setMapWidth(const int width) { map_width_ = width; }
  void setMapHeight(const int height) { map_height_ = height; }
  void setBlockWidth(const int width) { block_width_ = width; }
  void setBlockHeight(const int height) { block_height_ = height; }

  int windowWidth() const { return window_width_; }
  int windowHeight() const { return window_height_; }
  int mapWidth() const { return map_width_; }
  int mapHeight() const { return map_height_; }
  int blockWidth() const { return block_width_; }
  int blockHeight() const { return block_height_; }

private:
  Settings() = default;
  ~Settings() = default;

  int window_width_ = 1280;
  int window_height_ = 720;

  int map_width_ = 16;
  int map_height_ = 9;

  int block_width_ = 80;
  int block_height_ = 80;

}; // class Settings

} // namespace krw

#endif // SETTINGS_H