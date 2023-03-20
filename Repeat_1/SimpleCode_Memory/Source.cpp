//SimpleCode_Arrays
#include<iostream>
#include<string>
using namespace std;

//#define lesson_55	//Динамический массив с++ пример. Создание, заполнение, удаление, размер динамического массива.
//#define lesson_56	//Двумерный динамический массив c++ пример. Создание, заполнение, удаление. Динамические массивы.

#ifdef lesson_55


void main()
{
	int size;
	cout << "Type Array amount: "; cin >> size;
	int* arr = new int[size];
	for (int i = 0; i <= size; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << "\t";
		cout << arr + i << endl;
	}


	delete[] arr;



}
#endif // lesson_55
#ifdef lesson_56


void main()
{
	int rows = 4;
	int cols = 5;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	//=---------------------------------------
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << (arr[i][j] = rand() % 10)<<"\t";
		}
		cout << endl;
	}
	//=--------------------------------
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}
#endif // lesson_56