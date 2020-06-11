#include <iostream>
#include <locale>
#include "Object.h"
#include "Vector.h"
#include "Pair.h"
#include "Fraction.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Object* p;
    Vector v(5);
    Pair a;
    Fraction b;
    cin >> a;
    cin >> b;
    cout << a;
    p = &b;
    p->Show();
    p = &a;
    v.Add(p);
    p = &b;
    v.Add(p);
    cout << v << "\n";
    return 0;
}