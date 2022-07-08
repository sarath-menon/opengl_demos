
add_executable(opengl_demo 
src/main.cpp
src/glfw_helper.cpp
src/shader.cpp
src/triangle.cpp
src/square.cpp
src/VAO.cpp
src/VBO.cpp
src/EBO.cpp
)

target_include_directories(opengl_demo PUBLIC include)

target_link_libraries(opengl_demo PRIVATE
glfw
external
)

