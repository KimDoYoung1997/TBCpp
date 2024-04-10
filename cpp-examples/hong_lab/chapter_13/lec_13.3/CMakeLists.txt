cmake_minimum_required(VERSION 3.13)
project(lec_13.3)

add_executable(main main.cpp)
add_library(MyArray MyArray.cpp)
target_link_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/build)
target_link_libraries(main MyArray)


