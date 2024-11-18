# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(ReaderWriter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add threading support
find_package(Threads REQUIRED)

# Add the executable
add_executable(reader_writer main.cpp)

# Link against threading library
target_link_libraries(reader_writer PRIVATE Threads::Threads)