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
TEST(FractionTest, ShortenFractionIfItIsPossibleWhenNominatorIsBiggerThanDenominator)
{
    Fraction f(2,4);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}
TEST(FractionTest, ShortenFractionIfItIsPossibleWhenDenominatorIsBiggerThanNominator)
{
    Fraction f(4,2);
    EXPECT_EQ(f.getNominator(), 2);
    EXPECT_EQ(f.getDenominator(), 1);
}