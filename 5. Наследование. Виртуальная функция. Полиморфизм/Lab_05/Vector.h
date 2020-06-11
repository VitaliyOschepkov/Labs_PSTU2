#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Vector
{
private:
	int size; 
	int cur; 
	Object** beg; 
public:
	Vector(); 
	Vector(int); 
	~Vector();
	void Add(Object*); 
	friend ostream& operator<<(ostream& out, const Vector& v);
};