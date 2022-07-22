
set(LIB_NAME "objects")

add_library(${LIB_NAME} INTERFACE)

target_link_libraries(${LIB_NAME} INTERFACE 
triangle
cube
)

add_subdirectory(triangle)
add_subdirectory(cube)

