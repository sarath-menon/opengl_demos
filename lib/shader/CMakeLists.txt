
add_library(shader STATIC
src/shader.cpp
)

target_include_directories(shader PUBLIC include)

target_link_libraries(shader PRIVATE
glfw
external
Eigen3::Eigen
)

