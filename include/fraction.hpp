#pragma once
#include <cassert>
#include <stdexcept>
#include <iostream>

class Fraction
{
private:
    int nominator;
    int denominator;
    void findCommonDivisor(int divider);
    void reduce();
    void setMinusSign();
public:
    Fraction(int nominator_, int denominator_);
    friend bool operator==(const Fraction& first, const Fraction& second);
    friend bool operator!=(const Fraction& first, const Fraction& second);
    friend Fraction operator- (const Fraction &first, const Fraction &second);
    friend Fraction operator* (const Fraction &first, const Fraction &second);
    friend Fraction operator/ (const Fraction &first, const Fraction &second);
    friend Fraction operator+ (const Fraction& first, const Fraction& second);
    Fraction operator++ ();
    Fraction operator++ (int);
    Fraction operator-- ();
    Fraction operator-- (int);
};

bool operator==(const Fraction& first, const Fraction& second);
bool operator!=(const Fraction& first, const Fraction& second);
Fraction operator+ (const Fraction& first, const Fraction& second);
Fraction operator- (const Fraction &first, const Fraction &second);
Fraction operator* (const Fraction &first, const Fraction &second);
Fraction operator/ (const Fraction &first, const Fraction &second);