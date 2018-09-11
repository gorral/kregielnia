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
    const std::string inputfiles_directory = "test_files";
    fs::path testfile_path = fs::current_path() /= inputfiles_directory;
    int inFileCntr = 0;

    TenPinBowling testgame{"My Bowling Game!", {}};
    // GIVEN
        InputFile::Remove(inputfiles_directory);
        ASSERT_FALSE(fs::is_directory(testfile_path));
        ASSERT_TRUE(InputFile::Create(inputfiles_directory));
        ASSERT_TRUE(fs::is_directory(testfile_path));
        ASSERT_FALSE(fs::is_empty(testfile_path));

        for(auto&p: fs::directory_iterator(inputfiles_directory))
            inFileCntr++;
    // WHEN
    ASSERT_TRUE(testgame.loadInputFiles(testfile_path));
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
