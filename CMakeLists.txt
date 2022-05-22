cmake_minimum_required (VERSION 3.0 FATAL_ERROR)
project (Demo)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ${TORCH_CXX_FLAGS}")
#list(APPEND CMAKE_PREFIX_PATH "/home/hungan/libtorch")

#find_package(Torch REQUIRED)
#find_package( OpenCV REQUIRED )
#aux_source_directory(. DIR_SRCS)
# 指定生成目标 
add_executable(Demo main.cpp)

#include_directories( ${OpenCV_INCLUDE_DIRS} )
#target_link_libraries( Demo ${OpenCV_LIBS} stdc++fs)
#target_link_libraries( Demo "${TORCH_LIBRARIES}")

#set_property(TARGET example-app PROPERTY CXX_STANDARD 14
###
###
mainmain123