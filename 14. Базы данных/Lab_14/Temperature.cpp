#include "Temperature.h"

using namespace std;

Temperature& Temperature::operator=(const Temperature& t)
{
	if (&t == this)
		return *this;
	dayTemp = t.dayTemp;
	tempTemp = t.tempTemp;
	flagTemp = t.flagTemp;
	return *this;
}
Temperature& Temperature::operator++()
{
	tempTemp++;
	return *this;
}
Temperature Temperature::operator+(const Temperature& t)
{
	Temperature tt;	
	if (!t.flagTemp)
		tt.tempTemp = tempTemp + t.tempTemp;
	else
		tt.tempTemp = tempTemp;
	return tt;
}
Temperature Temperature::operator+(const int& i)
{
	Temperature t;
	t.tempTemp = tempTemp + i;
	return t;
}
Temperature Temperature::operator/(const Temperature& t)
{
	Temperature tt;
	tt.tempTemp = tempTemp / t.tempTemp;
	return tt;
}
Temperature Temperature::operator/(const int& i)
{
	Temperature t;
	t.tempTemp = tempTemp / i;
	return t;
}
bool Temperature::operator==(const Temperature& t)
{
	return (tempTemp == t.tempTemp && !flagTemp && !t.flagTemp);
}
bool Temperature::operator!=(const Temperature& t)
{
	return (tempTemp != t.tempTemp && !flagTemp && !t.flagTemp);
}
bool Temperature::operator>(const Temperature& t)
{
	return (tempTemp > t.tempTemp && !flagTemp && !t.flagTemp);
}
bool Temperature::operator>(const int& i)
{
	return (tempTemp > i);
}
bool Temperature::operator<(const Temperature& t)
{
	return (tempTemp < t.tempTemp && !flagTemp && !t.flagTemp);
}
bool Temperature::operator<(const int& i)
{
	return (tempTemp < i);
}
istream& operator>>(istream& in, Temperature& t)
{
	cout << "Введите дату: ";
	in >> t.dayTemp;
	cout << "Введите температуру: ";
	in >> t.tempTemp;
	return in;
}
ostream& operator<<(ostream& out, const Temperature& t)
{
	if (!t.flagTemp)
		out << "  " << t.dayTemp << setw(11) << " : " << setw(11) << t.tempTemp << "  \n";
	return out;
}
fstream& operator>>(fstream& fin, Temperature& t)
{
	fin >> t.dayTemp;
	fin >> t.tempTemp;
	fin >> t.flagTemp;	
	return fin;
}
fstream& operator<<(std::fstream& fout, const Temperature& t)
{
	fout << t.dayTemp << "\n";
	fout << t.tempTemp << "\n";
	fout << t.flagTemp << "\n";
	return fout;
}