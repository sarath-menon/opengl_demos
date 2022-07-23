#template for executables
set(EXEC_NAME cube_demo)

# list of c++ source files
set(CPP_FILES
src/main.cpp
)

# list of library dependendcies
set(LIB_DEP
glfw
external
Eigen3::Eigen
gl_lib
)

####### Do not modify !

add_library(${EXEC_NAME} STATIC ${CPP_FILES})

target_include_directories(${EXEC_NAME} PUBLIC include)

target_link_libraries(${EXEC_NAME} PRIVATE ${LIB_DEP})

