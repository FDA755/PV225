//String
#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

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
	char* get_str()
	{
		return str;			//возвразает указатель на массив
	}
	//						Constructors:
	explicit String(int size = 80)	//Конструктор по умолчанию
	{
		this->size = size;
		this->str = new char[size] {};								//{} - зануляют выделяемую память в массиве, как в числовом, так и в строковом типе
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)    //Создаем  конструктор с одним параметром чтобы принимал тип 'char'
	{
		this->size = strlen(str)+1;			     //strlen - возвращает размер строки в символах, но в классе хранится размер строки в байтах, т.е с учетом терминирующег нуля (т.е 0 ,это еще +1)
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	
	///						Operators:
	String& operator=(const String& other)								//Assighment Operator =
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
		cout << "CopyAssignmentOp\t" << endl;
		return *this;
	}
	String& operator+=(const String& other)							//Operator +=
	{
		return *this = *this + other;
	}


	char& operator[](int i)                            //без ссылки происходит возврат по значению,происходит копирование и на месте вызова создается временный безымянный объект ,который является константой,
	{													//добавляя &, мы делаем ссылку									
		return str[i];
	}
	const char& operator[](int i)const                        //делаем еще один оператор, для возвращения константной ссылки
	{																					
		return str[i];
	}
	

	String(const String& other)											//DeepCopy Constructor
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
	}
	//						Methods:
	void print()const		//Print
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	//String operator+=(const String& right)										//Для str3 перегружаем оператор +=, который будет возвращать string
	//{
	//	String cat(this->get_size() + right.get_size() - 1);					//После сложения строк убираем один 0 ,записываем минус 1. Т.к каждая строка содержит 0 в конце, и мы оставляем просто один.
	//	for (int i = 0; i < this->get_size(); i++)
	//		//cat.get_str()[i] = left.get_str()[i];
	//		cat[i] = this->get_str()[i];												//Чтобы аписать так сокращенно, нужно перегрузить квадратные скобки [ ]

	//	for (int i = 0; i < right.get_size(); i++)
	//		//cat.get_str()[i+left.get_size()-1] = right.get_str()[i];
	//		cat[i + this->get_size() - 1] = right[i];

	//	return cat;
	//}

};

String operator+(const String& left, const String& right)				//Для str3 перегружаем оператор +, который будет возвращать string
{
	String cat(left.get_size() + right.get_size() -1);					//После сложения строк убираем один 0 ,записываем минус 1. Т.к каждая строка содержит 0 в конце, и мы оставляем просто один.
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];												//Чтобы аписать так сокращенно, нужно перегрузить квадратные скобки [ ]

	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i+left.get_size()-1] = right.get_str()[i];
		cat[i+left.get_size()-1] = right[i];
	
	return cat;
}



std::ostream& operator<<(std::ostream& os, const String& obj)			//Operator cout <<
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
	/*String str1 (5);
	str1.print();*/

	String str1 = "Hello";    //"Hello" - это строковая константа
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;
}