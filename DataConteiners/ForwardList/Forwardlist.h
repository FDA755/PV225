#pragma once
//ForwardList
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

///////////////////   class - declaration (объ€вление класса	/////////////////////////////////

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
class Forwardlist //Forward - односв€зный, однонаправленный список
{
	Element<T>* Head; //√олова списка - содержит указатель на нулевой элемент списка
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
///////////////////   class - declaration end (конец объ€вление класса	/////////////////////////////////
