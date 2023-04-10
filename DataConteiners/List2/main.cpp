#include"List.cpp"

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