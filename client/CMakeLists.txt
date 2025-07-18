add_executable(client Main.cpp)

# target_link_libraries(myapp PRIVATE mylib)

# target_include_directories(myapp PRIVATE 
#     ${CMAKE_SOURCE_DIR}/lib/include
# )

set_target_properties(client PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)