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
void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0)
		out << "������ ����\n";
	Object** p = v.beg; 
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}