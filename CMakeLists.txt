cmake_minimum_required(VERSION 3.3)

project (cpp_memory_master)

add_compile_options(-std=c++17)

find_package(Threads)


set(OpenCV_DIR [OpenCV.cmake PATH])
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})

add_subdirectory(owner_pointer)
add_subdirectory(shared_pointer)
add_subdirectory(unique_pointer)
