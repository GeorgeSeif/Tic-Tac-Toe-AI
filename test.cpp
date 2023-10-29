#include <gtest/gtest.h>
#include <utils.cpp>

TEST(ExceptionTests, Invalidcin) {
	EXPECT_THROW(get_row(), std::runtime_error);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
