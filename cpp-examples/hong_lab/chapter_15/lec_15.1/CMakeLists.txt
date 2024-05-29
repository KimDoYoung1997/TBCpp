cmake_minimum_required(VERSION 3.13)
project(lec_15.1)

# 경로를 출력합니다.
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# include 디렉토리 경로 설정
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# 실행 파일과 라이브러리 타겟을 추가합니다.
add_executable(main main.cpp)
add_executable(main2 main2.cpp)

add_library(Resource Resource.cpp)
# include 디렉토리 경로 설정
message(STATUS "INCLUDE_DIR: ${INCLUDE_DIR}")

# # include 디렉토리를 main 타겟과 Resource 타겟에 추가합니다.
# target_include_directories(main PRIVATE ${INCLUDE_DIR})
# target_include_directories(main2 PRIVATE ${INCLUDE_DIR})

# target_include_directories(Resource PRIVATE ${INCLUDE_DIR})




# main 타겟에 Resource 라이브러리를 링크합니다.
target_link_libraries(main Resource)
target_link_libraries(main2 Resource)
