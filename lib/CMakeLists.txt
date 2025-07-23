add_library(log SHARED src/Lib.cpp include/Lib.h)

target_include_directories(log 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(logStatic STATIC src/Lib.cpp include/Lib.h)

target_include_directories(logStatic 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)