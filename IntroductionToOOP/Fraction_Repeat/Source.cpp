//Fraction repeating
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction 
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//																					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefoultConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		this->integer = decimal;
		decimal -= integer;
		this->denominator = 1e+9;
		this->numerator = decimal * denominator;
		reduce();
		cout << "DoubleDecimalConstructor: " << endl;
	}

	Fraction(int integer)
	{
		this->integer=integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer=0;
		this->numerator=numerator;
		this->set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//																					Operators:
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator++(int)
	{
		this->to_improper();
		this->numerator = numerator + 1;
		this->denominator = denominator + 1;
		return this->to_proper().reduce();
	}
	Fraction& operator--(int)
	{
		this->to_improper();
		this->numerator = numerator - 1;
		this->denominator = denominator - 1;
		return this->to_proper().reduce();
	}
	Fraction& operator++()
	{
		this->to_improper();
		this->numerator = numerator + 1;
		this->denominator = denominator + 1;
		return this->to_proper().reduce();
	}
	Fraction& operator--()
	{
		this->to_improper();
		this->numerator = numerator - 1;
		this->denominator = denominator - 1;
		return this->to_proper().reduce();
	}
	//																					Type-cast operators:
	explicit operator int()const
	{
		return Fraction(*this).to_proper().integer;
	}
	explicit operator double()const
	{
		/*double a, b = 0;
		a = Fraction(*this).to_improper().numerator;
		b = Fraction(*this).to_improper().denominator;
		return a / b;*/
		return integer + double(numerator / denominator);
	}
	explicit operator float()const
	{
	
	}

	//																					Methods:
	Fraction& to_improper()			//to improper
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less,rest  = 0;
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
	std::ostream& print(std::ostream& os)const
	{
		if (integer)os << integer;
		if (numerator)
		{
			if
				(integer)os << "(";
			os << numerator << "/" << denominator;
			if	(integer)os << ")";
		}
		else if (integer == 0)os << 0;
		return os;
	}

};

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
bool operator>( Fraction left,  Fraction right)
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
//#define CONSTRUCTORS_CHECK
//#define CHECK_ARIFMETICAL
//#define COMPARISON_OPERATOR
//#define HOME_WORK_1
//#define HOME_WORK_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; A.print();
	Fraction B = 5; B.print();
	Fraction C(2, 3); C.print();

	Fraction D(2, 3, 4); D.print();
	Fraction E = D; E.print();
#endif // CONSTRUCTORS_CHECK
#ifdef CHECK_ARIFMETICAL
	Fraction A(2, 3, 4); A.print();
	Fraction B(3, 4, 5); B.print();
	//Fraction C = A * B; C.print();
	//Fraction D= A / B; D.print();

	A *= B; A.print();
	A /= B; A.print();
	A += B; A.print();
	A -= B; A.print();
	++A; A.print();
	--A; A.print();
	A++; A.print();
	A--; A.print();
#endif // CHECK_ARIFMETICAL
#ifdef COMPARISON_OPERATOR
	Fraction A(2, 3, 4); A.print();
	Fraction B(3, 4, 5); B.print();
	cout << (A == A) << endl;
	cout << (A != B) << endl;
	cout << (Fraction(1, 2) != Fraction(2, 3)) << endl;
	cout << (Fraction(1, 2) < Fraction(2, 3)) << endl;
	cout << (Fraction(1, 2) > Fraction(2, 3)) << endl;
	cout << (Fraction(3, 2) <= Fraction(3, 1)) << endl;
	cout << (Fraction(3, 2) >= Fraction(3, 1)) << endl;
#endif // COMPARISON_OPERATOR

	/*Fraction A = 5; A.print();
	Fraction B; B = 8; B.print();*/
	/*Fraction A(11, 4); A.print();
	int a = (int)A; cout << a << endl;*/

#ifdef HOME_WORK_1
	Fraction D(2, 3, 4); double b = (double)D;
	cout << b << endl;
#endif // HOME_WORK_1
#ifdef HOME_WORK_2
	Fraction B = 2.65; cout << B << endl;
	
#endif // HOME_WORK_2

	Fraction A;
	cout << "Type simple drob': "; cin >> A; cout << A;

}