//Fraction
#include<iostream>
using namespace std;
#define delimiter "\n----------------------------------------------------------\n"

class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denomenator;	//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denomenator()const
	{
		return denomenator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denomenator(int denomenator)
	{
		if (denomenator == 0) denomenator = 1;
		else this->denomenator = denomenator;
	}
};

void main()
{
	setlocale(LC_ALL, "");

}