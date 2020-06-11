#include "Student.h"

Student::Student() :Person()
{
	rating = 0;
}
Student::Student(string n, int a, float r) : Person(n, a)
{
	rating = r;
}
Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	rating = s.rating;
}
Student::~Student()
{

}
float Student::getRating()
{
	return rating;
}
void Student::setRating(float r)
{
	rating = r;
}
Student& Student::operator=(const Student& s)
{
	if (&s == this)
		return *this;
	name = s.name;
	age = s.age;
	rating = s.rating;
	return *this;
}
void Student::Show()
{
	cout << "\n���: " << name;
	cout << "\n�������: " << age;
	cout << "\n�������: " << rating << "\n";
}
void Student::Input()
{
	cout << "\n������� ���: ";
	cin >> name;
	cout << "\n������� �������: ";
	cin >> age;
	cout << "\n������� �������: ";
	cin >> rating;
}