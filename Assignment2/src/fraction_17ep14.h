#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Fraction {
    
    public:
        // Constructors 
        Fraction();
        Fraction(int numer);
        Fraction(int numer, int denomin);

        // Accesors
        int numerator() const {return num; }  
        int denominator() const {return denom; }

        // Modifiers
        void setnum(int num);
        void setdenom(int denom);

        Fraction operator - (void) const;
        Fraction operator ++();
        Fraction operator ++(int);
        Fraction operator += (const Fraction&);

        friend Fraction operator + (const Fraction&, const Fraction&);
        friend Fraction operator - (const Fraction&, const Fraction&);
        friend Fraction operator * (const Fraction&, const Fraction&);
        friend Fraction operator / (const Fraction&, const Fraction&);
       
        friend bool operator > (const Fraction&, const Fraction&);
        friend bool operator < (const Fraction&, const Fraction&);
        
        bool operator <= (const Fraction&);
        bool operator == (const Fraction&);
        bool operator >= (const Fraction&);
       

        friend bool operator != (const Fraction&, const Fraction&);
        friend istream& operator >> (istream&, Fraction&);
        friend ostream& operator << (ostream&, const Fraction&);
        
    //private:
        int num;
        int denom;

};

class FractionException {
public:
    FractionException(const string& message);
    string& what(void);
private:
    string message;
};

int greatestCommonDivisor(int x, int y) {
int z=x%y;
 if(z==0)
 return(y);
 else
 return(greatestCommonDivisor(y,z));
}
