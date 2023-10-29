cmake_minimum_required(VERSION 3.14)
project(Tik_Tak_Toe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE src/Source.cpp)
set(LIB src/utils.cpp)

# g++ -I src

include_directories(src)

add_executable(main ${SOURCE_EXE})
target_link_libraries(main)
target_include_directories(main PUBLIC ${LIB})

# end of file
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

add_executable(
    test_source
    src/test.cpp
)
target_link_libraries(
    test_source
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_source)
