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
        if(other.getDenominator()%this->getDenominator() == 0 )
        {
            return Fraction(other.getNominator() + this->getNominator()*other.getDenominator()/this->getDenominator(), other.getDenominator() );
        }
        if(this->getDenominator()%other.getDenominator() == 0 )
        {
            return Fraction(other.getNominator()*this->getDenominator()/other.getDenominator() + this->getNominator(), this->getDenominator() );
        }
        return Fraction(other.getNominator()*this->getDenominator() + this->getNominator()*other.getDenominator(), other.getDenominator()*this->getDenominator() );
    }
};
