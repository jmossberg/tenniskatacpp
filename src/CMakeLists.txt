add_library(src Tennis.cpp)
target_compile_options(src PRIVATE -Werror -Wall -std=c++14 -pthread -g -O0)
target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})