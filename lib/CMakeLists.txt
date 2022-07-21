
add_library(gl_lib STATIC
src/glfw_helper.cpp
src/shader.cpp
src/triangle.cpp
src/square.cpp
src/VAO.cpp
src/VBO.cpp
src/EBO.cpp
)

target_include_directories(gl_lib PUBLIC include)

target_link_libraries(gl_lib PRIVATE
glfw
external
Eigen3::Eigen
)

