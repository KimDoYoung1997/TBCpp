cmake_minimum_required(VERSION 3.13)

project(book_13.2)

add_executable(PointClassTemplate PointClassTemplate.cpp)

add_executable(PointClassTemplateFuncDef PointClassTemplateFuncDef.cpp)

add_executable(PointMain PointMain.cpp)             # PointMain.cpp 를 실행 파일로 변환
add_library(PointTemplate PointTemplate.cpp)        # PointTemplate.cpp 파일을 정적 라이브러리로 변환

target_link_directories(PointMain PRIVATE ${CMAKE_SOURCE_DIR}/build) # targetget할 정적 라이브러리의 위치를 선언
target_link_libraries(PointMain PointTemplate)      # 해당 경로에 위치한 정적 라이브러리와 실행 파일간 link