//Fraction.cpp
#include"Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}

//																					Constructors:
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefoultConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	this->integer = decimal;
	decimal -= integer;
	this->denominator = 1e+9;
	this->numerator = decimal * denominator;
	reduce();
	cout << "DoubleDecimalConstructor: " << endl;
}

Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "2ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}
//																					Operators:
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}
Fraction& Fraction::operator++(int)
{
	this->to_improper();
	this->numerator = numerator + 1;
	this->denominator = denominator + 1;
	return this->to_proper().reduce();
}
Fraction& Fraction::operator--(int)
{
	this->to_improper();
	this->numerator = numerator - 1;
	this->denominator = denominator - 1;
	return this->to_proper().reduce();
}
Fraction& Fraction::operator++()
{
	this->to_improper();
	this->numerator = numerator + 1;
	this->denominator = denominator + 1;
	return this->to_proper().reduce();
}
Fraction& Fraction::operator--()
{
	this->to_improper();
	this->numerator = numerator - 1;
	this->denominator = denominator - 1;
	return this->to_proper().reduce();
}
//																					Type-cast operators:
Fraction::operator int()const
{
	return Fraction(*this).to_proper().integer;
}
Fraction::operator double()const
{
	/*double a, b = 0;
	a = Fraction(*this).to_improper().numerator;
	b = Fraction(*this).to_improper().denominator;
	return a / b;*/
	return integer + double(numerator / denominator);
}
Fraction::operator float()const
{
	return 0;
}

//																					Methods:
Fraction& Fraction::to_improper()			//to improper
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
{
	int more, less, rest = 0;
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;

}
std::ostream& Fraction::print(std::ostream& os)const
{
	if (integer)os << integer;
	if (numerator)
	{
		if
			(integer)os << "(";
		os << numerator << "/" << denominator;
		if (integer)os << ")";
	}
	else if (integer == 0)os << 0;
	return os;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();

	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result.to_proper();*/
	return left * right.inverted().reduce();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() + right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() - right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

//																					Comparison operator:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == left.get_denominator() * right.get_numerator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	//left.to_improper();
	//right.to_improper();
	//return !(left.get_numerator() * right.get_denominator() == left.get_denominator() * right.get_numerator());
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > left.get_denominator() * right.get_numerator();
}
bool operator<(const Fraction& left, const Fraction& right)
{
	//left.to_improper();
	//right.to_improper();
	//return left.get_numerator() * right.get_denominator() < left.get_denominator() * right.get_numerator();
	return !(left > right);
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() <= left.get_denominator() * right.get_numerator();
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() >= left.get_denominator() * right.get_numerator();
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return obj.print(os);
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	//int integer, numerator, denominator;
	//is >> integer >> numerator >> denominator;
	//obj(integer, numerator, denominator);
	int number[3] = {};

	const int SIZE = 256;
	char buffer[SIZE] = {};

	char delimiters[] = "/ ()";

	//is >> buffer;
	is.getline(buffer, SIZE);

	int n = 0; //счетчик чисел в веденной строке
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);		//atoi()  - ASCII-string to integer
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
	case 3:obj(number[0], number[1], number[2]);
	}
	return is;
}
