#include<iostream>
using namespace std;

//#define SimpleCode_46	//Указатели c++ что это. Для чего нужны. Указатели c++ разыменование. 
//#define SimpleCode_47 //Арифметика указателей. Указатели и массивы. 
//#define SimpleCode_48	//Передача аргументов по указателю. Как вернуть два и более значения из функции.
//#define SimpleCode_49	//Возврат нескольких значений функции через указатели. Функция возвращает несколько значений. 
//#define SimpleCode_50	//++ ссылки что это. c++ ссылки и указатели разница. Указатель на ссылку.
//#define SimpleCode_51	//Передача параметров в функцию по ссылке. Разница между ссылкой и указателем.
#define SimpleCode_52	//Возврат нескольких значений функции через ссылки. Как вернуть несколько значений функции.

#ifdef SimpleCode_46
void main()
{
	setlocale(LC_ALL, "");

	int a = 5;
	cout << "a:\t " << a << endl;

	int b = a;
	//тип данных указателя должен соответствовать типу данных на который он указывает ,т.е double *px =&a ,где a(int) не будет работать.
	int* px = &a;       //& - оператор взятия адреса, *px - указатель на адрес.

	cout << *px << endl;//тут уже * -является оператором разыменования, и возвращает именно значение 'а'
	cout << px << endl;
	cout << &a << endl;

	int* px2 = &a;
	cout << "px:\t " << px << endl;
	cout << "px2:\t " << px2 << endl;

	*px2 = 2;			//тут мы разыменовываем указатель, и записываем в область памяти 'a' другое значение.
	cout << "a:\t " << a << endl;
	cout << "px:\t " << *px << endl;
}
#endif // SimpleCode_46

#ifdef SimpleCode_47
void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 5;
	int arr[SIZE]{ 4,3,2,1,0 };				//arr - имя массива на самом деле является указателем на первый элемент массива.
	for (int i = 0; i < SIZE; i++)			//массив - неприрывная область памяти для его элементов
	{
		cout << arr[i] << endl;
	}
	cout << "=====================================" << endl;

	int *pArr = arr;						//

	cout << "arr:\t"<<arr << endl;
	cout << "pArr:\t"<<pArr << endl;

	cout << "=====================================" << endl;

	for (int i = 0; i < SIZE; i++)			//массив - неприрывная область памяти для его элементов
	{
		cout << pArr[i] << endl;
	}
	cout << "=====================================" << endl;
	for (int i = 0; i < SIZE; i++)			//массив - неприрывная область памяти для его элементов
	{
		cout << *(pArr+i) << endl;			//эта строка идентична cout << pArr[i] << endl;
	}

	cout << "=====================================" << endl;
	cout << *(pArr + 10) << endl;			//вывод первого (второго по счету) элемента массива;
	cout << "=====================================" << endl;
	for (int i = 0; i < SIZE; i++)			//массив - неприрывная область памяти для его элементов
	{
		cout << (pArr + i) << endl;			//вывод списка адресов эдементов массива
	}
}
#endif // SimpleCode_47

#ifdef SimpleCode_48


void Foo(int* pa)			//1. *pa - указатель на ссылку
{
	(*pa)++;					//2. *pa - оператор разыменования, для получения и изминения значения в 'a'. 
}								// () - скобки для указания приоритета операторов. Сначала *pa - заыменовываем, после pa++ - прибавляем.

void main()
{
	int a = 0;

	cout << a << endl;

	Foo(&a);				//3. &a - ссылка на указатель адреса переменной 'a'

	cout << a << endl;
}



#endif // SimpleCode_48

#ifdef SimpleCode_49


void Foo(int* pa, int* pb, int* pc, int *pd, int *pe)			//1. *pa - указатель на ссылку
{
	(*pa)++;					//2. *pa - оператор разыменования, для получения и изминения значения в 'a'. 
	(*pb) = 555;					// () - скобки для указания приоритета операторов. Сначала *pa - заыменовываем, после pa++ - прибавляем.
	(*pc) = -20;

	int buffer = (*pd);
	*pd = *pe;
	*pe = buffer;
}

