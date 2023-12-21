/**
 * @file MapItem.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAPITEM_H
#define MAPITEM_H

#include <GUI/GUI.h>
#include <GUI/Item/Map/MapType.h>
#include <GUI/Item/SimpleItem.h>

namespace krw::gui {

class MapItem : public SimpleItem {
public:
  MapItem(QGraphicsItem *parent = nullptr);
  MapItem(const MapItemType type, const Xaxis x, const Yaxis y,
          const Width width, const Height height,
          QGraphicsItem *parent = nullptr);
  ~MapItem() = default;

  void setModel(const Xaxis x, const Yaxis y, const Width width,
                const Height height) override;

  void setPixmapItems() override;

  void setCurrentPixmapItem() override;

  void addPixelMapItem(MapItemType type);

private:
  void setDecorationPixmapItems();

  // void setRoadPixmapItems(const MapType::RoadType type1,
  //                         const MapType::RoadType type2,
  //                         const MapType::RoadType type3,
  //                         const MapType::RoadType type4);

private:
  MapItemType type_;
};

} // namespace krw::gui

#endif // MAPITEM_H