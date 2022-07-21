
add_executable(triangle src/main.cpp)

target_include_directories(triangle PUBLIC include)

target_link_libraries(triangle PRIVATE
gl_lib
glfw
external
Eigen3::Eigen
)

