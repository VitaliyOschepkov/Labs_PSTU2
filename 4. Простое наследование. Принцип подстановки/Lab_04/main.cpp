#include <iostream>
#include <locale>
#include "Pair.h"
#include "Fraction.h"

using namespace std;

void func1(Pair& p)
{
    p.setSecond(9);
    cout << p;
}
Pair func2()
{
    Fraction f(18, 12);
    return f;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Pair a;
    cin >> a;
    cout << a;
    Pair b(10, 12);
    cout << b;
    if (a > b) cout << a << ">" << b << endl;
    a = b; 
    cout << a;
    Fraction c;
    cin >> c;
    cout << c;
    int h = c.getFirst();
    cout << "Целая часть дроби C: " << h << endl;
    Fraction f1, f2;
    cin >> f1;
    cin >> f2;
    if (f1 != f2)
        cout << f1 << "!=" << f2 << "\n";
    if (f1 == f2)
        cout << f1 << "==" << f2 << "\n";
    if (f1 >= f2)
        cout << f1 << ">=" << f2 << "\n";
    if (f1 <= f2)
        cout << f1 << "<=" << f2 << "\n";
    if (f1 > f2)
        cout << f1 << ">" << f2 << "\n";
    if (f1 < f2)
        cout << f1 << "<" << f2 << "\n";
    func1(c); 
    a = func2(); 
    cout << a;
    return 0;
}