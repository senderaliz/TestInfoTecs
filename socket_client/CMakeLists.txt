add_executable(socket_writer Writer.cpp)
target_link_libraries(socket_writer PRIVATE log)

add_executable(socket_reader Reader.cpp)
target_link_libraries(socket_reader PRIVATE log)