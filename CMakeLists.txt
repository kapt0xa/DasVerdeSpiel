cmake_minimum_required(VERSION 3.1)

project(DasVerdeSpiel C CXX)

# official GLFW tutorial https://www.glfw.org/docs/latest/build_guide.html

set(GLFW_DIR "${PROJECT_SOURCE_DIR}/glfw-3.4")
set(GLEW_DIR "${PROJECT_SOURCE_DIR}/glew-2.1.0")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# i tortured googleAI to setup glew. suffix _ROOT helps cmake not to fk up with find_package
set(GLEW_ROOT ${GLEW_DIR})
find_package(GLEW REQUIRED)

add_library(GLEW_LOCAL STATIC IMPORTED)

# by GLFW tutorial
add_subdirectory(${GLFW_DIR})

add_executable(DFS ${SRC_DIR}/main.cpp)

target_link_libraries(DFS glfw)

# 2. Analog for "Additional Include Directories"
# Adds the 'include' folder so you can write #include "header.h"
target_include_directories(DFS PRIVATE ${GLEW_DIR}/include)

# 3. Analog for "Additional Library Directories"
# Tells the linker where to look for .lib files
target_link_directories(DFS PRIVATE ${GLEW_DIR}/lib)

# 4. Analog for "Additional Dependencies"
# Links the actual library file (e.g., SomeLibrary.lib)
target_link_libraries(DFS PRIVATE SomeLibrary)

# by GLFW tutorial
# without this i gor error "undefined reference to `glClear'"
find_package(OpenGL REQUIRED)
target_link_libraries(DFS OpenGL::GL)

# by toturing googleAI about glew
target_link_libraries(DFS PRIVATE GLEW::GLEW)