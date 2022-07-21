
add_executable(triangle_demo src/main.cpp)

target_include_directories(triangle_demo PUBLIC include)

target_link_libraries(triangle_demo PRIVATE
glfw
external
Eigen3::Eigen
gl_lib
)

