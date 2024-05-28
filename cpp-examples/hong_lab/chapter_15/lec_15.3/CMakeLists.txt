cmake_minimum_required(VERSION 3.13)
project(lec_15.3)

# 경로를 출력합니다.
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# 실행 파일과 라이브러리 타겟을 추가합니다.
add_executable(main main.cpp)
add_executable(main2 main2.cpp)
add_library(Resource Resource.cpp)

# include 디렉토리 경로 설정
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
message(STATUS "INCLUDE_DIR: ${INCLUDE_DIR}")

# 타겟 리스트를 만듭니다.
set(TARGETS main main2)

# 타겟 리스트를 순회하며 include 디렉토리를 추가하고 라이브러리를 링크합니다.
foreach(TARGET ${TARGETS})
    message(STATUS "TARGET file : ${TARGET}")
    target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIR})
    target_link_libraries(${TARGET} Resource)
endforeach()