void main()
{
	int a = 0; int b = 0; int c = 1; int d = 777; int e = 111;

	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
	cout << " c = " << c << endl;
	cout << " d = " << d << endl;
	cout << " e = " << e << endl;

	cout << "Foo" << endl;
	Foo(&a, &b, &c, &d, &e);				//3. &a - ссылка на указатель адреса переменной 'a'

	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
	cout << " c = " << c << endl;
	cout << " d = " << d << endl;
	cout << " e = " << e << endl;

}






#endif // SimpleCode_49

#ifdef SimpleCode_50
void main()
{
	int a = 5;
	int *pa = &a;
	int &aRef = a;				//Помещение адреса 'a' в ссылку aRef

	cout << "*pa\t" << pa << endl;
	cout << "&aref\t" << aRef << endl;		//Тут мы получаем не адресс в консоль, а именно значение. Отличие ссылки от указателя - ссылке не требуется оператор разыменования.

	cout << "==============================" << endl;
	int b = 7;
	int	*pb = &b;
	int  &bRef = b;
	int d = 5;
	int* pd = &d;

	cout << "*pb\t" << pb << endl;
	pb++;									//тут пример арифметики указателей. адрес указателя сдвинут на величину элемента b (int = 4 byte).
	cout << "*pb++\t" << pb << endl;

	cout << "&bref\t" << bRef << endl;
	bRef++;									//Арифметика указателей отсутствует для ссылок. Действия идут со значениями.
	cout << "&bref++\t" << bRef << endl;
	cout << "b =\t" << b << endl;

	cout << "==============================" << endl;
	//int *pp= NULL;
	//int &pRef=NULL;	//Отличие указателя от ссылки, ссылка должна быть проинициализированна.
	cout << "d =\t" << d << endl;		
	int	&dRef = *pd;		//Ниже описан пример помещения указателя в ссылку, т.е еще раз переложиои после первого полещения ссылки в указатель.
	int *pdd = &dRef;
	 *pdd = 999;
	cout << "d =\t" << d << endl;
}

#endif // SimpleCode_50

#ifdef SimpleCode_51

void Foo1(int a)					//Функция принимает значение по значению
{
	a = 1;
}
void Foo2(int &a)				//Функция принимает значение по ссылке  //Ссылочный тип не нуждается в разыменовании, сразу работаем со значением.
{
	a = 2;
}
void Foo3(int *a)				//Функция принимает значение по указателю //1. *a принимаем указатель на ссылку. 2. *a =3 -разыменовыванм указатель для доступа к значению и после меняем значение.
{
	*a = 3;
}

void main()
{
	int value = 5;
	cout<< "value :\t" << value << endl;
	cout << "Foo1 :\t" <<  endl;
	Foo1(value);
	cout << "Foo1 :\t" << value << endl;

	cout << "Foo2 :\t" << endl;
	Foo2(value);
	cout << "Foo2 :\t" << value << endl;

	cout << "Foo3 :\t" << endl;
	Foo3(&value);
	cout << "Foo3 :\t" << value << endl;

}

#endif // SimpleCode_51

#ifdef SimpleCode_52

template<typename T> T Foo(int& a, int& b, int& c, T &d, T &e)
{
	a = 10;
	b *= 2;
	c -= 100;
	T buffer = d;
	d = e;
	e = buffer;
	return a,b,c,d,e;
}
void main()
{
	int a = 0, b = 4, c = 34;
	float d = 777.5, e = 111.1;
	cout << "a =\t" << a << endl;
	cout << "b =\t" << b << endl;
	cout << "c =\t" << c << endl;
	cout << "d =\t" << d << endl;
	cout << "e =\t" << e << endl;
	cout << "================================" << endl;
	Foo(a, b, c,d ,e);
	cout << "a =\t" << a << endl;
	cout << "b =\t" << b << endl;
	cout << "c =\t" << c << endl;
	cout << "d =\t" << d << endl;
	cout << "e =\t" << e << endl;


}

#endif // SimpleCode_52
