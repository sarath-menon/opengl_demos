set(MODULE_NAME obj_common)

# list of c++ source files
set(CPP_FILES
src/rigid3d.cpp
)

# list of library dependendcies
set(LIB_DEP
common
Eigen3::Eigen
)

####### Do not modify !

add_library(${MODULE_NAME} STATIC ${CPP_FILES})

target_include_directories(${MODULE_NAME} PUBLIC include)

target_link_libraries(${MODULE_NAME} PRIVATE ${LIB_DEP})

