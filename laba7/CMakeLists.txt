cmake_minimum_required(VERSION 3.16)
project(laba7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# ===== Основное приложение =====
add_executable(laba7
    main.cpp
    src/npc.cpp
    src/world.cpp
    src/factory.cpp
    src/visitor.cpp
    src/observer.cpp
    src/elf.cpp
    src/bear.cpp
    src/rogue.cpp
)

# ===== GoogleTest =====
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)
