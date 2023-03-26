//String_Separation
#include<iostream>
using namespace std;
using std::cin; 
using std::cout;
using std::endl;

///////////////						ОБЪЯВЛЕНИЕ КЛАССА - Class Declaration				////////////////////////////

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;   //размер строки
	char* str;	//адресс строки в динамичесой памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//																Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other)noexcept;
	~String();
	//																Operators:
	char& operator[](int i);
	const char& operator[](int i)const;
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	//																Methods:
	void print()const;
};

///////////////					Конец	ОБЪЯВЛЕНИЕ КЛАССА - Class Declaration End               ///////////////////////


///////////////							ОПРЕДЕЛЕНИЕ КЛАССА - Class Definition					///////////////////////
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//																Constructors:
explicit String::String(int size = 80) :size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "1ArgConstructor:" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)noexcept :size(other.size), str(other.str)
{
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete this->str;
	cout << "Destructor:\t" << this << endl;
}
//																Operators:

String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyOperator:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char& String::operator[](int i)
{
	return str[i];
}
const char& String::operator[](int i)const
{
	return str[i];
}
//																Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat (left.get_size() + right.get_size() -1);
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	for (int i =0; i < right.get_size(); i++)
		//cat.get_str()[i+ left.get_size()-1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
///////////////					КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА - Class Definition End			///////////////////////

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