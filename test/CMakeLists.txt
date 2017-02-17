add_executable(tennistest main.cpp TennisTest.cpp)
target_compile_options(tennistest PRIVATE -Werror -Wall -std=c++14 -pthread -g -O0)
target_link_libraries(tennistest src gmock_main gtest_main)