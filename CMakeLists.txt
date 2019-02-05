CMAKE_MINIMUM_REQUIRED(VERSION 3.4)


SET(CMAKE_CXX_STANDARD 17)

FILE(GLOB_RECURSE all_cpp "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

INCLUDE_DIRECTORIES("include/" "include/share" "include/engine" "include/core")

ADD_EXECUTABLE(ZimaDB ${all_cpp})
