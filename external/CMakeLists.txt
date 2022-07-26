# Template for pure interface library
include(ExternalProject)
include(FetchContent)

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

################# Download 

# tinyobjloader
FetchContent_Declare(
    tinyobjloader #
    URL https://github.com/tinyobjloader/tinyobjloader/archive/v2.0-rc1.zip #
    URL_HASH MD5=f660a9f91fc2ea5c4f33d7530f6a69bc #
)
FetchContent_GetProperties(tinyobjloader)
if(NOT tinyobjloader_POPULATED)
    FetchContent_Populate(tinyobjloader)
endif()
add_subdirectory(${tinyobjloader_SOURCE_DIR} tinyobjloader)
