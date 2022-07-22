
set(EXEC_NAME "triangle_demo")

add_executable(${EXEC_NAME} src/main.cpp)

target_include_directories(${EXEC_NAME} PUBLIC include)

target_link_libraries(${EXEC_NAME} PRIVATE
glfw
external
Eigen3::Eigen
gl_lib
)

