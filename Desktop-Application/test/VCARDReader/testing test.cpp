#include "gtest/gtest.h"
#include "../../src/VCARDReader/VCARDReader.h"

using namespace std;
TEST(VCARDGenerator, testOfTheTest) {
    VCARDReader g;
    EXPECT_EQ(g.sayHello(), "Hello");
}
