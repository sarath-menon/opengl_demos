set(MODULE_NAME vertex_objects)

# list of c++ source files
set(CPP_FILES
src/VAO.cpp
src/VBO.cpp
)

# list of library dependendcies
set(LIB_DEP
common
glfw
external
Eigen3::Eigen
)

####### Do not modify !

add_library(${MODULE_NAME} STATIC ${CPP_FILES})

target_include_directories(${MODULE_NAME} PUBLIC include)

target_link_libraries(${MODULE_NAME} PRIVATE ${LIB_DEP})
