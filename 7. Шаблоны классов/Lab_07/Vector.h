#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
private:
	int size;
	T* data;
public:
	Vector(); 
	Vector(int s, T k); 
	Vector(const Vector<T>& v); 
	~Vector();
	Vector& operator=(const Vector<T>& v);
	T& operator[](int index);
	Vector operator+(const T k);
	int operator()();
	friend istream& operator>><>(istream& in, Vector<T>& v);
	friend ostream& operator<<<>(ostream& out, const Vector<T>& v);
};
template <class T>
Vector<T>::Vector()
{

}
template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size = v.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}
template <class T>
Vector<T>::~Vector()
{
	delete[] data;
	data = 0;
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this == &v)
		return *this;
	size = v.size;
	if (data != 0)
		delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	return *this;
}
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size)
		return data[index];
	else
		cout << "\nError index > size";
}
template <class T>
Vector<T> Vector<T>::operator+(const T k)
{
	Vector<T> v(size,k);
	for (int i = 0; i < size; i++)
		v.data[i] = data[i] + k;
	return v;
}
template <class T>
int Vector<T>::operator()()
{
	return size;
}
template <class T>
istream& operator>>(istream& in, Vector<T>& v)
{
	for (int i = 0; i < v.size; i++)
		in >> v.data[i];
	return in;
}
template <class T>
ostream& operator<<(ostream& out, const Vector<T>& v)
{
	for (int i = 0; i < v.size; i++)
		out << v.data[i] << " ";
	return out;
}