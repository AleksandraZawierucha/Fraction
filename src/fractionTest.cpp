#include "gtest/gtest.h"
#include "fraction.hpp"

// struct FractionTestFixture : public ::testing::Test
// {
    
// };

TEST(FractionTest, CreateFraction)
{
    Fraction(1,2);
}
TEST(FractionTest, CreateFractionWithZeroDenominator)
{
    EXPECT_THROW(Fraction(1,0), std::logic_error);
}
