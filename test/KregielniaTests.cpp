#include <gtest/gtest.h>
#include "Kregielnia.hpp"
#include "StringToVectorConverter.hpp"
#include <string>

struct KregielniaTests : public ::testing::Test
{
};

int sumVector(std::vector<int> vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

TEST_F(KregielniaTests, assertThatTravisCiBuildStatusIsPass)
{
    ASSERT_TRUE(true);
}

TEST_F(KregielniaTests, assertSingleNumberConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("0")), 0);
    EXPECT_EQ(sumVector(ConvertStringToVector("2")), 2);
    EXPECT_EQ(sumVector(ConvertStringToVector("3")), 3);
    EXPECT_EQ(sumVector(ConvertStringToVector("8")), 8);
}

TEST_F(KregielniaTests, assertSingleMarkConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("X")), 10);
    EXPECT_EQ(sumVector(ConvertStringToVector("-")), 0);
}

TEST_F(KregielniaTests, assertSpareConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("3/")), 10);
}

TEST_F(KregielniaTests, assertExampleConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("3-|X|4/|5")), 28);
    EXPECT_EQ(sumVector(ConvertStringToVector("X|4-|3")), 17);
    EXPECT_EQ(sumVector(ConvertStringToVector("34|X|0-")), 17);
}
