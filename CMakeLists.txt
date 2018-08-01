cmake_minimum_required(VERSION 3.1)

project(memshare)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("src/mem/include" "src/utility/include")
file(GLOB SOURCES "src/mem/src/*.cpp" "src/utility/src/*.cpp")

add_library(memshare STATIC ${SOURCES})

add_executable(test_main ${PROJECT_SOURCE_DIR}/src/tests/test_main.cpp)
target_link_libraries(test_main memshare)
