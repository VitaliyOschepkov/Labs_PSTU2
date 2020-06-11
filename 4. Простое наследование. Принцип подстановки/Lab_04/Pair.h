#pragma once
#include <iostream>

using namespace std;

class Pair
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
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};