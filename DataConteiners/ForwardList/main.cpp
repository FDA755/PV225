#include"Forwardlist.cpp"



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