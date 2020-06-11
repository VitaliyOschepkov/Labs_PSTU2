#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Pair :
	public Object
{
protected:
	int first, second;
public:
	Pair(); 
	Pair(int, int); 
	Pair(const Pair&); 
	virtual ~Pair();
	int getFirst();
	int getSecond();
	void setFirst(int);
	void setSecond(int);
	Pair& operator=(const Pair&);
	bool operator>(const Pair&);
	void Compare(){}; 
	void Show(); 
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};