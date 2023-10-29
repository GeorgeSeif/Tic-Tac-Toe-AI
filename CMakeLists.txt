cmake_minimum_required(VERSION 3.14)
project(Tik_Tak_Toe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE src/Source.cpp)

add_executable(main ${SOURCE_EXE})
target_link_libraries(main)

# end of file
# enable_testing()

# add_executable(
#     test_Source
#     test_Source.cpp
# )
# target_link_libraries(
#     test_Source
#     GTest::gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(test_Source)

