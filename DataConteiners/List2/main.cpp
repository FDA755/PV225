#include<iostream>
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
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List<T>;
	}*Head, * Tail;
	unsigned int size;
	class ConstBaseIterator
	{protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp) :Temp(Temp) {}
		~ConstBaseIterator() {}
		bool operator ==(const ConstBaseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator !=(const ConstBaseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const T& operator*()const
		{
			return Temp->Data;
		}
	};
	//unsigned int size;
public:
	class ConstIterator:public ConstBaseIterator
	{
	
		//Element* Temp;
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ConstIterator()
		{
#ifdef DEBUG
			cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		ConstIterator& operator++()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return *this;
		}
		ConstIterator operator++(int)
		{
			ConstIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return old;
		}
		ConstIterator& operator--()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return *this;
		}
		ConstIterator operator--(int)
		{
			ConstIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return old;
		}
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
		ConstReverseIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
		}
		~ConstReverseIterator()
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
		}
		ConstReverseIterator& operator++()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return *this;
		}
		ConstReverseIterator operator++(int)
		{
			ConstReverseIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
			return old;
		}
		ConstReverseIterator& operator--()
		{
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return *this;
		}
		ConstReverseIterator operator--(int)
		{
			ConstReverseIterator old = *this;
			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
			return old;
		}
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
		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}
		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	ConstIterator cbegin()const
	{
		return Head;
	}
	ConstIterator cend()const
	{
		return nullptr;
	}
	ConstIterator begin()const
	{
		return Head;
	}
	ConstIterator end()const
	{
		return nullptr;
	}
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ConstReverseIterator crbegin()const
	{
		return Tail;
	}
	ConstReverseIterator crend()const
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

	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const std::initializer_list<T>& il) :List()
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
	void push_front(T Data)
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
	void push_back(T Data)
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
		//1) Исключаем элемент:
		Head = Head->pNext;
		//2)Удаляем элемент из памяти:
		delete Head->pPrev;
		//3)Обнуляем адресс удаленного элемента:
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
		//1) Исключаем элемент:
		Element* Temp = Tail->pPrev;
		Tail = Tail->pPrev;
		//2)Удаляем элемент из памяти:
		delete Tail->pNext;
		//3)Обнуляем адресс удаленного элемента:
		Tail->pNext = nullptr;
		size--;	
	}
	void insert(int index, T Data)
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
		/*New->pPrev =*/  Temp->pPrev =Temp->pPrev->pNext= new Element(Data,Temp, Temp->pPrev);

		size++;
	}
	void erase(int index)
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
		cout << "Количество элементов списка: " << size << endl << endl;
	}
	void reverse_print()const
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
		}
		cout << "Количество элементов реверсивного списка: " << size << endl << endl;
	}
};

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

}