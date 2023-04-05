//ForwardList
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

template<typename T>class Forwardlist;
template<typename T>class Iterator;
template<typename T> 
class Element
{
	static int count;
	T Data;   //данные элемента
	Element<T>* pNext;	//указатель на элмент списка
public:
	Element(T Data, Element<T>* pNext = nullptr);
		~Element();
	friend class Forwardlist<T>;
	friend class Iterator<T>;
};
template<typename T>
 int Element<T>::count = 0; //Инициализируем статическую переменную, объявленную в классе 'Element'



 template<typename T>
 class Iterator
 {
	 Element<T>* Temp;
 public:
	 Iterator(Element<T>* Temp = nullptr);
	 ~Iterator();
	 Iterator<T>& operator++();
	 bool operator==(const Iterator<T>& other)const;
	 bool operator!=(const Iterator<T>& other)const;
	 T& operator*();
 };


 template<typename T>
class Forwardlist //Forward - односвязный, однонаправленный список
{
	Element<T>* Head; //Голова списка - содержит указатель на нулевой элемент списка
	int size;
public:
	Iterator<T> begin();
	Iterator<T> end();
	Forwardlist();
	Forwardlist(const std::initializer_list<T>& il);
	~Forwardlist();

//																Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int index, T Data);
	void erase(int index);

	//															Erasing Elements
	void pop_front();
	void pop_back();

	//															Methods:
	void print()const;
};
/////////////////     Element      /////////////////////
template<typename T>Element<T>::Element(T Data, Element<T>* pNext) :Data(Data), pNext(pNext)
{
	count++;
	cout << "EConstructor:\t" << this << endl;
}
template<typename T>Element<T>::~Element()
{
	count--;
	cout << "EDestructor:\t" << this << endl;
}

/////////////////     Iterator      /////////////////////
template<typename T>Iterator<T>::Iterator(Element<T>* Temp) :Temp(Temp)
{
	cout << "ItConstructor:\t " << this << endl;
}
template<typename T>Iterator<T>::~Iterator()
{
	cout << "ItConstructor:\t " << this << endl;
}
template<typename T>Iterator<T>& Iterator<T>::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>bool Iterator<T>::operator==(const Iterator<T>& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool Iterator<T>::operator!=(const Iterator<T>& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>T& Iterator<T>::operator*()
{
	return Temp->Data;
}
/////////////////     Forwardlist      /////////////////////
template<typename T> Iterator<T> Forwardlist<T>::begin()
{
	return Head;
}
template<typename T>Iterator<T> Forwardlist<T>::end()
{
	return nullptr;
}
template<typename T>Forwardlist<T>::Forwardlist()
{
	Head = nullptr; //Если список пуст, его голова указывает на ноль.
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>Forwardlist<T>::Forwardlist(const std::initializer_list<T>& il) :Forwardlist()
{
	// il -сокращенно initializer_list
	cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>Forwardlist<T>::~Forwardlist()
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
}

//																Adding elements:
template<typename T> void Forwardlist<T>::push_front(T Data)
{
	//1) Создаем новый элемент:
	Element<T>* New = new Element<T>(Data);
	//2) Новый элемент должен указывать на начало списка:
	New->pNext = Head;
	//3) Голову списка переводим на новый элемент:
	Head = New;
	//Head = new Element<T>(Data,Head);
	size++;
}
template<typename T> void Forwardlist<T>::push_back(T Data)
{
	if (Head == nullptr)return push_front(Data);
	Element<T>* New = new Element<T>(Data);   //1) Создаем новый элемент списка
	Element<T>* Temp = Head;
	while (Temp->pNext)   //2)Доходим до конца списка
		Temp = Temp->pNext;			//Переход на следующий элемент
	//3) добавляем элемент в конец списка
	Temp->pNext = New;
	//Temp->Data = New->Data;
	//New -> pNext = nullptr;  

	//Head = new Element(Data, Head);
	size++;
}
template<typename T>void Forwardlist<T>::insert(int index, T Data)
{
	if (index == 0)return push_front(Data);
	if (index > size)return;
	//1)Создаем новый элемент:
	Element<T>* New = new Element<T>(Data);
	//2)Доходим до нужного элемента:
	Element<T>* Temp = Head;
	for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
	//3)Вставляем новый элемент в список:
	/*New->pNext = Temp->pNext;
	Temp->pNext = New;*/
	Temp->pNext = new Element<T>(Data, Temp->pNext);
	size++;
}
template<typename T>void Forwardlist<T>::erase(int index)
{

	size--;
}

//															Erasing Elements
template<typename T>void Forwardlist<T>::pop_front()
{
	Element<T>* Erased = Head;		//1) Запоминаем адресс удаляемого элемента
	Head = Head->pNext;			//2) Исключаем элемент из списка
	delete Erased;				//3) Удаляем первый элемент
	size--;
}
template<typename T>void Forwardlist<T>::pop_back()
{
	Element<T>* Temp = Head;
	while (Temp->pNext->pNext) Temp = Temp->pNext;
	delete Temp->pNext;
	Temp->pNext = nullptr;
	size--;
}

//															Methods:
template<typename T>void Forwardlist<T>::print()const
{
	/*Element* Temp = Head;    //Temp - это итератор. Это указательль, при помощи котороо можно получить доступ к элементам структуры данных
	while (Temp)
	{
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		Temp = Temp->pNext;			//Переход на следующий элемент
	} */
	for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов списка: " << size << endl;
	cout << "Обзее количество элементов списка: " << Element::count << endl;
}

//#define BASE_CHECK
//#define RANGED_BASE_FOR_FOR_ARRYA
//#define HOME_WORK_1
#define RANGED_BASED_FOR_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
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
	cout << "Введите значение добавляемого элемента: "; cin >> value;
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
#endif // BASE_CHECK
#ifdef RANGED_BASE_FOR_FOR_ARRYA
	int arr[] = { 3,5,8,13,21 };
	//for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	//{
	//	cout << arr[i] << tab;
	//}
	//cout << endl;
	for (int i : arr)   //Range-based FOR -			for для диапазона (контейнера)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGED_BASE_FOR_FOR_ARRYA
#ifdef RANGED_BASED_FOR_LIST
	Forwardlist<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;

	Forwardlist<double> d_list = { 2.7,3.14,1.9,8.3 };
	for (double i : d_list)cout << i << tab; cout << endl;

	Forwardlist<std::string> s_list = { "Хорошо","живет","на","свете","Винни-Пух" };
	for (std::string i : s_list)cout << i << tab; cout << endl;


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