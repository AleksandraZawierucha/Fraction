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
Fraction operator+ (const Fraction& first, const Fraction& second)
{
    if(first.denominator == second.denominator)
        return Fraction(second.nominator+first.nominator,second.denominator);
    else if(second.denominator%first.denominator == 0 )
    {
        return Fraction(second.nominator + first.nominator*second.denominator/first.denominator, second.denominator );
    }
    else if(first.denominator%second.denominator == 0 )
    {
        return Fraction(second.nominator*first.denominator/second.denominator + first.nominator, first.denominator );
    }
    else
        return Fraction(second.nominator*first.denominator + first.nominator*second.denominator, second.denominator*first.denominator );
}
Fraction operator-(const Fraction &first, const Fraction &second)
{
    if (second.denominator == first.denominator)
        return Fraction(first.nominator - second.nominator, second.denominator);
    else if (second.denominator % first.denominator == 0)
    {
        return Fraction(first.nominator * second.denominator / first.denominator - second.nominator, second.denominator);
    }
    else if (first.denominator % second.denominator == 0)
    {
        return Fraction(first.nominator - second.nominator * first.denominator / second.denominator, first.denominator);
    }
    else
        return Fraction(first.nominator * second.denominator - second.nominator * first.denominator, second.denominator * first.denominator);
}
Fraction operator* (const Fraction &first, const Fraction &second)
{
    return Fraction(first.nominator*second.nominator, first.denominator*second.denominator);
}
Fraction operator/ (const Fraction &first, const Fraction &second)
{
    return Fraction(first.nominator*second.denominator, first.denominator*second.nominator);
}
bool operator==(const Fraction& first, const Fraction& second)
{
    if(first.nominator == second.nominator && first.denominator == second.denominator)
        return true;
    return false;
}
bool operator!=(const Fraction& first, const Fraction& second)
{
    if(first.nominator == second.nominator && first.denominator == second.denominator)
        return false;
    return true;
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