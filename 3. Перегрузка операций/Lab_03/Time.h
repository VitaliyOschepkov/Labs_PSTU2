#pragma once
#include <iostream>

using namespace std;

class Time
{
	int min, sec;
public:
	Time() { min = 0; sec = 0; }
	Time(int m, int s) { min = m; sec = s; }
	Time(const Time& t) { min = t.min; sec = t.sec; }
	~Time() {}
	int getMin() { return min; }
	int getSec() { return sec; }
	void setMin(int m) { min = m; }
	void setSec(int s) { sec = s; }
	Time& operator=(const Time&);
	Time& operator++();
	Time operator++(int);
	Time operator+(const Time&);
	bool operator==(const Time&);
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};