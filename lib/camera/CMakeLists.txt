set(MODULE_NAME camera)

# list of c++ source files
set(CPP_FILES
src/${MODULE_NAME}.cpp
)

# list of library dependendcies
set(LIB_DEP
common
glfw
external
shader
)

####### Do not modify !

add_library(${MODULE_NAME} STATIC ${CPP_FILES})

target_include_directories(${MODULE_NAME} PUBLIC include)

target_link_libraries(${MODULE_NAME} PRIVATE ${LIB_DEP})


