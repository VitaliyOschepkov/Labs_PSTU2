#include "Vector.h"

Vector::Vector()
{
	beg = 0;
	size = 0;
	cur = 0;
}
Vector::Vector(int v)
{
	beg = new Object * [v];
	cur = 0;
	size = v;
}
Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}
void Vector::Make(int v)
{
	if (v == 0)
	{
		cout << "Недостаточный размер для создания группы\n";
		return;
	}
	else if (v >= 1)
	{
		beg = new Object * [v];
		cur = 0;
		size = v;
		cout << "Создана группа размера: " << size << "\n";
	}
	else
		return;
}
void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}
void Vector::Add()
{
	Object* p;
	if (size == 0)
	{
		cout << "Нет группы для добавления элемента\n";
		return;
	}
	if (cur == size)
	{
		cout << "Группа заполнена\n";
		return;
	}
	cout << "1.Person\n";
	cout << "2.Student\n";
	cout << "> ";
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* a = new Person;
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p; 
			cur++;
		}
	}
	else if (y == 2)
	{
		Student* b = new Student;
		b->Input();
		p = b;
		if (cur < size)
		{
			beg[cur] = p; 
			cur++;
		}
	}
	else
		return;
}
void Vector::Get(int g) {
	if (size == 0)
	{
		cout << "Нет группы для показа элемента\n";
		return;
	}
	if (cur == 0)
	{
		cout << "Группа пуста\n";
		return;
	}
	Object** p = beg; 
	int index = g - 1;
	if (index < 0)
	{
		cout << "Введен не допустимый индекс\n";
		return;
	}
	if (g > cur)
	{
		cout << "Введеное значение превышает допустимое\n";
		return;
	}
	for (int i = 0; i < cur; i++)
	{
		if (i == index)
			(*p)->Show(); 
		p++;
	}
}
void Vector::Show()
{
	if (size == 0)
	{
		cout << "Нет группы для показа элементов\n";
		return;
	}
	if (cur == 0)
	{
		cout << "Группа пуста\n";
		return;
	}
	Object** p = beg; 
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show(); 
		p++;
	}
}
void Vector::Del()
{
	if (size == 0)
	{
		cout << "Нет группы для удаления элемента\n";
		return;
	}
	if (cur == 0)
	{
		cout << "Группа пуста\n";
		return;
	}
	cur--;
}
int Vector::operator()()
{
	return cur;
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}