#pragma once
#include <iostream>
#include <string>
#include "Object.h"
#include "Person.h"
#include "Student.h"

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
	void Make(int);
	void Add(Object*); 
	void Add(); 
	void Get(int); 
	void Show(); 
	void Del(); 
	int operator()();
	void HandleEvent(const TEvent& e);
};