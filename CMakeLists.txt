cmake_minimum_required(VERSION 3.14)
project(Tik_Tak_Toe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE src/Source.cpp)

# g++ -I src

add_executable(main ${SOURCE_EXE})
target_link_libraries(main)
