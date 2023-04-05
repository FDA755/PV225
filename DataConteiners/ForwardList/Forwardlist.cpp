#include"Forwardlist.h"

//------------------- Class definition - ����������� ������ ----------------------------------------
// 
/////////////////     Element      /////////////////////
template<typename T>
int Element<T>::count = 0; //�������������� ����������� ����������, ����������� � ������ 'Element'
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
	Head = nullptr; //���� ������ ����, ��� ������ ��������� �� ����.
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>Forwardlist<T>::Forwardlist(const std::initializer_list<T>& il) :Forwardlist()
{
	// il -���������� initializer_list
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
	//1) ������� ����� �������:
	Element<T>* New = new Element<T>(Data);
	//2) ����� ������� ������ ��������� �� ������ ������:
	New->pNext = Head;
	//3) ������ ������ ��������� �� ����� �������:
	Head = New;
	//Head = new Element<T>(Data,Head);
	size++;
}
template<typename T> void Forwardlist<T>::push_back(T Data)
{
	if (Head == nullptr)return push_front(Data);
	Element<T>* New = new Element<T>(Data);   //1) ������� ����� ������� ������
	Element<T>* Temp = Head;
	while (Temp->pNext)   //2)������� �� ����� ������
		Temp = Temp->pNext;			//������� �� ��������� �������
	//3) ��������� ������� � ����� ������
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
	//1)������� ����� �������:
	Element<T>* New = new Element<T>(Data);
	//2)������� �� ������� ��������:
	Element<T>* Temp = Head;
	for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
	//3)��������� ����� ������� � ������:
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
	Element<T>* Erased = Head;		//1) ���������� ������ ���������� ��������
	Head = Head->pNext;			//2) ��������� ������� �� ������
	delete Erased;				//3) ������� ������ �������
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
	/*Element* Temp = Head;    //Temp - ��� ��������. ��� �����������, ��� ������ ������� ����� �������� ������ � ��������� ��������� ������
	while (Temp)
	{
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		Temp = Temp->pNext;			//������� �� ��������� �������
	} */
	for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "���������� ��������� ������: " << size << endl;
	cout << "����� ���������� ��������� ������: " << Element::count << endl;
}
//------------------- Class definition end- ����� ����������� ������ ----------------------------------------