//#include "Error in " Util.relativeFilePath('C:/Users/emmap/OneDrive - Queen's University/Third Year/CMPE320/Assignment3/fraction.h', 'C:/Users/emmap/OneDrive - Queen's University/Third Year/CMPE320/Assignment3' + '/' + Util.path('fraction.cpp'))": SyntaxError: Expected token `)'"
#include "fraction.h"

/*+ Constructors -*/
Fraction::Fraction(){
    num = 0;
    den = 1;
}

Fraction::Fraction(int n){
    num = n;
    den = 1;
}

Fraction::Fraction (int n, int d){
    if (d == 0){
        throw FractionException("Error, denominator cannot be zero");
    }
    else{
        //make fraction as small as possible - use gcd
        int div = gcd(abs(n), abs(d));

        /*+ If Denominator Negative Make Numerator Negative
         * If both negative, this will cancel out the negatives -*/
        if (d<0){

            num = -(n/div);
            den = -(d/div);
        }
        /*+ Both positive or only numerator negative (no change) -*/
        else{
            num = n/div;
            den = d/div;
        }
    }
}


/*+ Function to find Greatest Common Denominator -*/
int Fraction :: gcd (int n, int m){
    if ( (m<=n) && (n%m == 0)){
        return m;
    }
    else if (n<m){
        return gcd(m,n);
    }
    else{
        return gcd(m, n%m);
    }
}

/*+ Accessors -*/

int Fraction :: numerator() const {
    return num;
}

int Fraction :: denominator() const {
    return den;
}


/*+ Unary Operators Overloading -*/

/*+ Negation -*/
Fraction Fraction ::operator -(){
    return Fraction(-num, den);
}

/*+ Pre-Increment -*/
Fraction& Fraction ::operator ++(){
    num += den;
    return *this;
}

/*+ Post-Increment -*/
Fraction Fraction ::operator++(int unused){
    Fraction clone(num, den);
    num += den;
    return clone;
}

/*+ Binary Operators Overloading -*/
/*+ Note - For each operation a temporary fraction is made so that the values are simplified before returned-*/

/*+ Addition -*/
Fraction operator+(const Fraction& lhs, const Fraction& rhs){

    if (lhs.denominator() == rhs.denominator()){

        return ((lhs.numerator()+rhs.numerator()), lhs.denominator());
    }
    else {
        Fraction sum (((lhs.numerator()*rhs.denominator())+(rhs.numerator()*lhs.denominator())), (lhs.denominator()*rhs.denominator()));

        return sum;
    }
}

/*+ Subtraction -*/
Fraction operator-(const Fraction& lhs, const Fraction& rhs){
    if (lhs.denominator() == rhs.denominator()){

            return ((lhs.numerator()-rhs.numerator()), lhs.denominator());
        }
        else {
            Fraction sub (((lhs.numerator()*rhs.denominator())-(rhs.numerator()*lhs.denominator())), (lhs.denominator()*rhs.denominator()));

            return sub;
        }
}

/*+ Multiplication -*/
Fraction operator*(const Fraction& lhs, const Fraction& rhs){
    Fraction mult ((lhs.numerator()*rhs.numerator()), (lhs.denominator()*rhs.denominator()) );
    return mult;
}

/*+ Division -*/
Fraction operator/(const Fraction& lhs, const Fraction& rhs){
    Fraction div ((lhs.numerator()*rhs.denominator()), (lhs.denominator()*rhs.numerator()));
    return div;
}

/*+ Addition and Assignment -*/
Fraction& Fraction::operator+=(const Fraction& rhs){
    Fraction temp = Fraction(num, den)+rhs;
    num = temp.num;
    den=temp.den;
    return *this;
}


/*+ Comparison Operators -*/

// < operator
bool operator<(const Fraction& lhs, const Fraction& rhs){
    if (lhs.denominator() == rhs.denominator()){
        return(lhs.numerator() < rhs.numerator());
    }
    else {
        return ((lhs.numerator() * rhs.denominator())<(rhs.numerator() * lhs.denominator()));
    }
}

// <= operator
bool operator<=(const Fraction& lhs, const Fraction& rhs){
    if (lhs.denominator() == rhs.denominator()){
            return(lhs.numerator() <= rhs.numerator());
        }
        else {
            return ((lhs.numerator() * rhs.denominator())<=(rhs.numerator() * lhs.denominator()));
        }
}

// == operator
bool operator==(const Fraction& lhs, const Fraction& rhs){
    if (lhs.denominator() == rhs.denominator()){
            return(lhs.numerator() == rhs.numerator());
        }
        else {
            return ((lhs.numerator() * rhs.denominator())==(rhs.numerator() * lhs.denominator()));
        }
}

// != operator
bool operator!=(const Fraction& lhs, const Fraction& rhs){
    if (lhs.denominator() == rhs.denominator()){
            return(lhs.numerator() != rhs.numerator());
        }
        else {
            return ((lhs.numerator() * rhs.denominator())!=(rhs.numerator() * lhs.denominator()));
        }
}

//>=
bool operator>=(const Fraction& lhs, const Fraction& rhs){
    if (lhs.denominator() >= rhs.denominator()){
            return(lhs.numerator() >= rhs.numerator());
        }
        else {
            return ((lhs.numerator() * rhs.denominator())>=(rhs.numerator() * lhs.denominator()));
        }
}

//>
bool operator>(const Fraction& lhs, const Fraction& rhs){
    if (lhs.denominator() == rhs.denominator()){
            return(lhs.numerator() > rhs.numerator());
        }
        else {
            return ((lhs.numerator() * rhs.denominator())>(rhs.numerator() * lhs.denominator()));
        }
}

/*+ << (used with cout) -*/
ostream& operator<<(ostream& out, const Fraction& fraction){
    out << fraction.numerator() << "/" << fraction.denominator() << "\n";
    return out;
}

/*+ >> (used with cin) -*/

istream& operator>>(istream& in, Fraction& newFraction){

    in >> newFraction.num;
    char fSlash;
    in >> fSlash;
    if (fSlash == '/'){
        in>> newFraction.den;
    }
    else{
        newFraction.den = 1;
    }
    return in;
}

/*+ Fraction Exception -*/

FractionException::FractionException(const string& msg) : error(msg){}

string FractionException :: what(){
    return error;
}
