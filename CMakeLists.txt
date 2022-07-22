cmake_minimum_required(VERSION 3.15.0)
set(CMAKE_CXX_STANDARD 17)

project(cube VERSION 0.1.0)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL 4.1 REQUIRED)
find_package(Eigen3 3.3 REQUIRED)


add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(external)

function(print var)
    message("${var} = ${${var}}")
endfunction(print var)

print(PROJECT_NAME)