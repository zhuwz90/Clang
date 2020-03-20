cmake_minimum_required(VERSION 3.15)
project(getopt C)

SET(CMAKE_C_STANDARD 11)

include_directories(.)

aux_source_directory(. SRC_LIST)

MESSAGE(${SRC_LIST})

add_executable(getopt_demo ${SRC_LIST})
