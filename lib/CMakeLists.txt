add_library(log SHARED src/Lib.cpp include/Lib.h)

target_include_directories(log 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)