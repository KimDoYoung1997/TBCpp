cmake_minimum_required(VERSION 3.13)

project(lec_13.2)

# 일단 main2.cpp 로부터 main3이라는 실행파일을 생성한다
add_executable(main2 main2.cpp)

# libMyArray.a 정적라이브러리 파일 생성 
add_library(MyArray MyArray.cpp)


# main2 실행파일에 링킹할 정적 라이브러리의 위치를 target해준다.
target_link_directories(main2 PRIVATE ${CMAKE_SOURCE_DIR}/build)

# 이후 정적라이브러리인 Cents와 실행파일 main3을 target_link 해준다.
target_link_libraries(main2 MyArray)

