//String_Separation
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

///////////////						ОБЪЯВЛЕНИЕ КЛАССА - Class Declaration				////////////////////////////

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

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