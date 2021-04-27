#include "fraction.hpp"

Fraction::Fraction(int nominator_, int denominator_): nominator(nominator_), denominator(denominator_)
{
    if(denominator == 0)
        throw std::logic_error("Denominator can't be zero value");
    else if(denominator_%nominator_ == 0)
    {
        nominator = 1;
        denominator = denominator_/nominator_;
    }
    else if(nominator%denominator == 0)
    {
        nominator = nominator_/denominator_;
        denominator = 1;
    }
    for(auto i = std::max(nominator, denominator); i > 1; i--)
    {
        findCommonDivisor(i);
    }
    setMinusSign();
}
int Fraction::getNominator()
{
    return nominator;
}
int Fraction::getDenominator()
{
    return denominator;
}
Fraction Fraction::operator+ (Fraction other)
{
    if(other.getDenominator() == this->getDenominator())
        return Fraction(other.getNominator()+this->getNominator(),other.getDenominator());
    else if(other.getDenominator()%this->getDenominator() == 0 )
    {
        return Fraction(other.getNominator() + this->getNominator()*other.getDenominator()/this->getDenominator(), other.getDenominator() );
    }
    else if(this->getDenominator()%other.getDenominator() == 0 )
    {
        return Fraction(other.getNominator()*this->getDenominator()/other.getDenominator() + this->getNominator(), this->getDenominator() );
    }
    else
        return Fraction(other.getNominator()*this->getDenominator() + this->getNominator()*other.getDenominator(), other.getDenominator()*this->getDenominator() );
}
int Fraction::findCommonDivisor(int divider)
{
    if(nominator%divider == 0 && denominator%divider == 0)
    {
        nominator /= divider;
        denominator /= divider;
        return divider;
    }      
    else
        return -1;
}
void Fraction::setMinusSign()
{
    if( (denominator < 0 && nominator < 0) || (denominator < 0 && nominator > 0) )
    {
        nominator *= -1;
        denominator *= -1;
    }
}