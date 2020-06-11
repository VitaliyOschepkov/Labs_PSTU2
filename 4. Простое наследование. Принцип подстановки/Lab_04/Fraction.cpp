#include "Fraction.h"

Fraction::Fraction() :Pair()
{

}
Fraction::Fraction(int f, int s) : Pair(f, s)
{

}
Fraction::Fraction(const Fraction& f)
{
	first = f.first;
	second = f.second;
}
Fraction::~Fraction()
{

}
Fraction& Fraction::operator=(const Fraction& f)
{
	if (&f == this)
		return *this;
	first = f.first;
	second = f.second;
	return *this;
}
bool Fraction::operator==(const Fraction& f)
{
	int tmp1 = first;
	int tmp2 = second;
	int tmp3 = f.first;
	int tmp4 = f.second;
	return ((tmp1 == tmp3) && (tmp2 == tmp4));
}
bool Fraction::operator!=(const Fraction& f)
{
	int tmp1 = first;
	int tmp2 = second;
	int tmp3 = f.first;
	int tmp4 = f.second;
	return ((tmp1 != tmp3) || (tmp2 != tmp4));
}
bool Fraction::operator>=(const Fraction& f)
{
	int tmp1 = first;
	int tmp2 = second;
	int tmp3 = f.first;
	int tmp4 = f.second;
	return (((tmp1 > tmp3) || ((tmp1 == tmp3) && (tmp2 > tmp4))) || ((tmp1 == tmp3) && (tmp2 == tmp4)));
}
bool Fraction::operator<=(const Fraction& f)
{
	int tmp1 = first;
	int tmp2 = second;
	int tmp3 = f.first;
	int tmp4 = f.second;
	return (((tmp1 < tmp3) || ((tmp1 == tmp3) && (tmp2 < tmp4))) || ((tmp1 == tmp3) && (tmp2 == tmp4)));
}
bool Fraction::operator<(const Fraction& f)
{
	int tmp1 = first;
	int tmp2 = second;
	int tmp3 = f.first;
	int tmp4 = f.second;
	return ((tmp1 < tmp3) || ((tmp1 == tmp3) && (tmp2 < tmp4)));
}
int Fraction::Part()
{
	int p;
	if (second != 0)
		p = first / second;
	else
	{
		cout << "\nОШИБКА : знаменатель равен 0\n";
		exit(1);
	}
	return p;
}
istream& operator>>(istream& in, Fraction& f)
{
	cout << "\nВведите целую часть: ";
	in >> f.first;
	cout << "\nВведите дробную часть: ";
	in >> f.second;
	if (f.second < 0)
	{
		cout << "ОШИБКА";
		exit(2);
	}
	return in;
}
ostream& operator<<(ostream& out, const Fraction& f)
{
	out << "\nДробь: " << f.first << "," << f.second << "\n";
	return out;
}