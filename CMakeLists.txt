cmake_minimum_required(VERSION 3.16)
# glue: minimum cmake version is 3.16: https://github.com/nigels-com/glew/blob/master/README.md

project(DasVerdeSpiel C CXX)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions

# Set the C standard to C17
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF) # Disable compiler-specific extensions

# official GLFW tutorial https://www.glfw.org/docs/latest/build_guide.html

set(GLFW_DIR "${PROJECT_SOURCE_DIR}/glfw-3.4")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# by GLFW tutorial
add_subdirectory(${GLFW_DIR})

add_executable(DFS ${SRC_DIR}/main.cpp)

target_link_libraries(DFS glfw)

# by GLFW tutorial
# without this i gor error "undefined reference to `glClear'"
# follow offial GLFW tutorial to avoid find_package failure here
# it requires U to install some modules
# the tutorial: https://www.glfw.org/docs/latest/compile.html
find_package(OpenGL REQUIRED)
target_link_libraries(DFS OpenGL::GL)

# abanded
# # GLEW
# # if find_package fails, and U dont want to install GLEW system-wide,
# # download GLEW and compole the lib via makefile it provides,
# # then use set(GLEW_ROOT "/path/to/glew/build/") before find_package
# # GLEW tutorial: https://glew.sourceforge.net/build.html
# find_package(GLEW REQUIRED)
# target_include_directories(DFS PRIVATE ${GLEW_INCLUDE_DIRS})
# target_link_libraries(DFS GLEW::GLEW)

# Stricter warning settings
if(MSVC)  # For Microsoft Visual Studio
    target_compile_options(DFS PRIVATE /W3 /WX)  # Warning level 3, treat warnings as errors
else()  # For other compilers like GCC or Clang
    target_compile_options(DFS PRIVATE -Wall -Werror)  # Treat all warnings as errors
endif()
