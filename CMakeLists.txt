cmake_minimum_required(VERSION 3.15)
project(TodoManager)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library
add_library(tasklib
    src/Task.cpp
    src/TaskManager.cpp
)

# Library include directories
target_include_directories(tasklib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Enable testing
enable_testing()

# find Google test
find_package(GTest REQUIRED)

# Add tests
add_executable(task_tests
    tests/TaskManagerTest.cpp
)

target_link_libraries(task_)