#include <iostream>
#include "Time.h"

using namespace std;

Time::Time()
{
	min = 0;
	sec = 0;
}
Time::Time(int m, int s)
{
	min = m;
	sec = s;
}
Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}
Time::~Time()
{

}
int Time::getMin()
{
	return min;
}
int Time::getSec()
{
	return sec;
}
void Time::setMin(int m)
{
	min = m;
}
void Time::setSec(int s)
{
	sec = s;
}
Time& Time::operator=(const Time& t)
{
	if (&t == this)
		return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time& Time::operator++()
{
	int t = min * 60 + sec;
	t++;
	min = t / 60;
	sec = t % 60;
	return *this;
}
Time Time::operator++(int)
{
	int t = min * 60 + sec;
	t++;
	Time tt(min, sec);
	min = t / 60;
	sec = t % 60;
	return tt;
}
Time Time::operator+(const Time& t)
{
	int t1 = min * 60 + sec;
	int t2 = t.min * 60 + t.sec;
	Time tt;
	tt.min = (t1 + t2) / 60;
	tt.sec = (t1 + t2) % 60;
	return tt;
}
Time Time::operator+(const int k)
{
	int t1 = min * 60 + sec;
	int t2 = k * 60 + k;
	Time tt;
	tt.min = (t1 + t2) / 60;
	tt.sec = (t1 + t2) % 60;
	return tt;
}
bool Time::operator==(const Time& t)
{
	int t1 = min * 60 + sec;
	int t2 = t.min * 60 + t.sec;
	return (t1 == t2);
}
istream& operator>>(istream& in, Time& t)
{
	cout << "¬ведите минуты: ";
	in >> t.min;
	cout << "¬ведите секунды: ";
	in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}