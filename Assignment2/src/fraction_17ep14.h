#include <fstream>
#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Fraction {
    
    public:
        // Constructors 
        Fraction();
        Fraction(int num);
        Fraction(int num, int denom);

        // Accesors
        int getNumerator();  // Add const at the end???
        int getDenominator();  //" "

        // Modifiers
        void setNumerator(int num);
        void setDenominator(int denom);

        Fraction operator - (void) const;
        Fraction operator ++();
        Fraction operator ++(int);
        Fraction operator += (const Fraction&);

        friend Fraction operator + (const Fraction&, const Fraction&);
        friend Fraction operator - (const Fraction&, const Fraction&);
        friend Fraction operator * (const Fraction&, const Fraction&);
        friend Fraction operator / (const Fraction&, const Fraction&);

        friend Fraction operator < (const Fraction&, const Fraction&);
        bool operator <= (const Fraction&);
        bool operator == (const Fraction&);
        bool operator != (const Fraction&);
        bool operator >= (const Fraction&);
        bool operator > (const Fraction&);
        
        friend istream& operator >> (istream&, Fraction&);
        friend ostream& operator << (ostream&, const Fraction&);

    private:
        int numerator;
        int denominator;

};

int greatestCommonDivisor(int x, int y) {
int z=x%y;
 if(z==0)
 return(y);
 else
 return(greatestCommonDivisor(y,z));
}
