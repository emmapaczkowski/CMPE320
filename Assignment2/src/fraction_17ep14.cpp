#include <iostream>
#include <algorithm>
#include <cmath>
#include "fraction_17ep14.h"

using namespace std;

Fraction::Fraction() : numerator(0), denominator(0) { }

Fraction::Fraction(int num) : numerator(num), denominator(1) {}

Fraction::Fraction(int num, int denom) {
   int gcd = greatestCommonDivisor(num, denom);
   this->setNumerator(num/gcd);
   this->setDenominator(denom/gcd);
} 

Fraction Fraction::operator - (void) const {
    return(Fraction(-numerator, denominator));
}

Fraction Fraction::operator ++ () {

}

Fraction Fraction::operator ++ (int num) {

}



Fraction operator + (const Fraction& fracOne, const Fraction& fracTwo) {

}

Fraction operator - (const Fraction& fracOne, const Fraction& fracTwo) {

}

Fraction operator * (const Fraction& fracOne, const Fraction& fracTwo) {

}

Fraction operator / (const Fraction& fracOne, const Fraction& fracTwo) {

}



bool operator < (const Fraction& fracOne, const Fraction& fracTwo) {

}

bool operator <= (const Fraction& fracOne, const Fraction& fracTwo) {

}

bool operator == (const Fraction& fracOne, const Fraction& fracTwo) {

}

bool operator != (const Fraction& fracOne, const Fraction& fracTwo) {

}

bool operator >= (const Fraction& fracOne, const Fraction& fracTwo) {

}

bool operator > (const Fraction& fracOne, const Fraction& fracTwo) {

}
 


ostream& operator << (const Fraction& fracOne, const Fraction& fracTwo) {

}

istream& operator >> (const Fraction& fracOne, const Fraction& fracTwo) {

}
