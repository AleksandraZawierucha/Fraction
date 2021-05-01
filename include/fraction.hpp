#pragma once
#include <cassert>
#include <stdexcept>
#include <iostream>

class Fraction
{
    int nominator;
    int denominator;
    void findCommonDivisor(int divider);
    void reduce();
    void setMinusSign();
public:
    Fraction(int nominator_, int denominator_);
    int getNominator();
    int getDenominator();
    Fraction operator+ (Fraction other);
    Fraction operator- (Fraction other);
    Fraction operator* (Fraction other);
    Fraction operator/ (Fraction other);
};
