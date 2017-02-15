cmake_minimum_required(VERSION 3.0)
project(MissionImpossible)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE headers src/*.h)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -fPIC")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Boost REQUIRED)
find_package(Qt5Core REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS} ${Qt5Core_LIBRARY_DIRS})
add_executable(${PROJECT_NAME} ${sources} ${headers})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "game")
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${Qt5Core_LIBRARIES})
