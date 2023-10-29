cmake_minimum_required(VERSION 3.14)
project(Tik_Tak_Toe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_EXE src/Source.cpp)
set(LIB src/utils.cpp)
set(TEST_FILES src/test.cpp)

# g++ -I src
# Add the Google Test source code files and include directories
# add_subdirectory(googletest)
# add_library(gtest STATIC ${TEST})
# target_include_directories(gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_compile_options(gtest PRIVATE -Wall -Wextra -pedantic)
# target_link_libraries(gtest PUBLIC pthread)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(src)

add_executable(main ${SOURCE_EXE})
target_link_libraries(main)
target_include_directories(main PUBLIC ${LIB})

# end of file
enable_testing()

# Find and include Google Test
# set(gtest_DIR googletest/build)

# Create a test executable
add_executable(test_Source ${TEST_FILES})
# Link Google Test to the test executable
target_link_libraries(test_Source ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
add_test(NAME CoreTest COMMAND test_Source)


# add_executable(test_source src/test.cpp)
# target_link_libraries(test_source PUBLIC gtest)
# target_link_libraries(test_source gtest)

# include(GoogleTest)
# gtest_discover_tests(test_source)
