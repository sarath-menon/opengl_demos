
add_library(vertex_objects STATIC
src/VAO.cpp
src/VBO.cpp
src/EBO.cpp
)

target_include_directories(vertex_objects PUBLIC include)

target_link_libraries(vertex_objects PRIVATE
glfw
external
Eigen3::Eigen
)

