cmake_minimum_required(VERSION 3.5)

project(opencv_example)

set(OpenCV_DIR [OpenCV.cmake PATH])

find_package(OpenCV REQUIRED)

add_compile_options(-std=c++17)

include_directories(${OpenCV_INCLUDE_DIR})

add_executable(opencv_example main)
target_link_libraries(opencv_example ${OpenCV_LIBRARIES})
