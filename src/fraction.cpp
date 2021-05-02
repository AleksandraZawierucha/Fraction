#include "fraction.hpp"

Fraction::Fraction(int nominator_, int denominator_): nominator(nominator_), denominator(denominator_)
{
    if(denominator == 0)
        throw std::logic_error("Denominator can't be zero value");
    else if(nominator == 0)
            denominator = 1;
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
    reduce();
    if(nominator_ < 0 || denominator_ < 0)
    setMinusSign();
}
int Fraction::getNominator() const
{
    return nominator;
}
int Fraction::getDenominator() const
{
    return denominator;
}
void Fraction::findCommonDivisor(int divider)
{
    if(nominator%divider == 0 && denominator%divider == 0)
    {
        nominator /= divider;
        denominator /= divider;
    }      
}
void Fraction::reduce()
{
    unsigned nominatorCheck = nominator >= 0 ? nominator : -nominator;
    unsigned denominatorCheck = denominator >= 0 ? denominator : -denominator;
    for(auto i = std::max(nominatorCheck, denominatorCheck); i > 1; i--)
    {
        findCommonDivisor(i);
    }
}
void Fraction::setMinusSign()
{
    if( (denominator < 0 && nominator < 0) || (denominator < 0 && nominator > 0) )
    {
        nominator *= -1;
        denominator *= -1;
    }
}
Fraction operator-(const Fraction &first, const Fraction &second)
{
    if (second.getDenominator() == first.getDenominator())
        return Fraction(first.getNominator() - second.getNominator(), second.getDenominator());
    else if (second.getDenominator() % first.getDenominator() == 0)
    {
        return Fraction(first.getNominator() * second.getDenominator() / first.getDenominator() - second.getNominator(), second.getDenominator());
    }
    else if (first.getDenominator() % second.getDenominator() == 0)
    {
        return Fraction(first.getNominator() - second.getNominator() * first.getDenominator() / second.getDenominator(), first.getDenominator());
    }
    else
        return Fraction(first.getNominator() * second.getDenominator() - second.getNominator() * first.getDenominator(), second.getDenominator() * first.getDenominator());
}
Fraction operator* (const Fraction &first, const Fraction &second)
{
    return Fraction(first.getNominator()*second.getNominator(), first.getDenominator()*second.getDenominator());
}
Fraction operator/ (const Fraction &first, const Fraction &second)
{
    return Fraction(first.getNominator()*second.getDenominator(), first.getDenominator()*second.getNominator());
}
bool operator==(const Fraction& first, const Fraction& second)
{
    if(first.getNominator() == second.getNominator() && first.getDenominator() == second.getDenominator())
        return true;
    return false;
}
bool operator!=(const Fraction& first, const Fraction& second)
{
    if(first.getNominator() == second.getNominator() && first.getDenominator() == second.getDenominator())
        return false;
    return true;
}
Fraction operator+ (const Fraction& first, const Fraction& second)
{
    if(first.getDenominator() == second.getDenominator())
        return Fraction(second.getNominator()+first.getNominator(),second.getDenominator());
    else if(second.getDenominator()%first.getDenominator() == 0 )
    {
        return Fraction(second.getNominator() + first.getNominator()*second.getDenominator()/first.getDenominator(), second.getDenominator() );
    }
    else if(first.getDenominator()%second.getDenominator() == 0 )
    {
        return Fraction(second.getNominator()*first.getDenominator()/second.getDenominator() + first.getNominator(), first.getDenominator() );
    }
    else
        return Fraction(second.getNominator()*first.getDenominator() + first.getNominator()*second.getDenominator(), second.getDenominator()*first.getDenominator() );
}
Fraction Fraction::operator++ ()
{
    return Fraction(this->nominator+this->denominator , this->denominator);
}
Fraction Fraction::operator++ (int)
{
    return Fraction(this->nominator+this->denominator , this->denominator);
}
Fraction Fraction::operator-- ()
{
    return Fraction(this->nominator-this->denominator , this->denominator);
}
Fraction Fraction::operator-- (int)
{
    return Fraction(this->nominator-this->denominator , this->denominator);
}