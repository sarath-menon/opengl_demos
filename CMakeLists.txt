cmake_minimum_required(VERSION 3.0.0)
project(opengl_demo VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL 3.3 REQUIRED)


include_directories(external)

add_executable(opengl_demo 
src/main.cpp
src/glad.c
)

target_include_directories(opengl_demo PUBLIC include)

target_link_libraries(opengl_demo PRIVATE
glfw
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

