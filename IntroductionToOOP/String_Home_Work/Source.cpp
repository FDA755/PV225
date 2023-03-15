//String Home Work
#include<iostream>
using namespace std;

class String
{
	int size;				//Размер строки
	char* str;				//адресс строки в динамической памяти    //т.к массив динамический, мы задаем указатель на char
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	//						Constructors:
	explicit String(int size = 80)	//Конструктор по умолчанию
	{
		this->size = size;
		this->str = new char[size] {'z','z'};								//{} - зануляют выделяемую память в массиве, как в числовом, так и в строковом типе
		cout << "DefConstructor:\t" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//						Methods:
	void print()const		//Print
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");
	String str1(5);
	str1.print();

}