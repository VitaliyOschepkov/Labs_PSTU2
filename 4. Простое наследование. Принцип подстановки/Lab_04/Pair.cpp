#include "Pair.h"

Pair::Pair()
{
	first = 0;
	second = 0;
}
Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}
Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}
Pair::~Pair()
{

}
int Pair::getFirst()
{
	return first;
}
int Pair::getSecond()
{
	return second;
}
void Pair::setFirst(int f)
{
	first = f;
}
void Pair::setSecond(int s)
{
	second = s;
}
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}
bool Pair::operator>(const Pair& p)
{
	int tmp1 = first;
	int tmp2 = second;
	int tmp3 = p.first;
	int tmp4 = p.second;
	return ((tmp1 > tmp3) || ((tmp1 == tmp3) && (tmp2 > tmp4)));
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "\nпервое число: ";
	in >> p.first;
	cout << "\nвторое число: ";
	in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	out << "\nПара: (" << p.first << "," << p.second << ")\n";
	return out;
}