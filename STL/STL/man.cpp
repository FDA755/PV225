#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------------------------------------------\n"

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "Max size:\t" << vec.max_size() << endl;
}

//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//Array - это контейнер, который хранит данные в виде статического массива.
	const int N = 5;
	std::array<int, N> arr = { 3,5,8 };
	//arr.fill(5);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

#endif // STL_ARRAY
#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		//cout << vec[i] << tab;
		cout << vec.at(i) << tab;
	}
	cout << endl;
	vector_properties(vec);
	cout << delimiter << endl;
	std::vector<int> vec2(100);
	vector_properties(vec2);
	cout << delimiter << endl;
	vec2.push_back(100);
	vector_properties(vec2);
	cout << delimiter << endl;
	vec2.shrink_to_fit();
	vector_properties(vec2);
	for (int i = 0; i < 90; i++)vec2.pop_back();
	cout << delimiter << endl;
	vector_properties(vec2);
	cout << delimiter << endl;
	vec.reserve(255);
	vec.resize(8);
	for (int i : vec)cout << i << tab; cout << endl;
	vector_properties(vec);
#endif // STL_VECTOR





}