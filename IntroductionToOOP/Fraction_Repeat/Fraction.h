#pragma once
//Fraction.h
//Fraction repeating
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//																					Constructors:
	Fraction();
	Fraction(double decimal);

	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(const Fraction& other);
	Fraction(int integer, int numerator, int denominator);
	~Fraction();
	//																					Operators:
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator++(int);
	Fraction& operator--(int);
	Fraction& operator++();
	Fraction& operator--();
	//																					Type-cast operators:
	explicit operator int()const;
	explicit operator double()const;
	explicit operator float()const;

	//																					Methods:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	std::ostream& print(std::ostream& os)const;
};