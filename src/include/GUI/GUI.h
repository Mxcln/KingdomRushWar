/**
 * @file GUI.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>
#include <GUI/PixelLoader.h>

namespace krw::gui {

constexpr static const int kWindowWidth = 1280;
constexpr static const int kWindowHeight = 720;

constexpr static const int kStatusBarHeight = 30;

constexpr static const int kGameWindowWidth = kWindowWidth;
constexpr static const int kGameWindowHeight = kWindowHeight - kStatusBarHeight;

constexpr static const int kDecorationNum = 11;

constexpr static const int kMaxRandomDecoration = 5;

constexpr static const int kUpdateFPS = 60;

using Xaxis = int;
using Yaxis = int;
using Length = int;

using Width = int;
using Height = int;

}   // namespace krw::gui

#endif  // GUI_H