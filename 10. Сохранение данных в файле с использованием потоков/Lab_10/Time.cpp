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
Time Time::operator+(const Time& t)
{
	int t1 = min * 60 + sec;
	int t2 = t.min * 60 + t.sec;
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
	cout << "минуты: ";
	in >> t.min;
	cout << "секунды: ";
	in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}
fstream& operator>>(fstream& fin, Time& t)
{
	fin >> t.min;
	fin >> t.sec;
	return fin;
}
fstream& operator<<(fstream& fout, const Time& t)
{
	fout << t.min << "\n";
	fout << t.sec << "\n";
	return fout;
}