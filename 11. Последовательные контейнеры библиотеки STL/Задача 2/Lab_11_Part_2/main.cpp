#include <iostream>
#include <locale>
#include <cstdlib>
#include <vector>
#include "Time.h"

using namespace std;

typedef vector<Time> Vec;

Vec vectorMake(int n)
{
    Vec v;
    for (int i = 0; i < n; i++)
    {
        int m = rand() % 60;
        int s = rand() % 60;
        Time t(m, s);
        v.push_back(t); 
    }
    return v;
}
void vectorPrint(Vec v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " | ";
    cout << "\n";
}
void positionDel(Vec& v, int p)
{
    v.erase(v.begin() + p);
}
void positionAdd(Vec& v, Time e, int p)
{
    v.insert(v.begin() + p - 1, e);
}
void beginAdd(Vec& v, Time e)
{
    v.insert(v.begin(), e);
}
Time Average(Vec v)
{
    Time a;
    int n = v.size();
    for (int i = 0; i < v.size(); i++)
    {
       a = a + v[i];
        cout << a << "\n";
    }
    return a / n;
}
int MaxNom(Vec v)
{
    Time m = v[0];
    int n = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (m < v[i])
        {
            m = v[i];
            n = i;
        }
    }
    return n;
}
int MinNom(Vec v)
{
    Time m = v[0];
    int n = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (m > v[i])
        {
            m = v[i];
            n = i;
        }
    }
    return n;
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<Time> v;
    vector<Time>::iterator vi = v.begin();
    int n;
    cout << "Введите размер вектора: ";
    cin >> n;
    v = vectorMake(n);
    vectorPrint(v);
    int pos;
    pos = MinNom(v);
    positionDel(v, pos);
    vectorPrint(v);
    return 0;
}