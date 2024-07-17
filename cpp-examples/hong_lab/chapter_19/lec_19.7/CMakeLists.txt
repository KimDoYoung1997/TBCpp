cmake_minimum_required(VERSION 3.13)
project(lec_19.7)
# # C++17 표준 사용 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 경로를 출력합니다.
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# include 디렉토리 경로 설정
# set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
# message(STATUS "INCLUDE_DIR: ${INCLUDE_DIR}")

# 라이브러리 타겟을 추가합니다.
# add_library(Resource STATIC Resource.cpp)
# add_library(MySwap STATIC MySwap.cpp)

# add_library(Resource2 STATIC Resource2.cpp)

# 실행 파일과 라이브러리를 추가합니다.
add_executable(main main.cpp)
add_executable(main2 main2.cpp)
add_executable(main3 main3.cpp)
add_executable(main4 main4.cpp)
add_executable(main5 main5.cpp)
add_executable(main6 main6.cpp)

# add_executable(main2 main2.cpp)
# add_executable(main3 main3.cpp)
# add_executable(main7 main7.cpp)


# # # 타겟 리스트를 만듭니다.
# set(TARGETS1 main main_x)
set(TARGETS1 main main2 main3 main4 main5 main6)
# # set(TARGETS2 main2)

# 타겟 리스트를 순회하며 include 디렉토리를 추가하고 라이브러리를 링크합니다.
foreach(TARGET ${TARGETS1})
    message(STATUS "TARGET1 file : ${TARGET}")
    # target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIR})
    # target_link_libraries(${TARGET} PRIVATE Resource)
endforeach()
# # target_link_libraries(main2 PRIVATE MySwap)
# # foreach(TARGET ${TARGETS2})
# #     message(STATUS "TARGET2 file : ${TARGET}")
# #     # target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIR})
# #     target_link_libraries(${TARGET} PRIVATE Resource2)
# # endforeach()
