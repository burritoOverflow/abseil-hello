cmake_minimum_required(VERSION 3.20)

project(my_project)

set(CMAKE_CXX_STANDARD 14)

find_package(absl REQUIRED)

add_executable(hello_world src/main.cc)

target_link_libraries(hello_world absl::strings)