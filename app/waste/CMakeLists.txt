
add_executable(waste src/main.cpp)

target_include_directories(waste PUBLIC include)

target_link_libraries(waste PRIVATE
glfw
external
Eigen3::Eigen
gl_lib
)

