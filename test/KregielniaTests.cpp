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
    bool result = false;
    Helper::CreateTestFiles();
    fs::path p1;
    p1 /= Helper::INPUT_FILES_DIRECTORY;
    result = fs::is_empty(p1);

    ASSERT_FALSE(result);
}

TEST_F(KregielniaTests, assertThatCanRemoveTestFiles)
{
    bool result = true;
    Helper::CreateTestFiles();
    fs::path p1;
    p1 /= Helper::INPUT_FILES_DIRECTORY;
    result &= not fs::is_empty(p1);
    result &= fs::is_directory(p1);
    result = Helper::RemoveTestFiles();
    result &= not fs::is_directory(p1);

    ASSERT_TRUE(result);
}
