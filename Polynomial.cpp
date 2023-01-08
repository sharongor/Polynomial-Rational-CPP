#include "Polynomial.h"


int Polynomial::maxDegreeGen = 0;// general max degree across all polynomials



Polynomial :: Polynomial()
{
	maxDegree = 0;
	this->set = new double[1];
	set[0] = 0;
}
Polynomial :: Polynomial(int max) {
	int i;
	maxDegree = max;
	set = new double[max + 1];
	for (i = 0; i <= max; i++) {
		set[i] = 0;
	}
}
Polynomial :: Polynomial(double c[], int maxDeg)
{
	int flag = 0;
	set = new double[maxDeg + 1];
	for (int i = 0; i <= maxDeg; i++) {
		set[i] = c[i];
		if (c[i] != 0) {
			flag = i;
		}
	}
	maxDegree = maxDeg;
	if (flag > maxDegreeGen) {
		maxDegreeGen = flag;
	}
}

Polynomial :: Polynomial(const Polynomial& p) {
	this->maxDegree = p.maxDegree;
	int deg = p.maxDegree;
	this->set = new double[deg + 1];
	for (int i = 0; i <= deg; i++) {
		this->set[i] = p.set[i];
	}
}

Polynomial :: Polynomial(int deg, int val) {// specifically for denom 
	this->set = new double[2];
	set[0] = val;
	set[1] = 0;
	this->maxDegree = deg;
}

Polynomial :: ~Polynomial() {
	maxDegree = 0;
	set = NULL;
}

int Polynomial::getMaxDegree() {
	return maxDegreeGen;
}

void Polynomial :: print() const {
	int i = 0, flag = this->getActualDegree();

	cout << "polynomial = " << set[0];
	for (i = 1; i <= flag; i++) {
		cout << "+(" << set[i] << ")*X" << '^' << i;
	}
	cout << endl;
}

void Polynomial :: setCoeff(const int degree, const double value) {
	if (degree >= 0 && degree < maxDegree ) {
		set[degree] = value;
	}
}

double Polynomial :: getDegree(bool what)const {
	if (what) {
		int flag = this->getActualDegree();
		return flag;
	}
	else {
		return  maxDegree;
	}
}
double Polynomial :: getCoeff(int index) const{
	if (index < maxDegree) {
		return set[index];
	}
	else {
		return -1234.56; // value given by course staff
	}
}

int Polynomial :: getActualDegree() const{
	int max = this->maxDegree, flag = 0;
	for (int i = 0; i <= maxDegree; i++) {// this function returns the actual degree
		if (set[i] != 0) {
			flag = i;
		}
	}
	return flag;
}

Polynomial &Polynomial :: operator=(const Polynomial& p2) {
	this->maxDegree = p2.maxDegree;

	this->set = new double[maxDegree + 1];
	for (int i = 0; i <= maxDegree; i++) {
		this->set[i] = p2.set[i];
	}
	return *this;
}

Polynomial &Polynomial :: operator+(const Polynomial& p2)const {
	int max, min, flag = 0;
	double* array;

	if (this->maxDegree >= p2.maxDegree) {
		max = this->maxDegree;
		min = p2.maxDegree;
		flag = 1;
	}
	else {
		max = p2.maxDegree;
		min = this->maxDegree;
	}
	array = new double[max + 1];
	for (int i = 0; i <= min;i++) {
		array[i] = this->set[i] + p2.set[i];
	}
	if (flag == 1) {
		for (int i = min + 1 ; i <= max; i++) {
			array[i] = this->set[i];
		}
	}
	else {
		for (int i = min + 1; i <= max; i++) {
			array[i] = p2.set[i];
		}
	}

	Polynomial *tmp = new Polynomial(array, max);

	return *tmp;

}



Polynomial &Polynomial :: operator-(const Polynomial& p2)const {
	int max;
	double* array;
	if (this->maxDegree >= p2.maxDegree) {
		max = this->maxDegree;
	}
	else {
		max = p2.maxDegree;
	}
	array = new double[max + 1];
	for (int i = 0; i <= max;i++) {
		array[i] = this->set[i] - p2.set[i];
	}
	Polynomial *tmp = new Polynomial(array, max);
	return *tmp;

}

Polynomial &Polynomial :: operator*(const Polynomial& p2)const {
	int max1 = this->getActualDegree(), max2 = p2.getActualDegree(), maxTotal = max1 + max2;//actual max degree
	double* array =  new double[maxTotal + 1];
	for (int i = 0; i <= maxTotal; i++) {
		array[i] = 0;
	}

	for (int i = 0; i <= max1;i++) {
		for (int j = 0; j <= max2;j++) {
			array[i+j] += (this->set[i] * p2.set[j]);//adding all possible values to suitable array cells
		}

	}
	Polynomial *tmp = new Polynomial(array, maxTotal);

	return *tmp;

}

Polynomial &Polynomial :: operator*(const double d1)const {
	int max = this->maxDegree;
	double* array = new double[max + 1];
	for (int i = 0; i <= max; i++) {
		array[i] = (this->set[i]) * d1;
	}
	Polynomial *tmp = new Polynomial(array, max);

	return *tmp;
}

Polynomial operator*(const double d1, Polynomial& p) {
	return p * d1;

}

ostream&  operator<<(ostream& os, const Polynomial& p) {
	int i = 0, flag = p.getActualDegree();

	os << "polynomial = " << p.set[0];
	for (i = 1; i <= flag; i++) {
		os << "+(" << p.set[i] << ")*X" << '^' << i;
	}
	os << endl;
	return os;
}

const double Polynomial :: operator[](const int index)const {
	return this->getCoeff(index);
}

double &Polynomial :: operator[](const int index) {
	return this->set[index];
}


