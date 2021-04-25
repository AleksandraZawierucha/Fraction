#pragma once
#include <cassert>
#include <stdexcept>

class Fraction
{
    int nominator;
    int denominator;
public:
    Fraction(int nominator_, int denominator_);
    int getNominator();
    int getDenominator();
};