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
TEST(FractionTest, AddFractionWithTheSameDenominator)
{
    Fraction f1(1,2);
    Fraction f2 = f1+Fraction(1,2);
    EXPECT_EQ(f2.getNominator(), 1);
    EXPECT_EQ(f2.getDenominator(), 1);
}
TEST(FractionTest, AddFractionWithDiferentDenominator)
{
    Fraction f1(1,2);
    Fraction f2 = f1+Fraction(1,3);
    EXPECT_EQ(f2.getNominator(), 5);
    EXPECT_EQ(f2.getDenominator(), 6);
}
TEST(FractionTest, AddFractionWithDiferentDenominator2)
{
    Fraction f1(5,4);
    Fraction f2 = f1+Fraction(7,8);
    EXPECT_EQ(f2.getNominator(), 17);
    EXPECT_EQ(f2.getDenominator(), 8);
}
TEST(FractionTest, AddFractionWithDiferentDenominator3)
{
    Fraction f1(7,8);
    Fraction f2 = f1+Fraction(5,4);
    EXPECT_EQ(f2.getNominator(), 17);
    EXPECT_EQ(f2.getDenominator(), 8);
}
TEST(FractionTest, AddFractionWithDiferentDenominator4)
{
    Fraction f1(3,2);
    Fraction f2 = f1+Fraction(1,6);
    EXPECT_EQ(f2.getNominator(), 10);
    EXPECT_EQ(f2.getDenominator(), 6);
}