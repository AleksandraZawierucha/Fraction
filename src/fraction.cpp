#include "fraction.hpp"

Fraction::Fraction(int nominator_, int denominator_): nominator(nominator_), denominator(denominator_)
{
    if(denominator == 0)
        throw std::logic_error("Denominator cant be zero value");
    if(denominator_%nominator_ == 0)
    {
        nominator = nominator_/nominator_;
        denominator = denominator_/nominator_;
    }
     if(nominator%denominator == 0)
    {
        nominator = nominator_/denominator_;
        denominator = denominator_/denominator_;
    }
}
int Fraction::getNominator()
{
    return nominator;
}
int Fraction::getDenominator()
{
    return denominator;
}