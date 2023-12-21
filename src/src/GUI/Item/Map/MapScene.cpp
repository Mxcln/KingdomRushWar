/**
 * @file MapScene.cpp
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <GUI/Item/Map/MapScene.h>
#include <GUI/Item/Map/RoadItem.h>
#include <Settings.h>

#include <QFile>
#include <QXmlStreamReader>
#include <qgraphicsgridlayout.h>

using namespace krw::gui;

MapScene::MapScene(QGraphicsItem *parent) : QGraphicsWidget(parent) {
  auto settings = Settings::instance();
  setGeometry(0, 0, settings->windowWidth(), settings->windowHeight());

  //   grid_layout_ = new QGraphicsGridLayout();
  //   setLayout(grid_layout_);

  readMapFile(":/test.xml");

  //   readMapFile(settings->mapPath());
  //   setSceneRect(0, 0, settings->windowWidth(), settings->windowHeight());
  //   for (auto &item : map_items_) {
  //     addItem(item);
  //   }
}

void MapScene::readMapFile(const std::string &path) {
  auto settings = Settings::instance();
  // parse the xml file

  // we'll parse the example.xml
  QFile file(path.c_str());
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Error: Cannot read file " << file.errorString();
    return;
  }
  QXmlStreamReader reader(&file);
  while (!reader.atEnd() && !reader.hasError()) {
    // Read next element
    auto token = reader.readNext();
    // If token is just StartDocument - go to next
    if (token == QXmlStreamReader::StartDocument) {
      continue;
    }
    // If token is StartElement - read it
    if (token == QXmlStreamReader::StartElement) {
      auto name = reader.name().toString();
      if (name == "map") {
      } else if (name == "width") {
        width_ = reader.readElementText().toInt();
        settings->setMapWidth(width_);
        settings->setBlockWidth(settings->windowWidth() / width_);
        reader.readNext();
      } else if (name == "height") {
        height_ = reader.readElementText().toInt();
        settings->setMapWidth(height_);
        settings->setBlockWidth(settings->windowHeight() / height_);
        map_items_.resize(width_ * height_);
        reader.readNext();
      } else if (name == "id") {
        auto id = reader.readElementText().toInt();
        reader.readNext();
        reader.readNext();
        auto type_name = reader.readElementText().toStdString();
        // qDebug() << type_name;
        auto type = MapType::toType(type_name);
        auto x = (id % width_) * settings->blockWidth();
        auto y = (id / width_) * settings->blockHeight();

        if (type == MapType::Type::ROAD) {
          reader.readNext();
          reader.readNext();
          auto road_type_name = reader.readElementText().toStdString();
          auto road_type = RoadType::toType(road_type_name);
          map_items_[id] = new RoadItem(road_type, x, y, settings->blockWidth(),
                                        settings->blockHeight(), this);
        } else {
          if (map_items_[id] == nullptr) {
            map_items_[id] = new MapItem(type, x, y, settings->blockWidth(),
                                         settings->blockHeight(), this);
          } else {
            map_items_[id]->addPixelMapItem(type);
          }
          reader.readNext();
        }
      }
    }
  }
}

  // void MapScene::paint(QPainter *painter, const QStyleOptionGraphicsItem
  // *option,
  //                      QWidget *widget) {
  //   Q_UNUSED(option);
  //   Q_UNUSED(widget);
  //   //   painter->setPen(Qt::NoPen);
  //   //   painter->setBrush(Qt::darkGray);
  //   //   painter->drawRect(boundingRect());
  // }