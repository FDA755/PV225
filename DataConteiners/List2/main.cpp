#include<iostream>
using namespace std;

#define tab "\t"
class List
{

	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head, * Tail;
	unsigned int size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ItDestructor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		bool operator ==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator !=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
	};
	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "RItConstructor:\t" << this << endl;
		}
		~ReverseIterator()
		{
			cout << "RItConstructor:\t" << this << endl;
		}
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const ReverseIterator& other)
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}

	};
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ReverseIterator rbegin()
	{
		return Tail;
	}
	ReverseIterator rend()
	{
		return nullptr;
	}
	 Iterator begin()const
	{
		return Head;
	}
	 Iterator end()const
	{
		return nullptr;
	}
	 ReverseIterator rbegin()const
	{
		return Tail;
	}
	 ReverseIterator rend()const
	{
		return nullptr;
	}
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
		{
			push_back(*it);
		}
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "LDestructor:\t" << this << endl;
	}

	//						Adding Elements:
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		//Element* New = new Element(Data);	//1) ������� �������
		//New->pNext = Head;					//
		//Head->pPrev = New;					//	
		//Head = New;							//4)
		//size++;
		//Element* New = new Element(Data,Head);	//1) ������� �������
		//New->pNext = Head;					//
		Head = Head->pPrev = new Element(Data, Head);					//	
		//New;							//4)
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		//Element* New = new Element(Data);	//1) ������� �������
		//New->pNext = nullptr;	
		//New->pPrev = Tail;//
		//Tail->pNext = New;					//	
		//Tail = New;							//4)
		//size++;

		/*New->pNext = nullptr;
		New->pPrev = Tail;*/
		Tail = Tail->pNext = new Element(Data,nullptr, Tail);
		size++;
	}

	//						Removing elements:
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		//1) ��������� �������:
		Head = Head->pNext;
		//2)������� ������� �� ������:
		delete Head->pPrev;
		//3)�������� ������ ���������� ��������:
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		//1) ��������� �������:
		Element* Temp = Tail->pPrev;
		Tail = Tail->pPrev;
		//2)������� ������� �� ������:
		delete Tail->pNext;
		//3)�������� ������ ���������� ��������:
		Tail->pNext = nullptr;
		size--;	
	}
	void insert(int index, int Data)
	{
		//if (index == 0)return push_front(Data);
		//if (index > size)return;
		////1)������� ����� �������:
		//Element* New = new Element(Data);
		////2)������� �� ������� ��������:
		//Element* Temp = Head;
		//for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		////3)��������� ����� ������� � ������:
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		//New->pPrev = Temp;
		////Temp->pNext = new Element(Data, Temp->pNext);
		//size++;
		if (index > size)return;
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else 
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
		}
		//Element* New = new Element(Data);
		//New->pNext = Temp;
		//New->pPrev = Temp->pPrev;
		//Temp->pPrev->pNext = New;
		//Temp->pPrev = New;
		/*New->pPrev =*/  Temp->pPrev =Temp->pPrev->pNext= new Element(Data,Temp, Temp->pPrev);

		size++;
	}
	void erase(int index)
	{
		if (index == 0)return pop_front();
		if (index > size)return;
		//1)������� ����� �������:
		//Element* Erased = new Element(Data);
		//2)������� �� ������� ��������:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		//3)��������� ����� ������� � ������:
		delete Temp->pPrev;
		Temp->pPrev = Temp->pNext=Temp;
		
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		//New->pPrev = Temp;
		//Temp->pNext = new Element(Data, Temp->pNext);
		size--;
	}

	//						Methods:
	void print()const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "���������� ��������� ������: " << size << endl << endl;
	}
	void reverse_print()const
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
		}
		cout << "���������� ��������� ������������ ������: " << size << endl << endl;
	}
};

void print(const List& list)
{
	for(int i:list)
	{
		cout << i << tab;
	}
	cout << endl;
}
void reverse_print(const List& list)
{
	for (List::ReverseIterator rit = list.rbegin(); rit != list.rend(); ++rit)
	{
		*rit *= 10;
		cout << *rit << tab;
	}
	cout << endl;
}

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	/*list.reverse_print(); */
	list.push_back(123); list.print();
	//list.push_front(321); list.reverse_print();
	//list.pop_front(); list.print(); list.reverse_print();
	//list.pop_back(); list.print(); list.reverse_print();

	int value;
	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list.insert(index, value);
	list.print();
	list.erase(index);
	cout << "������� ������ ���������� ��������: "; cin >> index;
	list.print();
#endif // BASE_CHECK

	List list = { 3,5,8,13,21 };
	//list.print();
	print(list);
	reverse_print(list);

}