#include <iostream>
#include "Vector.h"
#include "Time.h"

int main()
{
    setlocale(LC_ALL, "rus");
    Vector<int> a(5,0);
    cout << a << "\n";
    cin >> a;
    cout << a << "\n";
    a[2] = 69;
    cout << a << "\n";
    Vector<int> b(10,5);
    cout << b << "\n";
    b = a;
    cout << b << "\n";
    Vector<int> c(10,0);
    c = b + 100;
    cout << c << "\n";
    cout << "Длина вектора a = " << a() << "\n";
    Time t;
    cin >> t;
    cout << t << "\n";
    Vector<Time> d(5, t);
    cin >> d;
    cout << d << "\n";
    Vector<Time> e(10, t);
    cout << e << "\n";
    e = d;
    cout << e << "\n";
    cout << d[2];
    cout << "\nДлина вектора d = " << d() << "\n";
    e = d + t;
    cout << e << "\n";
	return 0;
}