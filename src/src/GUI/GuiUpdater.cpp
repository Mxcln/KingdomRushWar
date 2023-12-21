/**
 * @file GuiUpdater.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <GUI/GUI.h>
#include <GUI/GuiUpdater.h>

using namespace krw::gui;

GuiUpdater::GuiUpdater(QObject *parent)
    : QObject(parent), timer_(new QTimer(this)), interval_(1000 / kUpdateFPS) {
  timer_->setInterval(interval_);
  connect(timer_, &QTimer::timeout, this, &GuiUpdater::update);
}

void GuiUpdater::start() { timer_->start(); }

void GuiUpdater::stop() { timer_->stop(); }

