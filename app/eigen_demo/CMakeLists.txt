
add_executable(eigen_demo src/main.cpp)

target_include_directories(eigen_demo PUBLIC include)

target_link_libraries(eigen_demo PRIVATE
gl_lib
glfw
external
Eigen3::Eigen
)

