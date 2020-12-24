#include <iostream>
#include "gtest/gtest.h"
#include "../../src/VCARDGenerator/VCARDGenerator.h"

using namespace std;
TEST(VCARDGenerator, testOfTheTest) {
    VCARDGenerator g;
    EXPECT_EQ(g.sayHello(), "Hello");
}
