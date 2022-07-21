
add_library(gl_lib INTERFACE
)

target_link_libraries(gl_lib INTERFACE 
objects
shader
vertex_objects
viewer
)

add_subdirectory(objects)
add_subdirectory(shader)
add_subdirectory(vertex_objects)
add_subdirectory(viewer)

