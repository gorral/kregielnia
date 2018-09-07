#include <gtest/gtest.h>
#include "InputFile.hpp"
#include "TenPinBowling.hpp"

struct TenPinBowlingTests : public ::testing::Test
{
};

TEST_F(TenPinBowlingTests, assertThatTravisCiBuildStatusIsPass)
{
    ASSERT_TRUE(true);
}

TEST_F(KregielniaTests, assertThatLoadInputFileFunctionReadAllFiles)
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
