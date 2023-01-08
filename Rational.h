#pragma once
#include "Polynomial.h"

using namespace std;

class Rational : public Polynomial
{
private:
	Polynomial  nom;
	Polynomial  denom;

public:
	Rational();
	Rational(const Polynomial& p1, const Polynomial& p2);
	// destructor for this class is the default and uses the Polynomial destructor 
	Polynomial&  getNom();
	Polynomial& getDenom();
	void print()const;

	Rational &operator=(const Rational& p2);
	Rational &operator+(const Rational& p2)const;
	Rational &operator-(const Rational& p2)const;
	Rational &operator*(const Rational& p2)const;
	Rational &operator*(const double d1)const;
	friend Rational& operator*(const double d1, const Rational& p2);
	friend ostream& operator<<(ostream& os, const Rational& p);


};

