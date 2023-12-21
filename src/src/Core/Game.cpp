/**
 * @file Game.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <Core/Game.h>

using namespace krw::core;

Game::Game(int argc, char* argv[]) : app_(argc, argv), main_window_() {
    // Set Fusion style
    app_.setStyle("Fusion");
    
    // // read stylesheet
    // QFile qss(":/theme/Default.qss");
    // qss.open(QFile::ReadOnly);
    // app_.setStyleSheet(qss.readAll());
}

Game::~Game() {}

int Game::start() {
    main_window_.show();
    return app_.exec();
}