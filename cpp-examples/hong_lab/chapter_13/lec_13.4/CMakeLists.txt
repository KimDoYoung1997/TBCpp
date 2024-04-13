cmake_minimum_required(VERSION 3.13)
project(lec_13.4)

add_executable(main main.cpp)
add_executable(main2 main2.cpp)
add_executable(main3 main2.cpp)

add_library(Storage Storage.cpp)

target_link_directories(main3 PRIVATE ${CMAKE_SOURCE_DIR}/build)
target_link_libraries(main3 Storage)


