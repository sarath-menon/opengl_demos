
add_executable(cube_demo src/main.cpp)

target_include_directories(cube_demo PUBLIC include)

target_link_libraries(cube_demo PRIVATE
glfw
external
Eigen3::Eigen
gl_lib
)

