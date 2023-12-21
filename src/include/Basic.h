/**
 * @file Basic.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BASIC_H
#define BASIC_H

#include <memory>

namespace krw {

constexpr static const int kWindowWidth = 1280;
constexpr static const int kWindowHeight = 720;

constexpr static const int kStatusBarHeight = 30;

constexpr static const int kGameWindowWidth = kWindowWidth;
constexpr static const int kGameWindowHeight = kWindowHeight - kStatusBarHeight;

// rename std::unique_ptr
template <typename T>
using Uptr = std::unique_ptr<T>;

using Xaxis = int;
using Yaxis = int;
using Length = int;

using Width = int;
using Height = int;

constexpr static const int kUnitItemZ = 1;

enum class Direction { 
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

}   // namespace krw

#endif  // BASIC_H