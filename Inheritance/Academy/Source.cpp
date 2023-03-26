//Academy
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Human
{
	std::string last_name;
	std::string first_name;
	tm birth_date;				//tm-timepoint
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	tm get_birth_date()const
	{
		return birth_date;
	}
	unsigned int get_age()const
	{
		time_t t_today = time(NULL); //Получаем текущую дату в формате Timestamp
		//cout << today << endl;
		tm* tm_today = localtime(&t_today);
		unsigned int age = tm_today->tm_year - birth_date.tm_year;
		if (tm_today->tm_mon < birth_date.tm_mon) age--;
		if (tm_today->tm_mon == birth_date.tm_mon && tm_today->tm_mday < birth_date.tm_mday)age--;
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_firts_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_date(int year, int month, int day)
	{
		birth_date.tm_year = year - 1900;
		birth_date.tm_mon = month - 1;
		birth_date.tm_mday = day;
	}
	//	---------------------------------------------------- Constructors:
	Human(const std::string& last_name, const std::string& first_name, int year, int month, int day)
	{
		set_last_name(last_name);
		set_firts_name(first_name);
		set_birth_date(year, month, day);
		cout << "HConstructors:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructors:\t" << this << endl;
	}
	//	----------------------------------------------------  Methods:
	void info()const
	{
		cout << last_name << " " << first_name << " " << get_age() << endl;
	}
};

class Student : public Human
{
	std::string specialty;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return specialty;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//	---------------------------------------------------- Constructors:
	Student(
		const std::string& last_name, const std::string& first_name, int year, int month, int day,
		const std::string& specialty, const std::string& group, double rating, double attendance
	) : Human(last_name,first_name, year, month, day)		//Вызов конструктор абазового класса.
	{
		set_specialty(specialty);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructors:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << specialty << " " << group << " " << rating << " " << attendance << endl;
	}


};
//#define TIME_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TIME_CHECK
	time_t t_today = time(NULL); //Получаем текущую дату в формате Timestamp
	cout << t_today << endl;
	tm* tm_today = localtime(&t_today);
	cout << tm_today->tm_year + 1900
		<< "\t" << tm_today->tm_mon + 1
		<< "\t" << tm_today->tm_mday << endl;
	cout << asctime(tm_today) << endl;
#endif // TIME_CHECK

	Human human("Федосов", "Дмитрий", 1990, 01, 01);
	human.info();

	Student student("Федосов", "Дмитрий", 1991, 01, 01, "programmer", "pv225", 5, 100);
	student.info();
}