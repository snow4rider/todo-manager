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
 
# Find Google Test
find_package(GTest REQUIRED)
 
# Add tests
add_executable(task_tests
    tests/TaskManagerTest.cpp
)
 
target_link_libraries(task_tests
    tasklib
    GTest::gtest_main
)
 
# Register tests
add_test(NAME TaskTests COMMAND task_tests)
 
# Optional: Add CLI executable (Phase 2)
# add_executable(todo-cli src/main.cpp)
# target_link_libraries(todo-cli tasklib)
