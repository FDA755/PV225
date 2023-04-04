//ForwardList
#include <iostream>
using namespace std;

#define tab "\t"

class Element
{
	static int count;
	int Data;   //данные элемента
	Element* pNext;	//указатель на элмент списка
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
 int Element::count = 0; //Инициализируем статическую переменную, объявленную в классе 'Element'

class Forwardlist //Forward - односвязный, однонаправленный список
{
	Element* Head; //Голова списка - содержит указатель на нулевой элемент списка
	int size;
public:
	Forwardlist()
		{
			Head = nullptr; //Если список пуст, его голова указывает на ноль.
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
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Новый элемент должен указывать на начало списка:
		New->pNext = Head;
		//3) Голову списка переводим на новый элемент:
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		/*if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);   //1) Создаем новый элемент списка
		Element* Temp = Head;
		while (Temp->pNext)   //2)Доходим до конца списка
			Temp = Temp->pNext;			//Переход на следующий элемент
		//3) добавляем элемент в конец списка
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
		//1)Создаем новый элемент:
		Element* New = new Element(Data);
	    //2)Доходим до нужного элемента:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext; 
		//3)Вставляем новый элемент в список:
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
		Element* Erased = Head;		//1) Запоминаем адресс удаляемого элемента
		Head = Head->pNext;			//2) Исключаем элемент из списка
		delete Erased;				//3) Удаляем первый элемент
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
		/*Element* Temp = Head;    //Temp - эот итератор. Это указательль, при помози котороо можно получить доступ к элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;			//Переход на следующий элемент
		} */
		for(Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов списка: " << size << endl;
		cout << "Обзее количество элементов списка: " << Element::count << endl;
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

	//list.push_back(123);
	list.pop_front();
	list.pop_back();

	int value;
	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >>value;
	list.insert(index, value);
	list.print();

	Forwardlist list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.print();

	/*int value;
	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.erase(index);
	list.print();*/


}