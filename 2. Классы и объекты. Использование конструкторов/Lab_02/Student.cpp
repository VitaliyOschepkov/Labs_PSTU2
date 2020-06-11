#include <string>
#include <iostream>
#include "student.h"

using namespace std;

Student::Student()
{
	fullname = "";
	group = "";
	averagemark = 0;
	cout << "����������� ��� ���������� ��� �������: " << this << "\n";
}
Student::Student(string f, string g, float a)
{
	fullname = f;
	group = g;
	averagemark = a;
	cout << "����������� � ����������� ��� �������: " << this << "\n";
}
Student::Student(const Student& s)
{
	fullname = s.fullname;
	group = s.group;
	averagemark = s.averagemark;
	cout << "����������� ����������� ��� �������: " << this << "\n";
}
Student::~Student()
{
	cout << "���������� ��� �������: " << this << "\n";
}
string Student::getFullname()
{
	return fullname;
}
string Student::getGroup()
{
	return group;
}
float Student::getAveragemark()
{
	return averagemark;
}
void Student::setFullname(string f)
{
	fullname = f;
}
void Student::setGroup(string g)
{
	group = g;
}
void Student::setAveragemark(float a)
{
	averagemark = a;
}
void Student::Show()
{
	cout << "\n���: " << fullname;
	cout << "\n������: " << group;
	cout << "\n������� ����: " << averagemark << "\n" << "\n";
}