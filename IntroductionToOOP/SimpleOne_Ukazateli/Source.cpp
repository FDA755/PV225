#include<iostream>
using namespace std;

//#define SimpleCode_46	//��������� c++ ��� ���. ��� ���� �����. ��������� c++ �������������. 
//#define SimpleCode_47 //���������� ����������. ��������� � �������. 
//#define SimpleCode_48	//�������� ���������� �� ���������. ��� ������� ��� � ����� �������� �� �������.
//#define SimpleCode_49	//������� ���������� �������� ������� ����� ���������. ������� ���������� ��������� ��������. 
//#define SimpleCode_50	//++ ������ ��� ���. c++ ������ � ��������� �������. ��������� �� ������.
//#define SimpleCode_51	//�������� ���������� � ������� �� ������. ������� ����� ������� � ����������.
#define SimpleCode_52	//������� ���������� �������� ������� ����� ������. ��� ������� ��������� �������� �������.

#ifdef SimpleCode_46
void main()
{
	setlocale(LC_ALL, "");

	int a = 5;
	cout << "a:\t " << a << endl;

	int b = a;
	//��� ������ ��������� ������ ��������������� ���� ������ �� ������� �� ��������� ,�.� double *px =&a ,��� a(int) �� ����� ��������.
	int* px = &a;       //& - �������� ������ ������, *px - ��������� �� �����.

	cout << *px << endl;//��� ��� * -�������� ���������� �������������, � ���������� ������ �������� '�'
	cout << px << endl;
	cout << &a << endl;

	int* px2 = &a;
	cout << "px:\t " << px << endl;
	cout << "px2:\t " << px2 << endl;

	*px2 = 2;			//��� �� �������������� ���������, � ���������� � ������� ������ 'a' ������ ��������.
	cout << "a:\t " << a << endl;
	cout << "px:\t " << *px << endl;
}
#endif // SimpleCode_46

#ifdef SimpleCode_47
void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 5;
	int arr[SIZE]{ 4,3,2,1,0 };				//arr - ��� ������� �� ����� ���� �������� ���������� �� ������ ������� �������.
	for (int i = 0; i < SIZE; i++)			//������ - ����������� ������� ������ ��� ��� ���������
	{
		cout << arr[i] << endl;
	}
	cout << "=====================================" << endl;

	int *pArr = arr;						//

	cout << "arr:\t"<<arr << endl;
	cout << "pArr:\t"<<pArr << endl;

	cout << "=====================================" << endl;

	for (int i = 0; i < SIZE; i++)			//������ - ����������� ������� ������ ��� ��� ���������
	{
		cout << pArr[i] << endl;
	}
	cout << "=====================================" << endl;
	for (int i = 0; i < SIZE; i++)			//������ - ����������� ������� ������ ��� ��� ���������
	{
		cout << *(pArr+i) << endl;			//��� ������ ��������� cout << pArr[i] << endl;
	}

	cout << "=====================================" << endl;
	cout << *(pArr + 10) << endl;			//����� ������� (������� �� �����) �������� �������;
	cout << "=====================================" << endl;
	for (int i = 0; i < SIZE; i++)			//������ - ����������� ������� ������ ��� ��� ���������
	{
		cout << (pArr + i) << endl;			//����� ������ ������� ��������� �������
	}
}
#endif // SimpleCode_47

#ifdef SimpleCode_48


void Foo(int* pa)			//1. *pa - ��������� �� ������
{
	(*pa)++;					//2. *pa - �������� �������������, ��� ��������� � ��������� �������� � 'a'. 
}								// () - ������ ��� �������� ���������� ����������. ������� *pa - �������������, ����� pa++ - ����������.

void main()
{
	int a = 0;

	cout << a << endl;

	Foo(&a);				//3. &a - ������ �� ��������� ������ ���������� 'a'

	cout << a << endl;
}



#endif // SimpleCode_48

#ifdef SimpleCode_49


void Foo(int* pa, int* pb, int* pc, int *pd, int *pe)			//1. *pa - ��������� �� ������
{
	(*pa)++;					//2. *pa - �������� �������������, ��� ��������� � ��������� �������� � 'a'. 
	(*pb) = 555;					// () - ������ ��� �������� ���������� ����������. ������� *pa - �������������, ����� pa++ - ����������.
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
	Foo(&a, &b, &c, &d, &e);				//3. &a - ������ �� ��������� ������ ���������� 'a'

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
	int &aRef = a;				//��������� ������ 'a' � ������ aRef

	cout << "*pa\t" << pa << endl;
	cout << "&aref\t" << aRef << endl;		//��� �� �������� �� ������ � �������, � ������ ��������. ������� ������ �� ��������� - ������ �� ��������� �������� �������������.

	cout << "==============================" << endl;
	int b = 7;
	int	*pb = &b;
	int  &bRef = b;
	int d = 5;
	int* pd = &d;

	cout << "*pb\t" << pb << endl;
	pb++;									//��� ������ ���������� ����������. ����� ��������� ������� �� �������� �������� b (int = 4 byte).
	cout << "*pb++\t" << pb << endl;

	cout << "&bref\t" << bRef << endl;
	bRef++;									//���������� ���������� ����������� ��� ������. �������� ���� �� ����������.
	cout << "&bref++\t" << bRef << endl;
	cout << "b =\t" << b << endl;

	cout << "==============================" << endl;
	//int *pp= NULL;
	//int &pRef=NULL;	//������� ��������� �� ������, ������ ������ ���� ��������������������.
	cout << "d =\t" << d << endl;		
	int	&dRef = *pd;		//���� ������ ������ ��������� ��������� � ������, �.� ��� ��� ���������� ����� ������� ��������� ������ � ���������.
	int *pdd = &dRef;
	 *pdd = 999;
	cout << "d =\t" << d << endl;
}

#endif // SimpleCode_50

#ifdef SimpleCode_51

void Foo1(int a)					//������� ��������� �������� �� ��������
{
	a = 1;
}
void Foo2(int &a)				//������� ��������� �������� �� ������  //��������� ��� �� ��������� � �������������, ����� �������� �� ���������.
{
	a = 2;
}
void Foo3(int *a)				//������� ��������� �������� �� ��������� //1. *a ��������� ��������� �� ������. 2. *a =3 -�������������� ��������� ��� ������� � �������� � ����� ������ ��������.
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
