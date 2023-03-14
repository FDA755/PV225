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
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
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
	Fraction()			//Конструктор по умолчанию
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)   //Конструктор с одним параметром
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)   //Конструктор с двемя параметром
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}
	//Fraction(int integer = 0, int numerator = 0, int denominator = 1)   //конструктор с параметрами. =0 и тд он конфликтует с другими конструкторами, т.к может быть выщван при любом создании объекта. Поэтому уберем его исходные значения.
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)      //Конструктор копирования
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
	Fraction& operator=(const Fraction& other)               //Оператор =
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
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
	//				Tyep-cast operators
	explicit operator int()const										//from Fraction to Int
	{
		return Fraction(*this).to_proper().integer;
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
	Fraction inverted()const          //Этот метод возвращает перевернутую дробь
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()					//Алгоритм сокращения дробей (Евклида)
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
		int GCD = more;					//GCD - Greates Common Divisor (Наибольший общий делитель)
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

Fraction operator*(Fraction left, Fraction right)    //Оператор *
{
	left.to_improper();
	right.to_improper();

	//Fraction result			//Default Constructor
	//result.set_numerator(left.get_numerator() * right.get_numerator());       // Пример при использовании set - методов
	//result.set_denominator(left.get_denominator() * right.get_denominator());

	//Fraction result			//Default Constructor
	//(
	//	left.get_numerator() * right.get_numerator(),                           //Пример при использовании Fraction как функции, только на get-методах.
	//	left.get_denominator() * right.get_denominator()
	//);
	//return result;

	//Явно вызываем конструктор и создаем временный безымянный объект который сразу же возвращается на место вызова:
	//То есть не обязательно как выше создавать объект с именем, если посл есразу его уничтожаем.

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();		//приписываем результат умножения к медоду правильной дроби(целая часть, числитель, знаменатель 3(4/5)
}
Fraction operator/(Fraction left, Fraction right)    //Оператор /
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/

	return left * right.inverted().reduce();   //заменяем описанным выше в классе методом 'inverted'
}
Fraction operator+(Fraction left, Fraction right)    //Оператор +
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() + right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator-(Fraction left, Fraction right)    //Оператор -
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() - right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

//////////////////////////////////////////////////////////
//				COMPARISON OPERATORS					//	

bool operator ==(Fraction left, Fraction right)			//Оператор срaвнения ==
{
	left.to_improper();
	right.to_improper();
	return	left.get_numerator() * right.get_denominator() ==
			right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right) //Оператор срaвнения !=
{
	return !(left == right);
}
bool operator >(Fraction left, Fraction right)			//Оператор срaвнения >
{
	left.to_improper();
	right.to_improper();
	return	left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator <(Fraction left, Fraction right)			//Оператор срaвнения <
{
	left.to_improper();
	right.to_improper();
	return	left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right) //Оператор срaвнения >=
{
	//returt left > right || left == right;
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right) //Оператор срaвнения <=
{
	return !(left > right);
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS
//#define TYPE_CONVERSIONS_BASICK
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CCLASS_TO_OTHER
#define HOME_WORK_1
#define HOME_WORK_2

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
#ifdef ARITHMETICAL_OPERATORS_CHECK
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
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef COMPARISON_OPERATORS
	cout << (Fraction(3, 1, 2) <= Fraction(3, 5, 10)) << endl;
#endif // COMPARISON_OPERATORS
#ifdef TYPE_CONVERSIONS_BASICK
	int a = 2;			//No conversions
	double b = 3;		//Conversion from less to more
	int c = b;			//Conversion from more to lesswith no data loss
	int d = 4.5;		//Conversion from more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICK
#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;   //COnversion from other to class by Single-Argument COnstructor
	A.print();

	Fraction B;
	B = Fraction(8);				//Conversion from other to class by Assignment operator
	B.print();
#endif // CONVERSION_FROM_OTHER_TO_CLASS
#ifdef CONVERSION_FROM_CCLASS_TO_OTHER
	Fraction A(11, 4);
	A.print();
	int a = A;
	cout << a << endl;
#endif // CONVERSION_FROM_CCLASS_TO_OTHER
#ifdef HOME_WORK_1    //from Fraction to double
	Fraction B(2, 3, 4);
	double b = (int)B;
	cout << b << endl;
#endif
#ifdef HOME_WORK_2		//from double to fraction
	Fraction B = 2.75;
	cout << B << endl;
#endif


}
