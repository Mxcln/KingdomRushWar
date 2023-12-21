cmake_minimum_required(VERSION 3.15)

project(KingdomRushWar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    set(CMAKE_PROJECT_INCLUDE_BEFORE "/Users/yang/Qt/Qt Creator.app/Contents/Resources/package-manager/auto-setup.cmake")
else ()
    set(CMAKE_PROJECT_INCLUDE_BEFORE "/opt/Qt/Tools/QtCreator/share/qtcreator/package-manager/auto-setup.cmake")
endif()

set(CMAKE_PREFIX_PATH "/opt/Qt/6.4.3/gcc_64")

find_package(QT NAMES Qt6 REQUIRED Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Xml Core Gui)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/include)

FILE(GLOB_RECURSE ALL_SRCS "./src/src/**/*.cpp" "./src/include/**/*.h")

set(MAIN_SRC ./src/main.cpp)
set(PROJECT_SOURCES ${MAIN_SRC} ${ALL_SRCS})

configure_file(${CMAKE_SOURCE_DIR}/src/Config.h.in ${CMAKE_SOURCE_DIR}/src/Config.h)

FILE(GLOB_RECURSE QRC_FILE "./assets/**/*.qrc")
# set(RESOURCES_FILE ${CMAKE_SOURCE_DIR}/src/res/pic.qrc)

if(APPLE)
    set(MACOSX_BUNDLE_ICON_FILE mac_icon.icns)
    set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/assets/icon/KingdomRushWar.icns")
    set_source_files_properties(${app_icon_macos} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION MACOSX_BUNDLE ${PROJECT_SOURCES} ${QRC_FILE} ${app_icon_macos})
else()
    qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION ${PROJECT_SOURCES} ${QRC_FILE} )
endif()

# Copy assets to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

# Link Libraries
# target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Xml Qt6::Multimedia)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER fudan.edu.cn
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Set Output Path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Set _d suffix for debug build
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}$<$<CONFIG:Debug>:_d>")

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
