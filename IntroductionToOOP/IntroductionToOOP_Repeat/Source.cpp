//Introduction to OOP
#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x=x;
	}
	void set_y(double y)
	{
		this->y=y;
	}

																		//Constructors:						
	/*Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x =0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;

	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//																	//Operators
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
																		//Methods:
	double distance(const Point& other)const
	{
		//other.x *= 126;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance* x_distance+ y_distance* y_distance);
		return distance;
	}
	void print()const
	{
		cout <<"X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point& A, Point& B)
{
	double x_distance = A.get_x()-B.get_x();
	double y_distance = A.get_y()-B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
#define ASSIGNMENT_CHECK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A; cout << pA << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(4);
	A.set_y(3);
	Point B;
	B.set_x(9);
	B.set_y(4);

	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "���������� �� ����� � �� �: " << A.distance(B) << endl;
	cout << "����� � � �: " << distance(A, B) << endl;
#endif // DISTANCE_CHECK
#ifdef CONSTRUCTORS_CHECK
	Point A;
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B(2, 3);	B.print();

	Point C(3); C.print();

	Point D = C; D.print();//Copy constructor  
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment
	Point A(2, 3); A.print();
	Point B = A; B.print();
	Point C;
	C = B; C.print();

#endif // ASSIGNMENT_CHECK_1
#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(2, 3);




#endif // ASSIGNMENT_CHECK_2

}