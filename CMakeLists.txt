cmake_minimum_required(VERSION 3.0.0)
project(opengl_demo VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL 4.1 REQUIRED)

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(external)
