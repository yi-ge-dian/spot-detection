cmake_minimum_required(VERSION 3.21)
project(spot-detection)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp src/background_subtraction.h src/utils.h)
target_link_libraries(spot-detection ${OpenCV_LIBS})