#include <gtest/gtest.h>
#include "elf.h"
#include "bear.h"
#include "rogue.h"
#include "world.h"
#include <cmath>

TEST(NPCTest, CreationTest) {
    Elf elf(10, 20);
    Bear bear(5, 5);
    Rogue rogue(0, 0);

    EXPECT_EQ(elf.getType(), "Elf");
    EXPECT_EQ(bear.getType(), "Bear");
    EXPECT_EQ(rogue.getType(), "Rogue");
}

TEST(NPCTest, CoordinatesTest) {
    Elf elf(10, 10);
    elf.move(5, -3);

    EXPECT_EQ(elf.getX(), 15);
    EXPECT_EQ(elf.getY(), 7);
}

TEST(NPCTest, AliveTest) {
    Bear bear(0, 0);
    EXPECT_TRUE(bear.isAlive());

    bear.kill();
    EXPECT_FALSE(bear.isAlive());
}

TEST(WorldTest, WorldCreation) {
    World world;
    SUCCEED();
}
