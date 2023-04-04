//ForwardList
#include <iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;   //данные элемента
	Element* pNext;	//указатель на элмент списка
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element() { cout << "EDestructor:\t" << this << endl; }
	friend class Forwardlist;
};

class Forwardlist //Forward - односвязный, однонаправленный список
{
	Element* Head; //Голова списка - содержит указатель на нулевой элемент списка
public:
	Forwardlist()
		{
			Head = nullptr; //Если список пуст, его голова указывает на ноль.
			cout << "LConstructor:\t" << this << endl;
		}
	~Forwardlist(){ cout << "LDestructor:\t" << this << endl; }

//																Adding elements:
	void push_front(int Data)
	{
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Новый элемент должен указывать на начало списка:
		New->pNext = Head;
		//3) Голову списка переводим на новый элемент:
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);   //1) Создаем новый элемент списка
		Element* Temp = Head;
		while (Temp->pNext)   //2)Доходим до конца списка
			Temp = Temp->pNext;			//Переход на следующий элемент
		//3) добавляем элемент в конец списка
		Temp->pNext = New;
		//Temp->Data = New->Data;
		//New -> pNext = nullptr;
	}

	//															Methods:
	void print()const
	{
		Element* Temp = Head;    //Temp - эот итератор. Это указательль, при помози котороо можно получить доступ к элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;			//Переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	Forwardlist list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();

	/*list.push_back(123);
	list.print();*/

}