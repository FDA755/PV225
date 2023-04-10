//ForwardList
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

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
	friend class Iterator;
};
 int Element::count = 0; //�������������� ����������� ����������, ����������� � ������ 'Element'

 class Iterator
 {
	 Element* Temp;
 public:
	 Iterator(Element* Temp = nullptr) :Temp(Temp)
	 {
		 cout << "ItConstructor:\t " << this << endl;
	 }
	 ~Iterator()
	 {
		 cout << "ItConstructor:\t " << this << endl;
	 }
	 Iterator& operator++()
	 {
		 Temp = Temp->pNext;
		 return *this;
	 }
	 bool operator==(const Iterator& other)const
	 {
		 return this->Temp == other.Temp;
	 }
	 bool operator!=(const Iterator& other)const
	 {
		 return this->Temp != other.Temp;
	 }
	 int& operator*()
	 {
		 return Temp->Data;
	 }
 };

class Forwardlist //Forward - �����������, ���������������� ������
{
	Element* Head; //������ ������ - �������� ��������� �� ������� ������� ������
	int size;
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	const Iterator begin()const
	{
		return Head;
	}
	const Iterator end()const
	{
		return nullptr;
	}
	Forwardlist()
		{
			Head = nullptr; //���� ������ ����, ��� ������ ��������� �� ����.
			size = 0;
			cout << "LConstructor:\t" << this << endl;
		}
	Forwardlist(const std::initializer_list<int>& il) :Forwardlist()
	{
		// il -���������� initializer_list
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	Forwardlist(const Forwardlist& other)
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		{
			push_back(Temp->Data);
		}
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
		if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);   //1) ������� ����� ������� ������
		Element* Temp = Head;
		while (Temp->pNext)   //2)������� �� ����� ������
			Temp = Temp->pNext;			//������� �� ��������� �������
		//3) ��������� ������� � ����� ������
		Temp->pNext = New;
		//Temp->Data = New->Data;
		//New -> pNext = nullptr;  
		
		//Head = new Element(Data, Head);
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

Forwardlist operator+(const Forwardlist& left, const Forwardlist& right)
{
	Forwardlist cat;
	for (Iterator it = left.begin(); it != left.end(); ++it)cat.push_back(*it);
	for (Iterator it = right.begin(); it != right.end(); ++it)cat.push_back(*it);
	return cat;
}

//#define BASE_CHECK
//#define RANGED_BASE_FOR_FOR_ARRYA
#define HOME_WORK_1
//#define RANGED_BASED_FOR_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
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
	cout << "������� �������� ������������ ��������: "; cin >> value;
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
#endif // BASE_CHECK
#ifdef RANGED_BASE_FOR_FOR_ARRYA
	int arr[] = { 3,5,8,13,21 };
	//for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	//{
	//	cout << arr[i] << tab;
	//}
	//cout << endl;
	for (int i : arr)   //Range-based FOR -			for ��� ��������� (����������)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGED_BASE_FOR_FOR_ARRYA
#ifdef RANGED_BASED_FOR_LIST
	Forwardlist list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;
#endif // RANGED_BASED_FOR_LIST
#ifdef HOME_WORK_1
	Forwardlist list = { 3,5,8,13,21 };
	//list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	Forwardlist list2 = { 33,55,89 };
	for (int i : list2)cout << i << tab; cout << endl;

	Forwardlist list3 = list + list2;
	for (int i : list3)cout << i << tab; cout << endl;
#endif // HOME_WORK_1



}