set(MODULE_NAME shader)

# list of c++ source files
set(CPP_FILES
src/${MODULE_NAME}.cpp
src/utils.cpp
)

# list of library dependendcies
set(LIB_DEP
glfw
GLEW::GLEW
external
Eigen3::Eigen
)

####### Do not modify !

add_library(${MODULE_NAME} STATIC ${CPP_FILES})

target_include_directories(${MODULE_NAME} PUBLIC include)

target_link_libraries(${MODULE_NAME} PUBLIC ${LIB_DEP})