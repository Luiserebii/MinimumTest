cmake_minimum_required(VERSION 3.2.0)
project(structuring)

# Add root directory of library as subdirectory
add_subdirectory(../../../ ${CMAKE_CURRENT_BINARY_DIR}/mint EXCLUDE_FROM_ALL)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} mint)
