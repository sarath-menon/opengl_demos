
add_library(viewer STATIC
src/glfw_helper.cpp
)

target_include_directories(viewer PUBLIC include)

target_link_libraries(viewer PRIVATE
shader
glfw
external
)

