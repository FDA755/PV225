//Introduction to OOP repeat
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
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)
	{
		/*this->x++;
		this->y++;*/
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}
	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
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
Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else return false;*/
	return (left.get_x() == right.get_x() && left.get_y() == right.get_y());
}
bool operator!=(const Point& left, const Point& right)
{
	return !(left==right );
}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}
std::istream& operator>>(std::istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj(x, y);
	return is;
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
	cout << "Расстояние от точки А до Б: " << A.distance(B) << endl;
	cout << "Между А и Б: " << distance(A, B) << endl;
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
	/*int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(2, 3);*/

	/*Point A(2, 3);
	Point B(4, 5);
	Point C = A + B; C.print();
	++C; C.print();
	C++; C.print();

	cout << (A == A) << endl;
	cout << (A != A) << endl;*/
	Point A(2,3);	A.print();
	A.set_x(12);
	A.set_y(5);		A.print();
	A(4, 4);		A.print();
	cout << A << endl;;
	cin >> A; A.print();
#endif // ASSIGNMENT_CHECK_2

}