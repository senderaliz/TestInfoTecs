add_library(log SHARED src/LibFile.cpp src/LibSocket.cpp include/Lib.h)

target_include_directories(log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(logStatic STATIC src/LibFile.cpp src/LibSocket.cpp include/Lib.h)

target_include_directories(logStatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)