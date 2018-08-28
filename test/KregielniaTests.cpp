#include <gtest/gtest.h>
#include "Kregielnia.hpp"

struct KregielniaTests : public ::testing::Test
{
};

TEST_F(KregielniaTests, assertThatTravisCiBuildStatusIsPass)
{
    ASSERT_TRUE(true);
}

TEST_F(KregielniaTests, assertThatCanCreateTestFiles)
{
    const std::string inputfiles_directory = "test_files";
    fs::path testfile_path = fs::current_path() /= inputfiles_directory;

    // GIVEN
    ASSERT_FALSE(fs::is_directory(testfile_path));
    // WHEN
    ASSERT_TRUE(TestFileSupport::CreateTestFiles(inputfiles_directory));
    // THEN
    ASSERT_TRUE(fs::is_directory(testfile_path));
    ASSERT_FALSE(fs::is_empty(testfile_path));

    TestFileSupport::RemoveTestFiles(inputfiles_directory);
}

TEST_F(KregielniaTests, assertThatCanRemoveTestFiles)
{
    const std::string inputfiles_directory = "test_files";
    // GIVEN
    TestFileSupport::CreateTestFiles(inputfiles_directory);
    fs::path testfile_path = fs::current_path() /= inputfiles_directory;
    ASSERT_FALSE(fs::is_empty(testfile_path));
    ASSERT_TRUE(fs::is_directory(testfile_path));
    // WHEN
    ASSERT_TRUE(TestFileSupport::RemoveTestFiles(inputfiles_directory));
    // THEN
    ASSERT_FALSE(fs::is_directory(testfile_path));
}
