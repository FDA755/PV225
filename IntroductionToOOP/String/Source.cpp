//String
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
	explicit String(int size = 80) :size(size), str(new char[size] {})  //Конструктор по умолчанию
	{
		//this->size = size;
		//this->str = new char[size] {};								//{} - зануляют выделяемую память в массиве, как в числовом, так и в строковом типе
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str):size (strlen(str) + 1),str(new char[size] {})  //Создаем  конструктор с одним параметром чтобы принимал тип 'char'
	{
		//this->size = strlen(str)+1;			     //strlen - возвращает размер строки в символах, но в классе хранится размер строки в байтах, т.е с учетом терминирующег нуля (т.е 0 ,это еще +1)
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const String& other) :size(other.size), str(new char[size] {})									//DeepCopy Constructor
	{
		//this->size = other.size;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
	}
	String(String&& other)noexcept :size(other.size), str(other.str)		//R-value refference			//Shallow copy - поверхностное копирование
	{
		//this->size = other.size;
		//this->str = other.str;			//Shallow copy
		other. size = 0;
		other.str = nullptr;			//nullptr - указательна ноль
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	
	///						Operators:
	String& operator=(const String& other)								//Assighment Operator =
	{
		//           l-value = r-value
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
		cout << "CopyAssignmentOp:\t" << endl;
		return *this;
	}
	String& operator=(String&& other)noexcept
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
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

#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	String str (5);
	str.print();

	String str1 = "Hello";    //"Hello" - это строковая константа
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3;
	str3 = str1 + str2;

	String str4 = str3;			//Copy constructor - потому ,что копируется сузествуюзий объект
	str4.print();

	String str5;
	str5 = str1 + str2;
	cout << str5 << endl;
#endif // BASE_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;			//Default constructor
	str1.print();
	String str2 = "Hello";	//Single Argument Constructor
	str2.print();
	String str3 = str2;		//CopyConstructor
	str3.print();
	String str4();			//Default constructor - На самом деле здесь не вызывается никакой конструктор, потому что здесь не создается объект.
	//Здесь создается функция str4(), которая не принимает ниаких параметров и возвразает значение типа String
	//str4().print();         //- это не объект, это функция, а для фенкции нельзя вызвать метод.
	String str5{ "Hello" };
	str5.print();
	String str6{ 22 };
	str6.print();
	String str7{ "World" };
	str7.print();
	String str8{ str7 };
	str8.print();
#endif // CALLING_CONSTRUCTORS



}