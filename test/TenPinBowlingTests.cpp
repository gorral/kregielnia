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
    EXPECT_EQ(CheckStatusForPlayer(""), Status::NotStarted);
    EXPECT_EQ(CheckStatusForPlayer(":"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer(":1"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer(":X|22|33"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer("Name1:X|4-|3"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|00"), Status::Finished);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|0"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|54"), Status::Finished);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|X"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55||"), Status::InProgress);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55||5"), Status::Finished);
    EXPECT_EQ(CheckStatusForPlayer("Name2:00|00|00|00|00|00|00|00|00|55||55"), Status::Finished);
}

TEST_F(TenPinBowlingTests, assertCorrectNameExtractionIfContainsColon)
{
    EXPECT_EQ(GetPlayerName("Name:1:X|4-|3"), "Name:1");
    EXPECT_EQ(GetPlayerName("N:1a-m|e/1:X|4-|3"), "N:1a-m|e/1");
}

TEST_F(TenPinBowlingTests, assertValidPlayer)
{
    TenPinBowling testgame{"My Bowling Game!", {}, "", ""};
    ASSERT_FALSE(testgame.validPlayer(""));
    ASSERT_TRUE(testgame.validPlayer(":"));
    ASSERT_TRUE(testgame.validPlayer("name:"));
    ASSERT_FALSE(testgame.validPlayer("na$e:"));
    ASSERT_TRUE(testgame.validPlayer("name:-"));
    ASSERT_TRUE(testgame.validPlayer("name:X"));
    ASSERT_TRUE(testgame.validPlayer("name:/"));
    ASSERT_TRUE(testgame.validPlayer("name:-X"));
    ASSERT_TRUE(testgame.validPlayer("name:XX"));
    ASSERT_TRUE(testgame.validPlayer("name:/X"));
    ASSERT_FALSE(testgame.validPlayer("name:a"));
    ASSERT_TRUE(testgame.validPlayer("name:3"));
    ASSERT_TRUE(testgame.validPlayer("name:11|"));
    ASSERT_TRUE(testgame.validPlayer("name:11|XX"));
    ASSERT_FALSE(testgame.validPlayer("name:11|XX||"));
    ASSERT_TRUE(testgame.validPlayer("name:11|XX|2-"));
    ASSERT_FALSE(testgame.validPlayer("name:11|XX|2-||"));
    ASSERT_TRUE(testgame.validPlayer("name:11|XX|33|44|55|66|77|88|99|00||"));
    ASSERT_FALSE(testgame.validPlayer("name:11|XX|33|44|55|66|77|88|99|00|||"));
    ASSERT_TRUE(testgame.validPlayer("name:11|XX|33|44|55|66|77|88|99|00||X"));
    ASSERT_TRUE(testgame.validPlayer("name:11|XX|33|44|55|66|77|88|99|00||X8"));
    ASSERT_FALSE(testgame.validPlayer("name:11|XX|33|44|55|66|77|88|99|00||X8X"));
}
