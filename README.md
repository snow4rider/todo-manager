# Todo Manager \- Learning C++, CMake, and Google Test

A simple task management library and CLI tool to learn modern C++ development practices.

## Project Structure

todo-manager/

├── CMakeLists.txt           \# Root build configuration

├── src/

│   ├── Task.h              \# Task data class

│   ├── Task.cpp

│   ├── TaskManager.h       \# Task manager (library interface)

│   ├── TaskManager.cpp

│   └── main.cpp            \# (Phase 2\) CLI application

└── tests/

    └── TaskManagerTest.cpp \# Google Test tests

## Building the Project

### Prerequisites

Install CMake and Google Test:

\# macOS

brew install cmake googletest

\# Ubuntu/Debian

sudo apt-get install cmake libgtest-dev

\# Or build from source (see Phase 1 notes)

### Build & Run Tests

\# Create build directory

mkdir build && cd build

\# Configure with CMake

cmake ..

\# Build

cmake \--build .

\# Run tests

ctest \--output-on-failure

\# Or directly:

./task\_tests

## Phase 1: Foundation (You are here)

**Goal:** Get the core library working with basic tests

**Current implementation:**

- ✅ `Task` class: title, description, status, ID  
- ✅ `TaskManager`: add/remove/mark done/done count  
- ✅ Save to JSON (basic)  
- ✅ Unit tests with Google Test (11 tests)  
- ✅ CMake configuration

**What you should do:**

1. Build and run the tests (follow "Build & Run Tests" above)  
2. Read through `Task.h` and `TaskManager.h` to understand the API  
3. Study `TaskManagerTest.cpp` to see how Google Test fixtures work  
4. Try modifying a test or adding a new feature (e.g., `setTitle()` method)  
5. Run tests again to verify your changes

**Key C++ concepts to notice:**

- `std::shared_ptr` and `std::make_shared` (smart pointers)  
- `std::vector` and standard algorithms (`std::find_if`, `std::count_if`)  
- Lambda functions used with algorithms  
- const-correctness in method signatures

## Phase 2: CLI & File I/O (Next)

**Goal:** Build a command-line interface and proper JSON loading

**Planned work:**

- Create `src/main.cpp` with argument parsing  
- Implement JSON parsing for `loadFromFile()`  
- Consider integrating a JSON library (nlohmann/json)  
- Add more test scenarios

## Phase 3: Polish & Features (After Phase 2\)

**Possible extensions:**

- Filtering and searching tasks  
- Due dates and priorities  
- Color-coded output  
- Configuration file support  
- More advanced testing (mocking file I/O)

## Common CMake Concepts Used

- `cmake_minimum_required()` \- Specify minimum CMake version  
- `project()` \- Define project name  
- `add_library()` \- Create a library target  
- `add_executable()` \- Create an executable target  
- `target_include_directories()` \- Specify include paths  
- `target_link_libraries()` \- Link libraries to targets  
- `find_package()` \- Find installed packages (like Google Test)  
- `enable_testing()` & `add_test()` \- Register tests

## Useful Links

- [Google Test Documentation](https://google.github.io/googletest/)  
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)  
- [Modern C++ (cppreference.com)](https://en.cppreference.com/)

## Next Steps

1. ✅ Review the code structure  
2. ✅ Build and run tests  
3. → Explore what happens when you modify a test  
4. → Add a new method to `Task` or `TaskManager` and write a test for it  
5. → (Phase 2\) Implement JSON loading with proper error handling

