#include <iostream>
#include "Time.h"

using namespace std;

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
Time Time::operator+(const Time& t) const
{
	int t1 = min * 60 + sec;
	int t2 = t.min * 60 + t.sec;
	Time tt;
	tt.min = (t1 + t2) / 60;
	tt.sec = (t1 + t2) % 60;
	return tt;
}
Time Time::operator+(const int& i)
{
	int t1 = min * 60 + sec;
	int t2 = i * 60 + i;
	Time t;
	t.min = (t1 + t2) / 60;
	t.sec = (t1 + t2) % 60;
	return t;
}
Time Time::operator/(const Time& t)
{
	int t1 = min * 60 + sec;
	int t2 = t.min * 60 + t.sec;
	Time tt;
	tt.min = (t1 / t2) / 60;
	tt.sec = (t1 / t2) % 60;
	return tt;
}
Time Time::operator/(const int& i)
{
	int t1 = min * 60 + sec;
	Time t;
	t.min = (t1 / i) / 60;
	t.sec = (t1 / i) % 60;
	return t;
}
bool Time::operator==(const Time& t) const
{
	int t1 = min * 60 + sec;
	int t2 = t.min * 60 + t.sec;
	return (t1 == t2);
}
bool Time::operator>(const Time& t) const
{
	return ((min > t.min) || (min == t.min && sec > t.sec));
}
bool Time::operator<(const Time& t) const
{
	return ((min < t.min) || (min == t.min && sec < t.sec));
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