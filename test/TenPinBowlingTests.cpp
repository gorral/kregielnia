#include <gtest/gtest.h>
#include "InputFile.hpp"
#include "TenPinBowling.hpp"
#include "StringToVectorConverter.hpp"
#include <string>
#include <numeric>

struct TenPinBowlingTests : public ::testing::Test
{
};

int sumVector(std::vector<int> vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

TEST_F(TenPinBowlingTests, assertThatTravisCiBuildStatusIsPass)
{
    ASSERT_TRUE(true);
}

TEST_F(TenPinBowlingTests, assertThatLoadInputFileFunctionReadAllFiles)
{
    const std::string inputDirectoryPath = "test_files";
    const fs::path outputFilePath = "result.txt";
    int inFileCntr = 0;

    TenPinBowling testgame{"My Bowling Game!", {}, inputDirectoryPath, outputFilePath};
    // GIVEN
    InputFile::Remove(inputDirectoryPath);
    ASSERT_FALSE(fs::is_directory(inputDirectoryPath));
    ASSERT_TRUE(InputFile::Create(inputDirectoryPath));
    ASSERT_TRUE(fs::is_directory(inputDirectoryPath));
    ASSERT_FALSE(fs::is_empty(inputDirectoryPath));

    for(auto&p: fs::directory_iterator(inputDirectoryPath)) {
        inFileCntr++;
    }
    // WHEN
    ASSERT_TRUE(testgame.loadInputFiles());
    // THEN
    ASSERT_TRUE(inFileCntr == testgame.gamesCntr());
}

TEST_F(TenPinBowlingTests, assertSingleNumberConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("0")), 0);
    EXPECT_EQ(sumVector(ConvertStringToVector("2")), 2);
    EXPECT_EQ(sumVector(ConvertStringToVector("3")), 3);
    EXPECT_EQ(sumVector(ConvertStringToVector("8")), 8);
}
TEST_F(TenPinBowlingTests, assertSingleMarkConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("X")), 10);
    EXPECT_EQ(sumVector(ConvertStringToVector("-")), 0);
}
TEST_F(TenPinBowlingTests, assertSpareConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("3/")), 10);
}
TEST_F(TenPinBowlingTests, assertExampleConversion)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("3-|X|4/|5")), 28);
    EXPECT_EQ(sumVector(ConvertStringToVector("X|4-|3")), 17);
    EXPECT_EQ(sumVector(ConvertStringToVector("34|X|0-")), 17);
}
