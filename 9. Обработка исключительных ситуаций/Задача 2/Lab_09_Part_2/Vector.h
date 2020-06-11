#pragma once
#include <iostream>
#include "Error.h"

using namespace std;

const int MAXSIZE = 30;

class Vector {
protected:
	int size;
	int* beg;
public:
	Vector();
	Vector(int s);
	Vector(int s, int* arr);
	Vector(const Vector& v);
	~Vector();
	Vector Add(int d);
	const Vector& operator=(const Vector& v);
	int operator[](int i);
	int operator()();
	Vector operator+(int a);
	Vector operator-(int n);
	Vector operator--();
	friend istream& operator>>(istream& in, Vector& v);
	friend ostream& operator<<(ostream& out, const Vector& v);
};