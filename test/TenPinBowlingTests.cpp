#include <gtest/gtest.h>
#include "InputFile.hpp"
#include "TenPinBowling.hpp"
#include "StringToVectorConverter.hpp"
#include <string>
#include <numeric>

struct TenPinBowlingTests : public ::testing::Test
{
};

int sumVector(std::vector<int> const &vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

TEST_F(TenPinBowlingTests, assertThatTravisCiBuildStatusIsPass)
{
    ASSERT_TRUE(true);
}

//TEST_F(TenPinBowlingTests, assertThatLoadInputFileFunctionReadAllFiles)
//{
//    const std::string inputfiles_directory = "test_files";
//    fs::path testfile_path = fs::current_path() /= inputfiles_directory;
//    int inFileCntr = 0;

//    TenPinBowling testgame{"My Bowling Game!", {}};
//    // GIVEN
//        InputFile::Remove(inputfiles_directory);
//        ASSERT_FALSE(fs::is_directory(testfile_path));
//        ASSERT_TRUE(InputFile::Create(inputfiles_directory));
//        ASSERT_TRUE(fs::is_directory(testfile_path));
//        ASSERT_FALSE(fs::is_empty(testfile_path));

//        for(auto&p: fs::directory_iterator(inputfiles_directory))
//            inFileCntr++;
//    // WHEN
//    ASSERT_TRUE(testgame.loadInputFiles(testfile_path));
//    // THEN
//    ASSERT_TRUE(inFileCntr == testgame.gamesCntr());
//}

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
TEST_F(TenPinBowlingTests, assertCorrectNameExtraction)
{
    EXPECT_EQ(GetPlayerName("Name1:X|4-|3"), "Name1");
    EXPECT_EQ(GetPlayerName(":X|22|33"), "");
    EXPECT_EQ(GetPlayerName(":"), "");
    EXPECT_EQ(GetPlayerName(""), "");
}
TEST_F(TenPinBowlingTests, assertCorrectPointsExtractionFromGameDescription)
{
    EXPECT_EQ(sumVector(ConvertStringToVector("Name1:X|4-|3")), 17);
    EXPECT_EQ(sumVector(ConvertStringToVector(":X|22|33")), 20);
    EXPECT_EQ(sumVector(ConvertStringToVector(":")), 0);
    EXPECT_EQ(sumVector(ConvertStringToVector("")), 0);
    EXPECT_EQ(sumVector(ConvertStringToVector("N:1a-m|e/1:X|4-|3")), 17);
}

TEST_F(TenPinBowlingTests, assertCorrectGameStatusForOneLine)
{
    EXPECT_EQ(CheckStatusForPlayer(""), 0);
    EXPECT_EQ(CheckStatusForPlayer(":"), 1);
    EXPECT_EQ(CheckStatusForPlayer(":1"), 1);
    EXPECT_EQ(CheckStatusForPlayer(":X|22|33"), 1);
    EXPECT_EQ(CheckStatusForPlayer("Name1:X|4-|3"), 1);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|00"), 2);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|0"), 1);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55"), 1);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|54"), 2);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|X"), 1);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55||"), 1);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55||5"), 2);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55||55"), 2);
}
TEST_F(TenPinBowlingTests, assertCorrectNameExtractionIfContainsColon)
{
    EXPECT_EQ(GetPlayerName("Name:1:X|4-|3"), "Name:1");
    EXPECT_EQ(GetPlayerName("N:1a-m|e/1:X|4-|3"), "N:1a-m|e/1");
}
