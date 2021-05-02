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
    EXPECT_EQ(Fraction(2,4), Fraction(1,2));
}
TEST(FractionTest, ReducePositiveFractionWhenNominatorIsMultipleDenominator)
{
    EXPECT_EQ(Fraction(4,2), Fraction(2,1));
}
TEST(FractionTest, ReducePositiveFractionWhenNominatorAndDenominatorHaveSameDivider)
{
    EXPECT_EQ(Fraction(9,12), Fraction(3,4));
}
TEST(FractionTest, ReduceNegativeAndPositiveFractionWhenNominatorAndDenominatorHaveSameDivider)
{
    EXPECT_EQ(Fraction(-12,-15), Fraction(4,5));
}
TEST(FractionTest, AddFractionWithTheSameDenominator)
{
    EXPECT_EQ(Fraction(1,2) + Fraction(1,2), Fraction(1,1));
}
TEST(FractionTest, AddShortFractionWithDiferentDenominator)
{
    EXPECT_EQ(Fraction(1,2)+Fraction(1,3), Fraction(5,6));
}
TEST(FractionTest, AddFractionWithDiferentDenominatorWhenOneDenominatorIsMultipleOfOther)
{
    EXPECT_EQ(Fraction(5,4)+Fraction(7,8), Fraction(17,8));
}
TEST(FractionTest, AddFractionWithDiferentDenominator3WhenOneDenominatorIsMultipleOfOther2)
{

    EXPECT_EQ(Fraction(7,8)+Fraction(5,4), Fraction(17,8));
}
TEST(FractionTest, AddFractionWithDiferentDenominatorBigNumbers)
{
    EXPECT_EQ(Fraction(9999,8888)+Fraction(12,1119), Fraction(3389,2984));
}
TEST(FractionTest, AddFractionWithDiferentDenominatorWhenOneDenominatorIsMultipleOfOtherForAssigmentOperator)
{
    Fraction f1(5,4);
    Fraction f2(7,8);
    Fraction f3 = f1 + f2;
    EXPECT_EQ(f3, Fraction(17,8));
}
TEST(FractionTest, FractionWithMinusNominatorAndDenominatorIsChangedToPlus)
{
    EXPECT_EQ(Fraction(-2,-3), Fraction(2,3));
}
TEST(FractionTest, FractionWithMinusDenominatorIsChangedToMinusNominator)
{
    EXPECT_EQ(Fraction(2,-3), Fraction(-2,3));
}
TEST(FractionTest, AddFractionWithMinusSign)
{
    EXPECT_EQ(Fraction(-2,3)+ Fraction(7,6), Fraction(1,2));
}
TEST(FractionTest, AddFractionWithMinusSign2)
{
    Fraction f = Fraction(-9,-12) + Fraction(1,4);
    EXPECT_EQ(f, Fraction(1,1));
}
TEST(FractionTest, AddedFractionGivenOne)
{
    EXPECT_EQ(Fraction(1,2) + Fraction(1,2), Fraction(1,1) );
}
TEST(FractionTest, AddedFractionGivenZero)
{
    EXPECT_EQ(Fraction(1,2) + Fraction(-1,2), Fraction(0,1) );
} 
TEST(FractionTest, SubstractFractionsWithTheSameDenominators)
{
    Fraction f = Fraction(-9,-12) - Fraction(1,4);
    EXPECT_EQ(f, Fraction(1,2));
}
TEST(FractionTest, SubstractFractionsWithDiferentDenominators)
{
    Fraction f = Fraction(1,6) - Fraction(1,2);
    EXPECT_EQ(f, Fraction(-1,3));
}
TEST(FractionTest, SubstractFractionsWithDiferentDenominatorsInversely)
{
    Fraction f = Fraction(1,2) - Fraction(1,6);
    EXPECT_EQ(f, Fraction(1,3));
}
TEST(FractionTest, MultiplySimplePositiveFractions)
{
    Fraction f = Fraction(1,2) * Fraction(1,6);
    EXPECT_EQ(f, Fraction(1,12));
}
TEST(FractionTest, MultiplyReducedPositiveFractions)
{
    Fraction f = Fraction(4,5) * Fraction(7,12);
    EXPECT_EQ(f, Fraction(7,15));
}
TEST(FractionTest, MultiplyNegativeAndPositiveFractions)
{
    Fraction f = Fraction(-1,2) * Fraction(1,6);
    EXPECT_EQ(f, Fraction(-1,12));
}
TEST(FractionTest, MultiplyNegativeFractions)
{
    Fraction f = Fraction(-1,2) * Fraction(1,-6);
    EXPECT_EQ(f, Fraction(1,12));
}
TEST(FractionTest, MultiplyReducedNegativeFractions)
{
    Fraction f = Fraction(-4,2) * Fraction(-1,16);
    EXPECT_EQ(f, Fraction(1,8));
}
TEST(FractionTest, DevideSimplePositiveFractions)
{
    Fraction f = Fraction(1,2) / Fraction(1,3);
    EXPECT_EQ(f, Fraction(3,2));
}
TEST(FractionTest, DevideReducedPositiveFractions)
{
    Fraction f = Fraction(6,5) / Fraction(3,2);
    EXPECT_EQ(f, Fraction(4,5));
}
TEST(FractionTest, DevideReducedNegativeAndPositiveFractions)
{
    Fraction f = Fraction(6,-5) / Fraction(3,2);
    EXPECT_EQ(f, Fraction(-4,5));
}
TEST(FractionTest, DevideReducedNegativeFractions)
{
    Fraction f = Fraction(6,-5) / Fraction(-3,2);
    EXPECT_EQ(f, Fraction(4,5));
}
TEST(FractionTest, FractionEqualOperatorWorks)
{
    EXPECT_EQ(Fraction(2,-4), Fraction(-1,2) );
}
TEST(FractionTest, FractionNotEqualOperatorWorks)
{
    EXPECT_NE(Fraction(2,4), Fraction(-1,2) );
}
TEST(FractionTest, OperatorPreIncrementationWorks)
{
    EXPECT_EQ(++Fraction(1,2), Fraction(3,2) );
}
TEST(FractionTest, OperatorPreDecrementationWorks)
{
    EXPECT_EQ(--Fraction(1,2), Fraction(-1,2) );
}
TEST(FractionTest, OperatorPostIncrementationWorks)
{
    EXPECT_EQ(Fraction(1,2)++, Fraction(3,2) );
}
TEST(FractionTest, OperatorPostDecrementationWorks)
{
    EXPECT_EQ(Fraction(1,2)--, Fraction(-1,2) );
}