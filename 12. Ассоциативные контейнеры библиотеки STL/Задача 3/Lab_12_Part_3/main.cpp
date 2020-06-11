#include <iostream>
#include <locale>
#include <map>
#include "Time.h"
#include "Vector.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Vector<Time> vec(10);
	Time el;
	vec.Print();
	el = vec.Average();
	cout << "Среднее арифметическое: |" << el << endl;
	vec.toAllAdd(el);
	vec.Print();
	return 0;
}