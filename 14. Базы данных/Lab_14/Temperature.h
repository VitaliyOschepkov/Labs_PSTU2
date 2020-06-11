#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Temperature
{
	int dayTemp;
	int tempTemp;
	bool flagTemp;
public:
	Temperature() { dayTemp = 0; tempTemp = 0; flagTemp = false; }
	Temperature(int d, int t) { dayTemp = d; tempTemp = t; flagTemp = false; }
	Temperature(const Temperature& t) { dayTemp = t.dayTemp; tempTemp = t.tempTemp; flagTemp = t.flagTemp; }
	~Temperature() {}
	int get_date() { return dayTemp; }
	int get_temp() { return tempTemp; }
	int get_del() { return flagTemp; }
	void set_date(int d) { dayTemp = d; }
	void set_temp(int t) { tempTemp = t; }
	void set_del(bool d) { flagTemp = d; }
	Temperature& operator=(const Temperature&);
	Temperature& operator++();
	Temperature operator+(const Temperature&);
	Temperature operator+(const int&);
	Temperature operator/(const Temperature&);
	Temperature operator/(const int&);
	bool operator==(const Temperature&);
	bool operator!=(const Temperature&);
	bool operator>(const Temperature&);
	bool operator>(const int&);
	bool operator<(const Temperature&);
	bool operator<(const int&);
	friend istream& operator>>(istream& in, Temperature& t);
	friend ostream& operator<<(ostream& out, const Temperature& t);
	friend fstream& operator>>(fstream& fin, Temperature& t);
	friend fstream& operator<<(fstream& fout, const Temperature& t);
};