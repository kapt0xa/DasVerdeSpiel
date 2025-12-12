cmake_minimum_required(VERSION 3.1)

project(DasVerdeSpiel C CXX)

# official GLFW tutorial https://www.glfw.org/docs/latest/build_guide.html

set(GLFW_DIR "${PROJECT_SOURCE_DIR}/glfw-3.4")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# by GLFW tutorial
add_subdirectory(${GLFW_DIR})

add_executable(DFS ${SRC_DIR}/main.cpp)

target_link_libraries(DFS glfw)

# by GLFW tutorial
# without this i gor error "undefined reference to `glClear'"
find_package(OpenGL REQUIRED)
target_link_libraries(DFS OpenGL::GL)