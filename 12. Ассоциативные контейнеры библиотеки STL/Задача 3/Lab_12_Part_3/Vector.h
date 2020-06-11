#pragma once
#include <iostream>
#include <map>

using namespace std;

template <class T>
class Vector
{
private:
	int size;
	multimap <int, T> map;
public:
	Vector(); 
	Vector(int n); 
	~Vector();
	void Print();
	T Average();
	void toAllAdd(T el);
	void positionAdd(T el, int pos);
	void endAdd(T el);
	void beginAdd(T el);
	void multimapBeginAdd(T el);
	void positionDel(int pos);
	int MinKey();
	int MaxKey();
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
		map.insert(make_pair(i, a));
	}
	size = map.size();
}
template <class T>
Vector<T>::~Vector()
{

}
template <class T>
void Vector<T>::Print()
{
	typename multimap<int,T>::iterator it;
	for (it = map.begin(); it != map.end(); it++)
	{
		cout << (*it).first << " | " << (*it).second << " | ";
	}
	cout << "\n";
}
template <class T>
void Vector<T>::positionDel(int p)
{
	map.erase(p);
}
template <class T>
void Vector<T>::positionAdd(T e, int p)
{
	map.emplace(p, e);
}
template <class T>
void Vector<T>::endAdd(T e)
{
	typename multimap<int, T>::iterator it;
	it = map.end();
	--it;
	map.insert(make_pair((*it).first + 1, e));
}
template <class T>
void Vector<T>::beginAdd(T e)
{
	multimap<int,T> t;
	typename multimap<int, T>::iterator it;
	typename multimap<int, T>::iterator tt;
	t.emplace(0, e);
	for (it = map.begin(); it != map.end(); it++)
	{
		tt = t.end();
		--tt;
		t.insert(make_pair((*tt).first + 1, (*it).second));
	}
	map = t;
}
template <class T>
void Vector<T>::multimapBeginAdd(T el)
{
	map.emplace(0, el);
}
template <class T>
void Vector<T>::toAllAdd(T el)
{
	typename multimap<int, T>::iterator it;
	for (it = map.begin(); it != map.end(); it++)	
		(*it).second = (*it).second + el;
}
template <class T>
T Vector<T>::Average()
{
	typename multimap<int, T>::iterator it;
	T a;
	int n = map.size();
	for (it = map.begin(); it != map.end(); it++)
		a = a + (*it).second;
	return a / n;
}

template <class T>
int Vector<T>::MaxKey()
{
	typename multimap<int, T>::iterator it;
	T max;
	int key;
	for (it = map.begin(); it != map.end(); it++)
	{
		if (max < (*it).second)
		{
			max = (*it).second;
			key = (*it).first;
		}
	}
	return key;
}
template <class T>
int Vector<T>::MinKey()
{
	typename multimap<int, T>::iterator it = map.begin();
	T min = (*it).second;
	int key;
	for (it = map.begin(); it != map.end(); it++)
	{
		if (min > (*it).second)
		{
			min = (*it).second;
			key = (*it).first;
		}
	}
	return key;
}