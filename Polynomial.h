#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Polynomial
{	
private:
	int maxDegree;
	double* set = NULL;
	static int maxDegreeGen;
public:
	Polynomial();
	Polynomial(int max);
	Polynomial(double c[], int maxDeg);
	Polynomial(const Polynomial& p);
	Polynomial(int deg, int val);// specifically for denom 
	~Polynomial();

	static int getMaxDegree();
	void print()const;
	void setCoeff(const int degree, const double value);
	double getDegree( bool what)const;
	double getCoeff(const int index)const;
	int getActualDegree()const;
	Polynomial &operator=(const Polynomial  &p2);
	Polynomial &operator+(const Polynomial  &p2)const;
	Polynomial &operator-(const Polynomial  &p2)const;
	Polynomial &operator*(const Polynomial  &p2)const;
	Polynomial &operator*(const double d1)const;
	friend Polynomial operator*(const double d1 ,Polynomial& p);
	friend ostream& operator<<(ostream& os, const Polynomial& p);
	const double operator[](const int index)const;
	double &operator[](const int index);


};

