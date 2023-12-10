cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -O3 -flto -fconstexpr-ops-limit=1000000000")

project(Kuzhyechik)


find_package(GTest CONFIG REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main main.cpp coder.cpp)

target_include_directories(main
 PUBLIC
  /usr/include/c++/11/bits/)

enable_testing()

add_executable(
    tests
    test.cpp
    coder.cpp
)
target_link_libraries(
    tests
    GTest::gtest_main
    GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(tests)