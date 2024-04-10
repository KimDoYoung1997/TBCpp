cmake_minimum_required(VERSION 3.13)

project(lec_13.1)

add_executable(main2 main2.cpp)

# libCents.a 정적라이브러리 파일 생성 (/home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.1/build)
add_library(Cents Cents.cpp)

# 일단 main3.cpp 로부터 main3이라는 실행파일을 생성한다
add_executable(main3 main3.cpp)

# main3 실행파일에 링킹할 정적 라이브러리의 위치 (/home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.1/) 를 target해준다.
target_link_directories(main3 PRIVATE ${CMAKE_SOURCE_DIR})

# 이후 정적라이브러리인 Cents와 실행파일 main3을 target_link 해준다.
target_link_libraries(main3 Cents)

# TARGETS 옆에는 executable파일이 와도 되고, library가 와도 된다. 여기서는 executable파일이 왔다.
# 위 install(TARGET <Target_목록> DESTINATION <설치 경로>)
# 즉 KIM 실행파일을 /usr/local/bin 경로에 install하겠다는 뜻.
# 이 경우 build 폴더에서 sudo make install 추가로 해줘야 /usr/local/bin 경로에 KIM 실행파일이 생김
install(TARGETS main3 DESTINATION bin)
