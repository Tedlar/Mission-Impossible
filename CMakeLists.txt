cmake_minimum_required(VERSION 3.0)
project(MissionImpossible)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE headers src/*.h)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -fPIC")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(AUTORCC_OPTIONS "qml.qrc")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#FILE(GLOB QML_FILES "${CMAKE_CURRENT_SOURCE_DIR}/res/*.qml")
FILE(GLOB QRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.qrc")
MESSAGE( STATUS "QRC: " ${QRC_FILES} )
MESSAGE( STATUS "QML: " ${QML_FILES} )

find_package(Boost REQUIRED COMPONENTS system thread)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml   REQUIRED)
find_package(Qt5Quick REQUIRED)

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Qml_INCLUDE_DIRS}
    ${Qt5Quick_INCLUDE_DIRS})
link_directories(
    ${Boost_LIBRARY_DIRS}
    ${Qt5Core_LIBRARY_DIRS}
    ${Qt5Widgets_LIBRARY_DIRS}
    ${Qt5Qml_LIBRARY_DIRS}
    ${Qt5Quick_LIBRARY_DIRS})
add_executable(${PROJECT_NAME} ${sources} ${headers} ${QRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "game")
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${Qt5Core_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Qml_LIBRARIES}
    ${Qt5Quick_LIBRARIES})


