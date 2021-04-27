#pragma once
#include <cassert>
#include <stdexcept>
#include <iostream>

class Fraction
{
    int nominator;
    int denominator;
    int findCommonDivisor(int divider);
    void setMinusSign();
public:
    Fraction(int nominator_, int denominator_);
    int getNominator();
    int getDenominator();
    Fraction operator+ (Fraction other);
};
