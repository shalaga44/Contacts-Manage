//
// Created by shalaga44 on 12/24/20.
//
#include "gtest/gtest.h"
#include "../../src/VCARDReader/VCARDReader.h"
#include "../../src/VCARDContact/VCARDContact.h"

using namespace std;
TEST(VCARDGenerator, readVcard) {
    VCARDReader generator = VCARDReader();
    const vector<VCARDContact> contacts = generator.readVCARDFrom("../../../vCards-Samples/0- name_phone.vcf");
    EXPECT_EQ("Mohamed Moawia El-Bashir", contacts[0].username);
}

