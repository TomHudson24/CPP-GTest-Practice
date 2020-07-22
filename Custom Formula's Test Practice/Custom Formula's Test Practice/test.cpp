#include "pch.h"
#include <cmath>

double Rounded_Square_Root(const double &value)
{
	if (value == 0)
	{
		return 0;
	}
	else if(value > 0)
	{
		return round(sqrt(value));
	}
	else 
	{
		return sqrt(value);
	}
	
}

TEST(SquareRootTest, OnlyPosNums)
{
	EXPECT_EQ(4, Rounded_Square_Root(16));
	EXPECT_EQ(7, Rounded_Square_Root(50));
	EXPECT_EQ(71, Rounded_Square_Root(5004));
	EXPECT_EQ(40, Rounded_Square_Root(1575));
}
TEST(SquareRootTest, Zero)
{
	ASSERT_EQ(0.0, Rounded_Square_Root(0.0));
}
TEST(SquareRootTest, DISABLED_NegativeNums)
{
	ASSERT_EQ(-1, Rounded_Square_Root(-22));
}