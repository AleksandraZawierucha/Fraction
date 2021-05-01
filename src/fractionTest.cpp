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
TEST(FractionTest, ReducePositiveFractionWhenDenominatorIsMultipleNominator)
{
    Fraction f(2,4);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}
TEST(FractionTest, ReducePositiveFractionWhenNominatorIsMultipleDenominator)
{
    Fraction f(4,2);
    EXPECT_EQ(f.getNominator(), 2);
    EXPECT_EQ(f.getDenominator(), 1);
}
TEST(FractionTest, ReducePositiveFractionWhenNominatorAndDenominatorHaveSameDivider)
{
    Fraction f(9,12);
    EXPECT_EQ(f.getNominator(), 3);
    EXPECT_EQ(f.getDenominator(), 4);
}
TEST(FractionTest, ReduceNegativeAndPositiveFractionWhenNominatorAndDenominatorHaveSameDivider)
{
    Fraction f = Fraction(-12,-15);
    EXPECT_EQ(f.getNominator(), 4);
    EXPECT_EQ(f.getDenominator(), 5);
}
TEST(FractionTest, AddFractionWithTheSameDenominator)
{
    Fraction f1(1,2);
    Fraction f2 = f1+Fraction(1,2);
    EXPECT_EQ(f2.getNominator(), 1);
    EXPECT_EQ(f2.getDenominator(), 1);
}
TEST(FractionTest, AddShortFractionWithDiferentDenominator)
{
    Fraction f1(1,2);
    Fraction f2 = f1+Fraction(1,3);
    EXPECT_EQ(f2.getNominator(), 5);
    EXPECT_EQ(f2.getDenominator(), 6);
}
TEST(FractionTest, AddFractionWithDiferentDenominatorWhenOneDenominatorIsMultipleOfOther)
{
    Fraction f1(5,4);
    Fraction f2 = f1+Fraction(7,8);
    EXPECT_EQ(f2.getNominator(), 17);
    EXPECT_EQ(f2.getDenominator(), 8);
}
TEST(FractionTest, AddFractionWithDiferentDenominator3WhenOneDenominatorIsMultipleOfOther2)
{
    Fraction f1(7,8);
    Fraction f2 = f1+Fraction(5,4);
    EXPECT_EQ(f2.getNominator(), 17);
    EXPECT_EQ(f2.getDenominator(), 8);
}
TEST(FractionTest, AddFractionWithDiferentDenominatorBigNumbers)
{
    Fraction f1(9999,8888);
    Fraction f2 = f1+Fraction(12,1119);
    EXPECT_EQ(f2.getNominator(), 3389);
    EXPECT_EQ(f2.getDenominator(), 2984);
}
TEST(FractionTest, AddFractionWithDiferentDenominatorWhenOneDenominatorIsMultipleOfOtherForAssigmentOperator)
{
    Fraction f1(5,4);
    Fraction f2(7,8);
    Fraction f3 = f1 + f2;
    EXPECT_EQ(f3.getNominator(), 17);
    EXPECT_EQ(f3.getDenominator(), 8);
}
TEST(FractionTest, FractionWithMinusNominatorAndDenominatorIsChangedToPlus)
{
    Fraction f(-2,-3);
    EXPECT_EQ(f.getNominator(), 2);
    EXPECT_EQ(f.getDenominator(), 3);
}
TEST(FractionTest, FractionWithMinusDenominatorIsChangedToMinusNominator)
{
    Fraction f(2,-3);
    EXPECT_EQ(f.getNominator(), -2);
    EXPECT_EQ(f.getDenominator(), 3);
}
TEST(FractionTest, AddFractionWithMinusSign)
{
    Fraction f = Fraction(-2,3) + Fraction(7,6);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}
TEST(FractionTest, AddFractionWithMinusSign2)
{
    Fraction f = Fraction(-9,-12) + Fraction(1,4);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 1);
}
TEST(FractionTest, SubstractFractionsWithTheSameDenominators)
{
    Fraction f = Fraction(-9,-12) - Fraction(1,4);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}
TEST(FractionTest, SubstractFractionsWithDiferentDenominators)
{
    Fraction f = Fraction(1,6) - Fraction(1,2);
    EXPECT_EQ(f.getNominator(), -1);
    EXPECT_EQ(f.getDenominator(), 3);
}
TEST(FractionTest, SubstractFractionsWithDiferentDenominatorsInversely)
{
    Fraction f = Fraction(1,2) - Fraction(1,6);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 3);
}
TEST(FractionTest, MultiplySimplePositiveFractions)
{
    Fraction f = Fraction(1,2) * Fraction(1,6);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 12);
}
TEST(FractionTest, MultiplyReducedPositiveFractions)
{
    Fraction f = Fraction(4,5) * Fraction(7,12);
    EXPECT_EQ(f.getNominator(), 7);
    EXPECT_EQ(f.getDenominator(), 15);
}
TEST(FractionTest, MultiplyNegativeAndPositiveFractions)
{
    Fraction f = Fraction(-1,2) * Fraction(1,6);
    EXPECT_EQ(f.getNominator(), -1);
    EXPECT_EQ(f.getDenominator(), 12);
}
TEST(FractionTest, MultiplyNegativeFractions)
{
    Fraction f = Fraction(-1,2) * Fraction(1,-6);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 12);
}
TEST(FractionTest, MultiplyReducedNegativeFractions)
{
    Fraction f = Fraction(-4,2) * Fraction(-1,16);
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 8);
}
TEST(FractionTest, DevideSimplePositiveFractions)
{
    Fraction f = Fraction(1,2) / Fraction(1,3);
    EXPECT_EQ(f.getNominator(), 3);
    EXPECT_EQ(f.getDenominator(), 2);
}
TEST(FractionTest, DevideReducedPositiveFractions)
{
    Fraction f = Fraction(6,5) / Fraction(3,2);
    EXPECT_EQ(f.getNominator(), 4);
    EXPECT_EQ(f.getDenominator(), 5);
}
TEST(FractionTest, DevideReducedNegativeAndPositiveFractions)
{
    Fraction f = Fraction(6,-5) / Fraction(3,2);
    EXPECT_EQ(f.getNominator(), -4);
    EXPECT_EQ(f.getDenominator(), 5);
}
TEST(FractionTest, DevideReducedNegativeFractions)
{
    Fraction f = Fraction(6,-5) / Fraction(-3,2);
    EXPECT_EQ(f.getNominator(), 4);
    EXPECT_EQ(f.getDenominator(), 5);
}