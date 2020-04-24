cmake_minimum_required(VERSION 2.8)

project(img2video)

set(CMAKE_CXX_FLAGS  "-std=c++11")

find_package( OpenCV 3 REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(img2video src/img2video.cpp)

target_link_libraries(img2video ${OpenCV_LIBS})