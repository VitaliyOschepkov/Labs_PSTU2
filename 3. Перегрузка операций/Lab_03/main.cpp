#include <iostream>
#include <locale>
#include "Time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Time t1, t2, t3, t4, t5;
    cout << "Введите t1:\n";
    cin >> t1;
    cout << "\nВведите t2:\n";
    cin >> t2;
    ++t1;
    cout << "\n++t1 = " << t1;
    t3 = (t1++) + t2;
    cout << "\nt1 = " << t1;
    cout << "\nt2 = " << t2;
    cout << "\nt3 = " << t3;
    cout << "\nВведите t4:\n";
    cin >> t4;
    cout << "\nВведите t5:\n";
    cin >> t5;
    cout << "\nt4 = " << t4;
    cout << "\nt5 = " << t5;
    if (t4 == t5)
        cout << "\nt4 и t5 равны!";  
    else
        cout << "\nt4 и t5 не равны!";
    cout << "\n" << t4 << " + " << t5 << " = " << t4 + t5 << "\n";
    return 0;
}