#include"Fraction.h"


//#define CONSTRUCTORS_CHECK
//#define CHECK_ARIFMETICAL
//#define COMPARISON_OPERATOR
//#define HOME_WORK_1
#define HOME_WORK_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; A.print();
	Fraction B = 5; B.print();
	Fraction C(2, 3); C.print();

	Fraction D(2, 3, 4); D.print();
	Fraction E = D; E.print();
#endif // CONSTRUCTORS_CHECK
#ifdef CHECK_ARIFMETICAL
	Fraction A(2, 3, 4); A.print();
	Fraction B(3, 4, 5); B.print();
	//Fraction C = A * B; C.print();
	//Fraction D= A / B; D.print();

	A *= B; A.print();
	A /= B; A.print();
	A += B; A.print();
	A -= B; A.print();
	++A; A.print();
	--A; A.print();
	A++; A.print();
	A--; A.print();
#endif // CHECK_ARIFMETICAL
#ifdef COMPARISON_OPERATOR
	Fraction A(2, 3, 4); A.print();
	Fraction B(3, 4, 5); B.print();
	cout << (A == A) << endl;
	cout << (A != B) << endl;
	cout << (Fraction(1, 2) != Fraction(2, 3)) << endl;
	cout << (Fraction(1, 2) < Fraction(2, 3)) << endl;
	cout << (Fraction(1, 2) > Fraction(2, 3)) << endl;
	cout << (Fraction(3, 2) <= Fraction(3, 1)) << endl;
	cout << (Fraction(3, 2) >= Fraction(3, 1)) << endl;
#endif // COMPARISON_OPERATOR

	/*Fraction A = 5; A.print();
	Fraction B; B = 8; B.print();*/
	/*Fraction A(11, 4); A.print();
	int a = (int)A; cout << a << endl;*/

#ifdef HOME_WORK_1
	Fraction D(2, 3, 4); double b = (double)D;
	cout << b << endl;
#endif // HOME_WORK_1
#ifdef HOME_WORK_2
	Fraction B = 2.65; cout << B << endl;
	
#endif // HOME_WORK_2

	Fraction A;
	cout << "Type simple drob': "; cin >> A; cout << A << endl;

}