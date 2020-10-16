#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "fraction_17ep14.h"

using namespace std;

Fraction::Fraction() : num(0), denom(0) { }
Fraction::Fraction(int numer) : num(numer), denom(1) {}
Fraction::Fraction(int numer, int denomin) {
   int gcd = greatestCommonDivisor(numer, denomin);
   this->setnum(numer/gcd);
   this->setdenom(denomin/gcd);
} 


Fraction Fraction::operator - (void) const {
    return(Fraction(-num, denom));
}
Fraction Fraction::operator ++ () {
    num += denom;
    return *this;
}
Fraction Fraction::operator ++ (int numer) {
    Fraction temp = *this;
    numer += denom;
    return temp;
}

Fraction Fraction::operator += (const Fraction& fracOne) {
    if (denom == fracOne.denom) {
        num += fracOne.num;
    } else {
        int gcd = ((num*fracOne.denom),(denom*fracOne.num));
        num = (num*fracOne.denom)/gcd;
        denom = (denom*fracOne.num)/gcd;
    }
}



Fraction operator + (const Fraction& fracOne, const Fraction& fracTwo) {
    if (fracOne.denom == fracTwo.denom) {
        return ( Fraction((fracOne.num + fracTwo.num), fracOne.denom));
    } else {
        return ((fracOne.num*fracTwo.denom + fracTwo.num*fracOne.denom),(fracOne.denom*fracTwo.denom));
    }
}

Fraction operator - (const Fraction& fracOne, const Fraction& fracTwo) {
     if (fracOne.denom == fracTwo.denom) {
        return ( Fraction((fracOne.num - fracTwo.num),fracOne.denom));
    } else {
        return ((fracOne.num*fracTwo.denom - fracTwo.num*fracOne.denom),(fracOne.denom*fracTwo.denom));
    }
}

Fraction operator * (const Fraction& fracOne, const Fraction& fracTwo) {
    return ((fracOne.num*fracTwo.num),(fracOne.denom*fracTwo.denom));

}

Fraction operator / (const Fraction& fracOne, const Fraction& fracTwo) {
    return ((fracOne.num*fracTwo.denom),(fracOne.denom*fracTwo.num));
}



bool operator < (const Fraction& lesser, const Fraction& greater) {
    if (lesser.denom == greater.denom) {
        if (lesser.num < greater.num)
            return false;
        return true;
    } else {
        if (lesser.num*greater.denom < greater.num*lesser.denom)
            return true;
        return false;
    }
}

bool operator > (const Fraction& greater, const Fraction& lesser) {
    if (greater.denom == lesser.denom) {
        if (greater.num > lesser.num)
            return false;
        return true;
    } else {
        if (greater.num*lesser.denom > lesser.num*greater.denom)
            return true;
        return false;
    }
}

bool Fraction::operator <= (const Fraction& greater) {
    if (denom == greater.denom) {
        if (num <= greater.num) {
            return false;
        }
        return true;
    } else {
        num = num*greater.denom;
        if (num <= greater.num*denom) {
            return true;
        }
        return false;
    }
}

bool Fraction::operator == (const Fraction& fracOne) {
    if (num == fracOne.num&& denom == fracOne.denom) {
        return true;
    } else {
        return false;
    }

}


bool Fraction::operator >= (const Fraction& lesser) {
    if (denom == lesser.denom) {
        if (num >= lesser.num) {
            return false;
        }
        return true;
    } else {
        num = num*lesser.denom;
        if (num >= lesser.num*denom) {
            return true;
        }
        return false;
    }
}

bool operator != (const Fraction& fracOne, const Fraction& fracTwo) {
    if ( fracOne.num != fracTwo.num || fracOne.denom != fracTwo.denom) {
        return true;
    }
    else {
        return false;
    }
}
 


ostream& operator << (ostream& outStream, const Fraction& frac) {
    outStream << frac.numerator() << "/" << frac.denominator();
    return outStream;
}


istream& operator >> (istream& inStream, Fraction& fraction) {
    string input;
    
    int n, d;
    getline(inStream, input);
    string numString;
    string denomString;
    
    bool slash = false;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '/') {
            slash = true;
        }
    }
    
    
    if (slash) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '/') {
                numString.append(input.substr(0,i));
                denomString.append(input.substr(i+1,input.length() - 1));
                fraction.num = atoi(numString.c_str());
                fraction.denom = atoi(denomString.c_str());
            }
        }
    } else {
        fraction.num = atoi(input.c_str());
        fraction.denom = 1;
    }
    return inStream;
}

FractionException::FractionException(const string& message) : message(message) {}

string& FractionException::what() { 
    return message; 
}
