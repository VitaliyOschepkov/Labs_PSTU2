
#include <iostream>
#include <locale>
#include "Ipart.h"

using namespace std;

Ipart makeIpart(unsigned f, unsigned s)
{
    Ipart temp;
    temp.iPart(f, s);
    return temp;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Ipart a;
    Ipart b;
    a.iPart(6, 4);
    b.Read();
    a.Show();
    b.Show();
    cout << "Целая часть дроби A ("<< a.first << "/" << a.second << ") равна: " << a.Part() << "\n";
    cout << "Целая часть дроби B (" << b.first << "/" << b.second << ") равна: " << b.Part() << "\n";   
    Ipart* i = new Ipart;
    i->iPart(10.12, 4.6);
    i->Show();
    i->Part();
    cout << "Целая часть дроби i ("<< i->first << "/" << i->second << ") равна: " << i->Part() << "\n";
    Ipart arr[3];
    for (int i = 0; i < 3; i++)
        arr[i].Read();
    for (int i = 0; i < 3; i++)
        arr[i].Show();
    for (int i = 0; i < 3; i++)
    {
        arr[i].Part();
        cout << "Целая часть дроби arr[" << i << "] (" << arr[i].first << "/" << arr[i].second << ") равна: ";
        cout << arr[i].Part() << "\n";
    }
    Ipart* darr = new Ipart[3];
    for (int i = 0; i < 3; i++)
        darr[i].Read();
    for (int i = 0; i < 3; i++)
        darr[i].Show();
    for (int i = 0; i < 3; i++)
    {
        darr[i].Part();
        cout << "Целая часть дроби darr[" << i << "] (" << darr[i].first << "/" << darr[i].second << ") равна: ";
        cout << darr[i].Part() << "\n";
    }
    unsigned y;
    unsigned z;
    cout << endl << "введите значение first: ";
    cin >> y;
    cout << endl << "введите значение second: ";
    cin >> z;
    Ipart f = makeIpart(y, z);
    f.Show();
    f.Part();
    cout << "Целая часть дроби f (" << f.first << "/" << f.second << ") равна: " << f.Part() << "\n";
    return 0;
}