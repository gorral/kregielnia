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
    bool result = true;
    fs::path p1;
    p1 /= Helper::INPUT_FILES_DIRECTORY;
    // GIVEN
    result &= not fs::is_directory(p1);
    // WHEN
    Helper::CreateTestFiles();
    // THEN
    result &= fs::is_directory(p1);
    result &= not fs::is_empty(p1);

    Helper::RemoveTestFiles();
    ASSERT_TRUE(result);

}

TEST_F(KregielniaTests, assertThatCanRemoveTestFiles)
{
    bool result = true;
    // GIVEN
    Helper::CreateTestFiles();
    fs::path p1;
    p1 /= Helper::INPUT_FILES_DIRECTORY;
    result &= not fs::is_empty(p1);
    result &= fs::is_directory(p1);
    // WHEN
    result = Helper::RemoveTestFiles();
    // THEN
    result &= not fs::is_directory(p1);

    ASSERT_TRUE(result);
}
