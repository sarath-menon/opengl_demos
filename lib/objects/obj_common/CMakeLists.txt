set(MODULE_NAME obj_common)

# list of c++ source files
set(CPP_FILES
src/simple_model.cpp
src/texture.cpp
src/mesh.cpp
src/rotation.cpp
src/EBO.cpp
src/VBO.cpp
src/VAO.cpp
)

# list of library dependendcies
set(LIB_DEP
common
shader
Eigen3::Eigen
assimp::assimp
external
)

####### Do not modify !

add_library(${MODULE_NAME} STATIC ${CPP_FILES})

target_include_directories(${MODULE_NAME} PUBLIC include)

target_link_libraries(${MODULE_NAME} PRIVATE ${LIB_DEP})

