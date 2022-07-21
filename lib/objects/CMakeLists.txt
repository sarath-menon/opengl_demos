
add_library(objects STATIC
src/triangle.cpp
)

target_include_directories(objects PUBLIC include)

target_link_libraries(objects PRIVATE
glfw
external
Eigen3::Eigen
)

