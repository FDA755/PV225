﻿#include<iostream>
using namespace std;

#define tab "\t"
template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List<T>;
	}*Head, * Tail;
	unsigned int size;
	class ConstBaseIterator
	{protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp) :Temp(Temp) {}
		~ConstBaseIterator() {}
		bool operator ==(const ConstBaseIterator& other)const;
		bool operator !=(const ConstBaseIterator& other)const;
		const T& operator*()const;
	};
	//unsigned int size;
public:
	class ConstIterator:public ConstBaseIterator
	{
	
		//Element* Temp;
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp) {}
		~ConstIterator() {}
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
		//bool operator ==(const Iterator& other)const
		//{
		//	return this->Temp == other.Temp;
		//}
		//bool operator !=(const Iterator& other)const
		//{
		//	return this->Temp != other.Temp;
		//}
		//const int& operator*()const
		//{
		//	return Temp->Data;
		//}
		/*int& operator*()
		{
			return Temp->Data;
		}*/
		/*	const int& operator*()const
		{
			return Temp->Data;
		}*/
	};
	class ConstReverseIterator: public ConstBaseIterator
	{
		//Element* Temp;
	public:
		ConstReverseIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp) {}
		~ConstReverseIterator() {}	
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
		/*bool operator==(const ReverseIterator& other)
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
		}*/
	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp) :ConstIterator(Temp) {}
		~Iterator() {}
		T& operator*();
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}
		T& operator*();
	};
	ConstIterator cbegin()const;
	ConstIterator cend()const;
	ConstIterator begin()const;
	ConstIterator end()const;
	Iterator begin();
	Iterator end();
	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;
	ReverseIterator rbegin();
	ReverseIterator rend();

	List();
	List(const std::initializer_list<T>& il);
	~List();

	//						Adding Elements:
	void push_front(T Data);
	void push_back(T Data);

	//						Removing elements:
	void pop_front();
	void pop_back();
	void insert(int index, T Data);
	void erase(int index);

	//						Methods:
	void print()const;
	void reverse_print()const;
};
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////						Element methods								///////////////	
////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>List<T>::Element::Element(T Data, Element* pNext , Element* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "EConstructor:\t" << this << endl;
}
template<typename T>List<T>::Element::Element::~Element()
{
	cout << "EDestructor:\t" << this << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////						ConstBaseIterators methods					///////////////	
////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>bool List<T>::ConstBaseIterator::operator ==(const ConstBaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::ConstBaseIterator::operator !=(const ConstBaseIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>const T& List<T>::ConstBaseIterator::operator*()const
{
	return Temp->Data;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////						ConstReverseIterators methods				///////////////	
////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator  List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator  List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////						ConstIterators methods						///////////////	
////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////						Iterators methods							///////////////	
////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>T& List<T>::Iterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}
template<typename T>T& List<T>::ReverseIterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////						Lst methods									///////////////	
////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>typename List<T>::ConstIterator List<T>::cbegin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ConstIterator List<T>::begin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::end()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}

template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); ++it)
	{
		push_back(*it);
	}
}
template<typename T>List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//						Adding Elements:
template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	//Element* New = new Element(Data);	//1) Создали элемент
	//New->pNext = Head;					//
	//Head->pPrev = New;					//	
	//Head = New;							//4)
	//size++;
	//Element* New = new Element(Data,Head);	//1) Создали элемент
	//New->pNext = Head;					//
	Head = Head->pPrev = new Element(Data, Head);					//	
	//New;							//4)
	size++;
}
template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	//Element* New = new Element(Data);	//1) Создали элемент
	//New->pNext = nullptr;	
	//New->pPrev = Tail;//
	//Tail->pNext = New;					//	
	//Tail = New;							//4)
	//size++;

	/*New->pNext = nullptr;
	New->pPrev = Tail;*/
	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}

//						Removing elements:
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		return;
	}
	//1) Исключаем элемент:
	Head = Head->pNext;
	//2)Удаляем элемент из памяти:
	delete Head->pPrev;
	//3)Обнуляем адресс удаленного элемента:
	Head->pPrev = nullptr;
	size--;
}
template<typename T>void List<T>::pop_back()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		return;
	}
	//1) Исключаем элемент:
	Element* Temp = Tail->pPrev;
	Tail = Tail->pPrev;
	//2)Удаляем элемент из памяти:
	delete Tail->pNext;
	//3)Обнуляем адресс удаленного элемента:
	Tail->pNext = nullptr;
	size--;
}
template<typename T>void List<T>::insert(int index, T Data)
{
	//if (index == 0)return push_front(Data);
	//if (index > size)return;
	////1)Создаем новый элемент:
	//Element* New = new Element(Data);
	////2)Доходим до нужного элемента:
	//Element* Temp = Head;
	//for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
	////3)Вставляем новый элемент в список:
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
	/*New->pPrev =*/  Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);

	size++;
}
template<typename T>void List<T>::erase(int index)
{
	if (index == 0)return pop_front();
	if (index > size)return;
	//1)Создаем новый элемент:
	//Element* Erased = new Element(Data);
	//2)Доходим до нужного элемента:
	Element* Temp = Head;
	for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
	//3)Вставляем новый элемент в список:
	delete Temp->pPrev;
	Temp->pPrev = Temp->pNext = Temp;

	//New->pNext = Temp->pNext;
	//Temp->pNext = New;
	//New->pPrev = Temp;
	//Temp->pNext = new Element(Data, Temp->pNext);
	size--;
}

//						Methods:
template<typename T>void List<T>::print()const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << "Количество элементов списка: " << size << endl << endl;
}
template<typename T>void List<T>::reverse_print()const
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
	{
		cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
	}
	cout << "Количество элементов реверсивного списка: " << size << endl << endl;
}

template<typename T>void print(const List<T>& list)
{
	for(int i:list)
	{
		cout << i << tab;
	}
	cout << endl;
}
template<typename T>void reverse_print(const List<T>& list)
{
	for (typename List<T>::ConstReverseIterator rit = list.crbegin(); rit != list.crend(); ++rit)
	{
		//*rit *= 10;
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
	cout << "Введите размер списка: "; cin >> n;
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
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
	list.erase(index);
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.print();
#endif // BASE_CHECK

	List<int> list = { 3,5,8,13,21};
	//list.print();
	//print(list);
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	for (int& i : list)i *= 10;
	print(list);
	for (List<int>::ReverseIterator rit = list.rbegin();rit!=list.rend();rit++)*rit/= 10;
	reverse_print(list);

	List<double> list2 = { 0.5,0.4,1.23 };
	for (double i : list2)
	{
		cout << i << tab;
	}
	cout << endl;
}