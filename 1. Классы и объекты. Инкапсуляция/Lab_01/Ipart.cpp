#include <iostream>
#include "ipart.h"

using namespace std;

void Ipart::iPart(unsigned f, unsigned s)
{
	first = f;
	if (s != 0)
		second = s;
	else {
		cout << "\n������ ����������� ����� 0\n";
		exit(1);
	}
}
void Ipart::Read()
{
	cout << "\n������� first: ";
	cin >> first;
	cout << "\n������� second: ";
	cin >> second;
}

void Ipart::Show()
{
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << "\n" << "\n";
}
int Ipart::Part()
{
	int p;
	if (second != 0)
		p = first / second;
	else {
		cout << "\n������ ����������� ����� 0\n";
		exit (2);
	}
	return p;
}