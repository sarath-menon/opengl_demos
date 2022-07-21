
add_executable(texture src/main.cpp)

target_include_directories(texture PUBLIC include)

target_link_libraries(texture PRIVATE
gl_lib
glfw
external
)

