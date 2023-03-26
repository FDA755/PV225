//String_Repeat
#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;   //размер строки
	char* str;	//адресс строки в динамичесой памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//																Constructors:
	explicit String(int size = 80):size(size), str(new char[size]{})
	{
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str) :String(strlen(str) + 1)
	{
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:" << this << endl;
	}
	String(const String& other):String(other.str)
	{;
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this<<endl;
	}
	String(String&& other)noexcept :size(other.size), str(other.str)
	{
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//																Operators:
	char& operator[](int i)
	{
		return str[i];
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyOperator:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;

	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	//																Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

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