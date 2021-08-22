cmake_minimum_required (VERSION 2.6)
project (Demo)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package( OpenCV REQUIRED )
#aux_source_directory(. DIR_SRCS)
# 指定生成目标 
add_executable(Demo main.cpp LogUtils.cpp LogUtils.h)

include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( Demo ${OpenCV_LIBS} stdc++fs)