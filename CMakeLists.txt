cmake_minimum_required(VERSION 3.1)

project(DasVerdeSpiel C CXX)


set(GLFW_DIR "${CMAKE_SOURCE_DIR}/glfw-3.4")

# by tutorial https://www.glfw.org/docs/latest/build_guide.html
add_subdirectory(${GLFW_DIR})

add_executable(DFS main.cpp)

target_link_libraries(DFS glfw)