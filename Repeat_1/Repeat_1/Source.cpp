//Memory
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
#define tab	"\t"

int** allocate(const int rows, const int cols);
void clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr,int& n, int value);
int** push_row_back(int** arr,int& rows, const int cols);
int** push_row_front(int** arr,int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, const int index);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);
int* push_front(int* arr, int& n, int value);

void push_col_back(int** arr, const int rows, int& cols);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Ведите количество элементов: "; cin >> n;
	int* arr = new int[n];    //Тут в массиве вместе & - ссылки на указатель используем NEW -для массивов

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое занчениев конец: "; cin >> value;
	arr = push_back(arr, n, value);
	////1) Создаем новый массив нужного размера:
	//int* buffer = new int[n + 1];
	////2) Копируем све содержимое исходного массива в буферный:
	//for (int i = 0; i < n; i++)
	//{
	//	buffer[i] = arr[i];
	//}
	////3)Удаляем исходны массив:
	//delete[] arr;
	////4) Подменяем адресс в указателе 'arr' адресом нового массива:
	//arr = buffer;
	////5) Только после всего этого в конец массива arr можно добавить значение.
	//arr[n] = value;
	////6) После добавления в массив arr элемента, количество его элементов увеличивается на 1
	//n++;
	Print(arr, n);

	cout << "Введите добавляемое занчение в начало: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows, cols;
	cout << "rows: "; cin >> rows;
	cout << "cols: "; cin >> cols;

	int**arr = allocate(rows, cols);

	FillRand(arr, rows, cols); Print(arr, rows, cols);
#ifdef DYNAMIC_MEMORY_2
	cout << "Push row back: " << endl;
	arr = push_row_back(arr, rows, cols); Print(arr, rows, cols);

	cout << "Push row front: " << endl;
	arr = push_row_front(arr, rows, cols); Print(arr, rows, cols);

	int index;
	cout << "Insert, type index: "; cin >> index;
	arr = insert_row(arr, rows, cols, index); Print(arr, rows, cols);

	cout << "Pop row back: " << endl;
	arr = pop_row_back(arr, rows, cols); Print(arr, rows, cols);

	cout << "Pop row front: " << endl;
	arr = pop_row_front(arr, rows, cols); Print(arr, rows, cols);

	cout << "Erase, type index: "; cin >> index;
	arr = erase_row(arr, rows, cols, index); Print(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2

	cout << "Push col back: " << endl;
	push_col_back(arr, rows, cols); Print(arr, rows, cols);


	clear(arr, rows);
}

int** allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]  arr[i];
	}
	delete[] arr;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}



void FillRand(int arr[], const int n)
{
	cout << typeid(arr).name()<<endl;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int* arr, const int n)
{
	cout << typeid(arr).name()<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int* push_back(int* arr,int& n, int value)
{
	//1) Создаем новый массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем све содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходны массив:
	delete[] arr;
	//4) Подменяем адресс в указателе 'arr' адресом нового массива:
	arr = buffer;
	//5) Только после всего этого в конец массива arr можно добавить значение.
	arr[n] = value;
	//6) После добавления в массив arr элемента, количество его элементов увеличивается на 1
	n++;
	return arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows+1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
}
int** push_row_front(int** arr, int& rows, const int cols)
	{
		int** buffer = new int* [rows + 1];
		for (int i = 0; i < rows; i++)
		{
			buffer[i+1] = arr[i];
		}
		delete[] arr;
		arr = buffer;
		arr[0] = new int[cols] {};
		rows++;
		return arr;
	}
int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	rows--;
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	rows--;
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	rows--;
	int** buffer = new int* [rows];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	//1) Создаем новый массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем све содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3)Удаляем исходны массив:
	delete[] arr;
	//4) Подменяем адресс в указателе 'arr' адресом нового массива:
	arr = buffer;
	//5) Только после всего этого в конец массива arr можно добавить значение.
	arr[0] = value;
	//6) После добавления в массив arr элемента, количество его элементов увеличивается на 1
	n++;
	return arr;
}