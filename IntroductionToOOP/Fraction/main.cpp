//Fraction
#include<iostream>
using namespace std;
#define delimiter "\n----------------------------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;		//����� �����
	int numerator;		//���������
	int denominator;	//�����������
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
		else this->denominator = denominator;
	}
	//				Constructors:
	Fraction()			//����������� �� ���������
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)   //����������� � ����� ����������
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)   //����������� � ����� ����������
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}
	//Fraction(int integer = 0, int numerator = 0, int denominator = 1)   //����������� � �����������. =0 � �� �� ����������� � ������� ��������������, �.� ����� ���� ������ ��� ����� �������� �������. ������� ������ ��� �������� ��������.
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)      //����������� �����������
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//				Operators:
	Fraction& operator=(const Fraction& other)               //�������� =
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)				//Operator *=
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)				//Operator /=
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)				//Operator +=
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)				//Operator -=
	{
		return *this = *this - other;
	}
	//				Methods:
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
	Fraction inverted()const          //���� ����� ���������� ������������ �����
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()					//�������� ���������� ������ (�������)
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
		int GCD = more;					//GCD - Greates Common Divisor (���������� ����� ��������)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const					//Print
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)    //�������� *
{
	left.to_improper();
	right.to_improper();

	//Fraction result			//Default Constructor
	//result.set_numerator(left.get_numerator() * right.get_numerator());       // ������ ��� ������������� set - �������
	//result.set_denominator(left.get_denominator() * right.get_denominator());

	//Fraction result			//Default Constructor
	//(
	//	left.get_numerator() * right.get_numerator(),                           //������ ��� ������������� Fraction ��� �������, ������ �� get-�������.
	//	left.get_denominator() * right.get_denominator()
	//);
	//return result;

	//���� �������� ����������� � ������� ��������� ���������� ������ ������� ����� �� ������������ �� ����� ������:
	//�� ���� �� ����������� ��� ���� ��������� ������ � ������, ���� ���� ������ ��� ����������.

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();		//����������� ��������� ��������� � ������ ���������� �����(����� �����, ���������, ����������� 3(4/5)
}
Fraction operator/(Fraction left, Fraction right)    //�������� /
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/

	return left * right.inverted().reduce();   //�������� ��������� ���� � ������ ������� 'inverted'
}
Fraction operator+(Fraction left, Fraction right)    //�������� +
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() + right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator-(Fraction left, Fraction right)    //�������� -
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() - right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK
	Fraction A(2, 3, 4); A.print();

	Fraction B(3, 4, 5); B.print();

	Fraction C = A * B; C.print();

	Fraction D = A / B; D.print();

	C = A + B; C.print();

	C = A - B; C.print();

	A *= B; A.print();

	A /= B; A.print();

	A += B; A.print();

	A -= B; A.print();

	Fraction E(3, 4, 5); E.to_improper().print();

}
