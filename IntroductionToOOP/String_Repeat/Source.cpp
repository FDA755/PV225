#include"String.h"
#include<iostream>

#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	String str(5);  str.print();

	String str1 = "Hello";	//"Hello" - строковая константа
	str1 = str1; cout << str1 << endl;

	String str2 = "World";	cout << str2 << endl;

	String str3 = str1 + str2; cout << str3 << endl;

	String str4 = str3; cout << str4 << endl;

	String str5; str5 = str1 + str2; cout << str5 << endl;

	//str1 = str3; cout << str1 << endl;
	//str1 += str2; cout << str1 << endl;  
#endif // BASE_CHECK
#ifdef CALLING_CONSTRUCTORS
	String str1;		    str1.print();	//Default Constructor
	String str2 = "Hello";	str2.print();	//Single Argument constructor
	String str3 = str2;		str3.print();	//Copy Constructor
	String str4();
	String str5{};			str5.print();	//Явный вызов конструктора по умолчанию
	String str6{ 22 };		str6.print();
	String str7{ "World" };	str7.print();
	String str8{ str7 };	str8.print();	//Copy constructor  
#endif // CALLING_CONSTRUCTORS

}