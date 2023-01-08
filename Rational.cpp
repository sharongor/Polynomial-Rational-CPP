#include "Rational.h"


Rational :: Rational() : nom(1), denom(1, 1) {};//initialization list

Rational :: Rational (const Polynomial& p1, const Polynomial& p2) {
	nom = p1;
	denom = p2;
}

Polynomial& Rational :: getNom() {
	return nom;
}
Polynomial& Rational :: getDenom() {
	return denom;
}
void Rational :: print() const{
	//cout << this << endl;
	nom.print();
	cout << "--------------------------" << endl;
	denom.print();
}

Rational &Rational :: operator=(const Rational& p2) {
	this->nom = p2.nom;
	this->denom = p2.denom;
	return *this;
}

Rational &Rational :: operator+(const Rational& p2)const {
	Rational *tmp = new Rational(this->nom * p2.denom  + this->denom * p2.nom, this->denom * p2.denom );

	return *tmp;
}


Rational &Rational :: operator-(const Rational& p2) const{
	Rational *tmp = new Rational(this->nom * p2.denom - this->denom * p2.nom, this->denom * p2.denom);
	return *tmp;
}


Rational &Rational :: operator*(const Rational& p2)const {
	Rational * tmp = new Rational(this->nom * p2.nom, this->denom * p2.denom);

	return *tmp;
}


Rational &Rational :: operator*(const double d1)const {
	Rational* tmp = new Rational(this->nom * d1, this->denom * d1);

	return *tmp;
}

Rational& operator*(const double d1, const Rational& p2) {
	return p2 * d1;
}


ostream& operator<<(ostream& os, const Rational& p) {

	os << "numerator=" << p.nom ;
	os << "--------------------------" << endl;
	os << "denominator=" << p.denom ;
	return os;
}
