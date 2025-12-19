add_executable(UnitTests
    tests.cpp
    ../src/npc.cpp
    ../src/world.cpp
    ../src/factory.cpp
    ../src/visitor.cpp
    ../src/observer.cpp
    ../src/elf.cpp
    ../src/bear.cpp
    ../src/rogue.cpp
)

target_include_directories(UnitTests PRIVATE ../include)

target_link_libraries(UnitTests
    gtest
    gtest_main
)

add_test(NAME UnitTests COMMAND UnitTests)
