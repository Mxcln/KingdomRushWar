/**
 * @file main.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <Config.h>

#include <Core/Game.h>

int main(int argc, char* argv[]) {
  
  krw::core::Game game(argc, argv);
  return game.start();
}
