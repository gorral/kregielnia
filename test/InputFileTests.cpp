#include <gtest/gtest.h>
#include "InputFile.hpp"

struct InputFileSupportTests : public ::testing::Test
{
};

TEST_F(InputFileSupportTests, assertThatCanCreateInputFiles)
{
    const std::string inputfiles_directory = "test_files";
    fs::path testfile_path = fs::current_path() /= inputfiles_directory;

    // GIVEN
    ASSERT_FALSE(fs::is_directory(testfile_path));
    // WHEN
    ASSERT_TRUE(InputFile::Create(inputfiles_directory));
    // THEN
    ASSERT_TRUE(fs::is_directory(testfile_path));
    ASSERT_FALSE(fs::is_empty(testfile_path));

    InputFile::Remove(inputfiles_directory);
}

TEST_F(InputFileSupportTests, assertThatCanRemoveInputFiles)
{
    const std::string inputfiles_directory = "test_files";
    // GIVEN
    InputFile::Create(inputfiles_directory);
    fs::path testfile_path = fs::current_path() /= inputfiles_directory;
    ASSERT_FALSE(fs::is_empty(testfile_path));
    ASSERT_TRUE(fs::is_directory(testfile_path));
    // WHEN
    ASSERT_TRUE(InputFile::Remove(inputfiles_directory));
    // THEN
    ASSERT_FALSE(fs::is_directory(testfile_path));
}
