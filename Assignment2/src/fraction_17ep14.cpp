#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
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
    numerator += denominator;
    return *this;
}
Fraction Fraction::operator ++ (int num) {
    Fraction temp = *this;
    numerator += denominator;
    return temp;
}

Fraction Fraction::operator += (const Fraction& fracOne) {
    if (denominator == fracOne.denominator) {
        numerator += fracOne.numerator;
    } else {
        int gcd = ((numerator*fracOne.denominator),(denominator*fracOne.numerator));
        numerator = (numerator*fracOne.denominator)/gcd;
        denominator = (denominator*fracOne.numerator)/gcd;
    }
}



Fraction operator + (const Fraction& fracOne, const Fraction& fracTwo) {
    if (fracOne.denominator == fracTwo.denominator) {
        return ( Fraction((fracOne.numerator + fracTwo.numerator), fracOne.denominator));
    } else {
        return ((fracOne.numerator*fracTwo.denominator + fracTwo.numerator*fracOne.denominator),(fracOne.denominator*fracTwo.denominator));
    }
}

Fraction operator - (const Fraction& fracOne, const Fraction& fracTwo) {
     if (fracOne.denominator == fracTwo.denominator) {
        return ( Fraction((fracOne.numerator - fracTwo.numerator),fracOne.denominator));
    } else {
        return ((fracOne.numerator*fracTwo.denominator - fracTwo.numerator*fracOne.denominator),(fracOne.denominator*fracTwo.denominator));
    }
}

Fraction operator * (const Fraction& fracOne, const Fraction& fracTwo) {
    return ((fracOne.numerator*fracTwo.numerator),(fracOne.denominator*fracTwo.denominator));

}

Fraction operator / (const Fraction& fracOne, const Fraction& fracTwo) {
    return ((fracOne.numerator*fracTwo.denominator),(fracOne.denominator*fracTwo.numerator));
}



bool operator < (const Fraction& lesser, const Fraction& greater) {
    if (lesser.denominator == greater.denominator) {
        if (lesser.numerator < greater.numerator)
            return false;
        return true;
    } else {
        if (lesser.numerator*greater.denominator < greater.numerator*lesser.denominator)
            return true;
        return false;
    }
}

bool operator > (const Fraction& greater, const Fraction& lesser) {
    if (greater.denominator == lesser.denominator) {
        if (greater.numerator > lesser.numerator)
            return false;
        return true;
    } else {
        if (greater.numerator*lesser.denominator > lesser.numerator*greater.denominator)
            return true;
        return false;
    }
}

bool Fraction::operator <= (const Fraction& greater) {
    if (denominator == greater.denominator) {
        if (numerator <= greater.numerator) {
            return false;
        }
        return true;
    } else {
        numerator = numerator*greater.denominator;
        if (numerator <= greater.numerator*denominator) {
            return true;
        }
        return false;
    }
}

bool Fraction::operator == (const Fraction& fracOne) {
    if (numerator == fracOne.numerator&& denominator == fracOne.denominator) {
        return true;
    } else {
        return false;
    }

}


bool Fraction::operator >= (const Fraction& lesser) {
    if (denominator == lesser.denominator) {
        if (numerator >= lesser.numerator) {
            return false;
        }
        return true;
    } else {
        numerator = numerator*lesser.denominator;
        if (numerator >= lesser.numerator*denominator) {
            return true;
        }
        return false;
    }
}

bool operator != (const Fraction& fracOne, const Fraction& fracTwo) {
    if ( fracOne.numerator != fracTwo.numerator || fracOne.denominator != fracTwo.denominator) {
        return true;
    }
    else {
        return false;
    }
}
 


ostream& operator << (ostream& outStream, const Fraction& frac) {
    outStream << frac.getNumerator() << "/" << frac.getDenominator();
    return outStream;
}


istream& operator >> (istream& inStream, Fraction& fraction) {
    string input;
    
    int n, d;
    getline(inStream, input);
    string numeratorString;
    string denominatorString;
    
    bool slash = false;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '/') {
            slash = true;
        }
    }
    
    
    if (slash) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '/') {
                numeratorString.append(input.substr(0,i));
                denominatorString.append(input.substr(i+1,input.length() - 1));
                fraction.numerator = atoi(numeratorString.c_str());
                fraction.denominator = atoi(denominatorString.c_str());
            }
        }
    } else {
        fraction.numerator = atoi(input.c_str());
        fraction.denominator = 1;
    }
    return inStream;
}

FractionException::FractionException(const string& message) : message(message) {}

string& FractionException::what() { 
    return message; 
}
