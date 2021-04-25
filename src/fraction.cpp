#include "fraction.hpp"

Fraction::Fraction(int nominator_, int denominator_): nominator(nominator_), denominator(denominator_)
{
    if(denominator == 0)
        throw std::logic_error("Denominator cant be zero value");
}