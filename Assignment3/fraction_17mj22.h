/*
 * fraction_17mj22.h
 *
 *  Created on: Oct 14, 2020
 *      Author: Melanie Jones
 *      Net ID: 17mj22
 *      Student #: 20090489
 */

#ifndef FRACTION_17MJ22_H_
#define FRACTION_17MJ22_H_

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Fraction{
public:

	/*+ Constructors -*/

	Fraction ();
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
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs); //multiplication
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

/*+ Fraction Exception -*/

class FractionException :public std::exception{
public:
	FractionException(const string& error);
	string what();
private:
	string error;
};


#endif /* FRACTION_17MJ22_H_ */
