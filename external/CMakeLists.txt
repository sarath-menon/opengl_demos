
add_library(external INTERFACE)

target_link_libraries(external INTERFACE 
glad
stb_image
)

add_subdirectory(glad)
add_subdirectory(stb_image)