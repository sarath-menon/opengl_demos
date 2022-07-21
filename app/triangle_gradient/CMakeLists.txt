
add_executable(triangle_grad_demo src/main.cpp)

target_include_directories(triangle_grad_demo PUBLIC include)

target_link_libraries(triangle_grad_demo PRIVATE
gl_lib
glfw
external
)

