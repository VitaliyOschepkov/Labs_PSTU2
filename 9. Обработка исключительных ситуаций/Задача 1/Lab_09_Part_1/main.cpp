#include <iostream>
#include <locale>
#include "Vector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    try
    {
        Vector x(2); 
        Vector y; 
        int i, n;
        cout << x; 
        cout << "input(-1 или 2): ";
        cin >> i;
        cout << x[i] << "\n"; 
        y = x + 6;
        cout << y;
        y = y.Add(8); 
        cout << y;
        cout << "Размер вектора y: " << y();
        cout << "\nСколько элементов удалить из вектора: ";
        cin >> n;
        y = y - n; 
        cout << "y - " << "n\n" << y;
        --x; 
        cout << x;
        --x;
        cout << x; 
        --x; 
    }
    catch (int e)
    {
        cout << e << "\n";
    }
    return 0;
}