#include "Vector.h"

Vector::Vector()
{
	size = 0;
	beg = 0;
}
Vector::Vector(int s)
{
	if (s > MAXSIZE)
		throw 1; 
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}
Vector::Vector(int s, int* arr)
{
	if (s > MAXSIZE)
		throw 2; 
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = arr[i];
}
Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}
Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
}
const Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	if (beg != 0)
		delete[] beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return *this;
}
int Vector::operator[](int i)
{
	if (i < 0)
		throw 3; 
	if (i >= size)
		throw 4; 
	return beg[i];
}

int Vector::operator()()
{
	return size;
}
Vector Vector::Add(int d)
{
	if (size + 1 == MAXSIZE)
		throw 5; 
	Vector v(size + 1, beg);
	v.beg[size] = d;
	return v;
}
Vector Vector::operator+(const int k)
{
	Vector v(size);
	for (int i = 0; i < size; i++)
		v.beg[i] = beg[i] + k;
	return v;
}
Vector Vector::operator-(int n)
{
	if (size == 0)
		throw 6; 
	if (size == 1)
	{ 
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}
	if (n > size)
		throw 7;
	for (int z = 0; z < n; z++)
	{
		Vector v(size, beg);
		delete[] beg;
		size--;
		beg = new int[size];
		for (int i = 0; i < size; i++)
			beg[i] = v.beg[i];
	}
	return *this;
}
Vector Vector::operator--()
{
	if (size == 0)
		throw 8; 
	if (size == 1)
	{ 
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}
	Vector v(size, beg);
	delete[] beg;
	size--;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return *this;
}
istream& operator>>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << "> ";
		in >> v.beg[i];
	}
	return in;
}
ostream& operator <<(ostream& out, const Vector& v)
{
	if (v.size == 0)
		out << "Вектор пуст\n";
	else {
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << "\n";
	}
	return out;
}