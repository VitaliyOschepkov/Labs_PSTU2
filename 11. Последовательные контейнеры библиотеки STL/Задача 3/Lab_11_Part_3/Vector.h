#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Vector
{
private:
	int size;
	vector <T> v;
public:
	Vector(); 
	Vector(int n); 
	~Vector();
	void Print();
	T Average();
	void toAllAdd(T el);
	void positionAdd(T el, int pos);
	void beginAdd(T el);
	void positionDel(int pos);
	int MinNom();
	int MaxNom();
};
template <class T>
Vector<T>::Vector()
{
	size = 0;
}
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	size = v.size();
}
template <class T>
Vector<T>::~Vector()
{

}
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " | ";
	cout << "\n";
}
template <class T>
void Vector<T>::positionDel(int p)
{
	v.erase(v.begin() + p);
}
template <class T>
void Vector<T>::positionAdd(T e, int p)
{
	v.insert(v.begin() + p - 1, e);
}
template <class T>
void Vector<T>::beginAdd(T e)
{
	v.insert(v.begin(), e);
}
template <class T>
void Vector<T>::toAllAdd(T e)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + e;
}
template <class T>
T Vector<T>::Average()
{
	T a = v[0];
	int n = v.size();
	for (int i = 1; i < v.size(); i++)
		a = a + v[i];
	return a / n;
}
template <class T>
int Vector<T>::MaxNom()
{
	T m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m < v[i])
		{
			m = v[i];
			n = i;
		}
	}
	return n;
}
template <class T>
int Vector<T>::MinNom()
{
	T m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m > v[i])
		{
			m = v[i];
			n = i;
		}
	}
	return n;
}