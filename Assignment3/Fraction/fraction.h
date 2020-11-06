#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Fraction_global.h"

using namespace std;

class FRACTION_EXPORT Fraction
{
public:
    /*+ Constructors -*/
    Fraction();
    Fraction (int);
    Fraction(int, int);

    /*+ Accessors -*/
    int numerator() const;
    int denominator() const;

    /*+ Unary Operator Overloading -*/
    Fraction operator-(); //negation
    Fraction& operator++(); //pre-increment
    Fraction operator++(int); //post-increment

    /*+ Binary Operator Overloading -*/
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs); //addition
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs); //subtraction
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs); //multiplicatio
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs); //division

    Fraction& operator+=(const Fraction& rhs); //Addition and Assignment

    /*+ Comparison Operators -*/
    friend bool operator<(const Fraction& lhs, const Fraction& rhs);
    friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
    friend bool operator==(const Fraction& lhs, const Fraction& rhs);
    friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
    friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
    friend bool operator>(const Fraction& lhs, const Fraction& rhs);

    /*+ Input and Output -*/
    friend ostream& operator<<(ostream& out, const Fraction& fraction); //<< used with cout
    friend istream& operator>>(istream& in, Fraction& fraction); //>> used with cin

    private:
    int num; //numerator value
    int den; //denominator value
    int gcd(int, int); //greatest common denominator function (for simplifying)

};

class FractionException :public std::exception{
public:
    FractionException(const string& error);
    string what();
private:
    string error;
};


#endif // FRACTION_H
