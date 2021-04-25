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
    Fraction operator+ (Fraction other)
    {
        if(other.getDenominator() == this->getDenominator())
            return Fraction(other.getNominator()+this->getNominator(),other.getDenominator());
        return Fraction(other.getNominator()*this->getDenominator() + this->getNominator()*other.getDenominator(), other.getDenominator()*this->getDenominator() );

    }
};
