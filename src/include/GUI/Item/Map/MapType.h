/**
 * @file MapType.h
 * @author Mxcln (windayau233@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MAPTYPE_H
#define MAPTYPE_H

#include <GUI/GUI.h>

#include <string>

namespace krw::gui {

class RoadType {
public:
  enum class Type {
    HORIZONTAL = 0,
    VERTICAL,
    LEFT_UP,
    LEFT_DOWN,
    RIGHT_UP,
    RIGHT_DOWN,
    LEFT_UP_BLOCK,
    LEFT_DOWN_BLOCK,
    RIGHT_UP_BLOCK,
    RIGHT_DOWN_BLOCK,
    LEFT_BLOCK,
    RIGHT_BLOCK,
    UP_BLOCK,
    DOWN_BLOCK,
    MIDDLE
  };

//   enum class SubType {

//   }

  static std::string toString(RoadType::Type type) {
    switch (type) {
    case RoadType::Type::HORIZONTAL:
      return "horizontal";
    case RoadType::Type::VERTICAL:
      return "vertical";
    case RoadType::Type::LEFT_UP:
      return "left_up";
    case RoadType::Type::LEFT_DOWN:
      return "left_down";
    case RoadType::Type::RIGHT_UP:
      return "right_up";
    case RoadType::Type::RIGHT_DOWN:
      return "right_down";
    case RoadType::Type::LEFT_UP_BLOCK:
      return "left_up_block";
    case RoadType::Type::LEFT_DOWN_BLOCK:
      return "left_down_block";
    case RoadType::Type::RIGHT_UP_BLOCK:
      return "right_up_block";
    case RoadType::Type::RIGHT_DOWN_BLOCK:
      return "right_down_block";
    case RoadType::Type::LEFT_BLOCK:
      return "left_block";
    case RoadType::Type::RIGHT_BLOCK:
      return "right_block";
    case RoadType::Type::UP_BLOCK:
      return "up_block";
    case RoadType::Type::DOWN_BLOCK:
      return "down_block";
    case RoadType::Type::MIDDLE:
      return "middle";
    default:
      std::cerr << "RoadType::toString() error: invalid type" << std::endl;
      exit(1);
    }
  }

  static RoadType::Type toType(const std::string type) {
    if (type == "horizontal") {
      return RoadType::Type::HORIZONTAL;
    } else if (type == "vertical") {
      return RoadType::Type::VERTICAL;
    } else if (type == "left_up") {
      return RoadType::Type::LEFT_UP;
    } else if (type == "left_down") {
      return RoadType::Type::LEFT_DOWN;
    } else if (type == "right_up") {
      return RoadType::Type::RIGHT_UP;
    } else if (type == "right_down") {
      return RoadType::Type::RIGHT_DOWN;
    } else if (type == "left_up_block") {
      return RoadType::Type::LEFT_UP_BLOCK;
    } else if (type == "left_down_block") {
      return RoadType::Type::LEFT_DOWN_BLOCK;
    } else if (type == "right_up_block") {
      return RoadType::Type::RIGHT_UP_BLOCK;
    } else if (type == "right_down_block") {
      return RoadType::Type::RIGHT_DOWN_BLOCK;
    } else if (type == "left_block") {
      return RoadType::Type::LEFT_BLOCK;
    } else if (type == "right_block") {
      return RoadType::Type::RIGHT_BLOCK;
    } else if (type == "up_block") {
      return RoadType::Type::UP_BLOCK;
    } else if (type == "down_block") {
      return RoadType::Type::DOWN_BLOCK;
    } else if (type == "middle") {
      return RoadType::Type::MIDDLE;
    } else {
      std::cerr << "RoadType::toType() error: invalid type: "
                << type<< std::endl;
      exit(1);
    }
  }


};  // class RoadType

class MapType {
public:

  enum class Type {
    GRASS = 0,
    TREE1,
    TREE2,
    TREE3,
    TREE4,
    ROCK1,
    ROCK2,
    ROCK3,
    ROCK4,
    RIVER_1,
    RIVER_2,
    RIVER_3,
    RIVER_4,
    RIVER_H,
    RIVER_V,
    // ROAD_1,
    // ROAD_2,
    // ROAD_3,
    // ROAD_4,
    // ROAD_H,
    // ROAD_V,
    ROAD,
    BRIDGE_H,
    BRIDGE_V
  };

  static std::string toString(MapType::Type type) {
    switch (type) {
    case MapType::Type::GRASS:
      return "grass";
    case MapType::Type::TREE1:
      return "tree1";
    case MapType::Type::TREE2:
      return "tree2";
    case MapType::Type::TREE3:
      return "tree3";
    case MapType::Type::TREE4:
      return "tree4";
    case MapType::Type::ROCK1:
      return "rock1";
    case MapType::Type::ROCK2:
      return "rock2";
    case MapType::Type::ROCK3:
      return "rock3";
    case MapType::Type::ROCK4:
      return "rock4";
    case MapType::Type::RIVER_1:
      return "river_1";
    case MapType::Type::RIVER_2:
      return "river_2";
    case MapType::Type::RIVER_3:
      return "river_3";
    case MapType::Type::RIVER_4:
      return "river_4";
    case MapType::Type::RIVER_H:
      return "river_h";
    case MapType::Type::RIVER_V:
      return "river_v";
    // case MapType::Type::ROAD_1:
    //   return "road_1";
    // case MapType::Type::ROAD_2:
    //   return "road_2";
    // case MapType::Type::ROAD_3:
    //   return "road_3";
    // case MapType::Type::ROAD_4:
    //   return "road_4";
    // case MapType::Type::ROAD_H:
    //   return "road_h";
    // case MapType::Type::ROAD_V:
    //   return "road_v";
    case MapType::Type::ROAD:
      return "road";
    case MapType::Type::BRIDGE_H:
      return "bridge_h";
    case MapType::Type::BRIDGE_V:
      return "bridge_v";
    default:
      std::cerr << "MapType::toString() error: invalid type" << std::endl;
      exit(1);
    }
  }

  static MapType::Type toType(const std::string type) {
    if (type == "grass") {
      return MapType::Type::GRASS;
    } else if (type == "tree1") {
      return MapType::Type::TREE1;
    } else if (type == "tree2") {
      return MapType::Type::TREE2;
    } else if (type == "tree3") {
      return MapType::Type::TREE3;
    } else if (type == "tree4") {
      return MapType::Type::TREE4;
    } else if (type == "rock1") {
      return MapType::Type::ROCK1;
    } else if (type == "rock2") {
      return MapType::Type::ROCK2;
    } else if (type == "rock3") {
      return MapType::Type::ROCK3;
    } else if (type == "rock4") {
      return MapType::Type::ROCK4;
    } else if (type == "river_1") {
      return MapType::Type::RIVER_1;
    } else if (type == "river_2") {
      return MapType::Type::RIVER_2;
    } else if (type == "river_3") {
      return MapType::Type::RIVER_3;
    } else if (type == "river_4") {
      return MapType::Type::RIVER_4;
    } else if (type == "river_h") {
      return MapType::Type::RIVER_H;
    } else if (type == "river_v") {
      return MapType::Type::RIVER_V;
      // } else if (type == "road_1") {
      //   return MapType::Type::ROAD_1;
      // } else if (type == "road_2") {
      //   return MapType::Type::ROAD_2;
      // } else if (type == "road_3") {
      //   return MapType::Type::ROAD_3;
      // } else if (type == "road_4") {
      //   return MapType::Type::ROAD_4;
      // } else if (type == "road_h") {
      //   return MapType::Type::ROAD_H;
      // } else if (type == "road_v") {
      //   return MapType::Type::ROAD_V;
    } else if (type == "road") {
      return MapType::Type::ROAD;
    } else if (type == "bridge_h") {
      return MapType::Type::BRIDGE_H;
    } else if (type == "bridge_v") {
      return MapType::Type::BRIDGE_V;
    } else {
      std::cerr << "MapType::toType() error: invalid type: "
                << type<< std::endl;
      exit(1);
    }
  }

}; // class MapItemType

using MapItemType = MapType::Type;
using RoadItemType = RoadType::Type;

}   // namespace krw::gui

#endif  // MAPTYPE_H