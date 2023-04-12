#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n > 12)throw std::exception("Arithmetical overflow");
	int f = 1;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "!=";
		f *= i;
		cout << f << endl;
	}
	return f;
}


//#define EXCEPTION_BASICS
//#define devided_by_zero

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXCEPTION_BASICS
	/*int a = 2;
	cout << a << endl;
	cout << "Finish" << endl;*/
	try
	{
		throw;
		//throw 1;
		//throw "Something went wrong";		//Ключевое слово 'throw' (бросить) бросает исключение.
		throw std::exception("STD exception thrown");
	}
	catch (int e)
	{
		std::cerr << "Error #" << e << std::endl;
	}
	catch (const char* e)
	{
		std::cerr << "Error: " << e << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error: Some exception was thrown..." << endl;
	}
	cout << "Final" << endl;
#endif // EXCEPTION_BASICS

#ifdef devided_by_zero
	int a, b;
	cout << " Введите два числа: "; cin >> a >> b;
	try
	{
		cout << a / b << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cerr << "Something went wrong" << endl;
	}
	//cout << a / b << endl;  
#endif // devided_by_zero

	int n;
	cout << "Введите число: "; cin >> n;
	try
	{
		cout << factorial(n) << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

}