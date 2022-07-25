# Template for pure interface library

set(LIB_NAME external)

# list of libs to combine as one interface lib
set(SUB_LIBS 
glad
stb
)

####### Do not modify !

add_library(${LIB_NAME} INTERFACE)

target_link_libraries(${LIB_NAME} INTERFACE ${SUB_LIBS})

foreach(LIB ${SUB_LIBS})
    add_subdirectory(${LIB})
endforeach()
