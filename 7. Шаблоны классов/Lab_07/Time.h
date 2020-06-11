#pragma once
#include <iostream>

using namespace std;

class Time
{
	int min, sec;
public:
	Time(); 
	Time(int m, int s); 
	Time(const Time& t); 
	~Time();
	int getMin();
	int getSec();
	void setMin(int m);
	void setSec(int s);
	Time& operator=(const Time&);
	Time& operator++();
	Time operator++(int);
	Time operator+(const Time&);
	Time operator+(const int);
	bool operator==(const Time&);
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};