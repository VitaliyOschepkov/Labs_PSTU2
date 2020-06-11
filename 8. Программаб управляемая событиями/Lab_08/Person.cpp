#include "Person.h"

Person::Person()
{
	name = "";
	age = 0;
}
Person::Person(string n, int a)
{
	name = n;
	age = a;
}
Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}
Person::~Person()
{

}
string Person::getName()
{
	return name;
}
int Person::getAge()
{
	return age;
}
void Person::setName(string n)
{
	name = n;
}
void Person::setAge(int a)
{
	age = a;
}
Person& Person::operator=(const Person& p)
{
	if (&p == this)
		return *this;
	name = p.name;
	age = p.age;
	return *this;
}
void Person::Show()
{
	cout << "\nИмя: " << name;
	cout << "\nВозраст: " << age << "\n";
}
void Person::Input()
{
	cout << "\nВведите имя: ";
	cin >> name;
	cout << "\nВведите возраст: ";
	cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{	
		switch (e.command)
		{
		case cmGet:
			cout << "Имя: " << getName() << "\n";
			break;
		}
	}
}