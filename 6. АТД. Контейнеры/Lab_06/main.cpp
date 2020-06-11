#include <iostream>
#include <locale>
#include "Vector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Vector a(5);
    cout << a << "\n";
    cin >> a;
    cout << a << "\n";
    a[2] = 69;
    cout << a << "\n";
    Vector b(10);
    cout << b << "\n";
    b = a;
    cout << b << "\n";
    Vector c(10);
    c = b + 100;
    cout << c << "\n";
    cout << "Длина вектора A = " << a() << "\n";
    cout << *(a.first()) << "\n";
    Iterator i = a.first();
    ++i;
    cout << *i << "\n";
    for (i = a.first(); i != a.last(); ++i)
        cout << *i << " ";
    return 0;
}