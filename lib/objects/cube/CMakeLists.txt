
set(MODULE_NAME "cube")

add_library(${MODULE_NAME} STATIC
src/${MODULE_NAME}.cpp
)

target_include_directories(${MODULE_NAME} PUBLIC include)

target_link_libraries(${MODULE_NAME} PRIVATE
common
glfw
external
Eigen3::Eigen
)

