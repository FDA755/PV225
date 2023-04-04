//ForwardList
#include <iostream>
using namespace std;

#define tab "\t"

class Element
{
	static int count;
	int Data;   //������ ��������
	Element* pNext;	//��������� �� ������ ������
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element() 
	{ 
		count--;
		cout << "EDestructor:\t" << this << endl; 
	}
	friend class Forwardlist;
};
 int Element::count = 0; //�������������� ����������� ����������, ����������� � ������ 'Element'

class Forwardlist //Forward - �����������, ���������������� ������
{
	Element* Head; //������ ������ - �������� ��������� �� ������� ������� ������
	int size;
public:
	Forwardlist()
		{
			Head = nullptr; //���� ������ ����, ��� ������ ��������� �� ����.
			size = 0;
			cout << "LConstructor:\t" << this << endl;
		}
	~Forwardlist()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl; 
	}

//																Adding elements:
	void push_front(int Data)
	{
		//1) ������� ����� �������:
		Element* New = new Element(Data);
		//2) ����� ������� ������ ��������� �� ������ ������:
		New->pNext = Head;
		//3) ������ ������ ��������� �� ����� �������:
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		/*if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);   //1) ������� ����� ������� ������
		Element* Temp = Head;
		while (Temp->pNext)   //2)������� �� ����� ������
			Temp = Temp->pNext;			//������� �� ��������� �������
		//3) ��������� ������� � ����� ������
		Temp->pNext = New;
		//Temp->Data = New->Data;
		//New -> pNext = nullptr;  */
		Head = new Element(Data, Head);
		size++;
	}
	void insert(int index, int Data)
	{
		if (index == 0)return push_front(Data);
		if (index > size)return;
		//1)������� ����� �������:
		Element* New = new Element(Data);
	    //2)������� �� ������� ��������:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext; 
		//3)��������� ����� ������� � ������:
		/*New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data,Temp->pNext);
		size++;
	}
	void erase(int index)
	{
		
		size--;
	}

	//															Erasing Elements
	void pop_front()
	{
		Element* Erased = Head;		//1) ���������� ������ ���������� ��������
		Head = Head->pNext;			//2) ��������� ������� �� ������
		delete Erased;				//3) ������� ������ �������
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext) Temp = Temp -> pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	//															Methods:
	void print()const
	{
		/*Element* Temp = Head;    //Temp - ��� ��������. ��� �����������, ��� ������ ������� ����� �������� ������ � ��������� ��������� ������
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;			//������� �� ��������� �������
		} */
		for(Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "���������� ��������� ������: " << size << endl;
		cout << "����� ���������� ��������� ������: " << Element::count << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������: "; cin >> n;
	Forwardlist list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();

	//list.push_back(123);
	list.pop_front();
	list.pop_back();

	int value;
	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >>value;
	list.insert(index, value);
	list.print();

	Forwardlist list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.print();

	/*int value;
	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list.erase(index);
	list.print();*/


}