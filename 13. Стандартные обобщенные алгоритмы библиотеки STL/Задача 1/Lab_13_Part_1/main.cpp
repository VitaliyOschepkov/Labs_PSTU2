#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include "Time.h"
#include <list>

using namespace std;

typedef vector<Time> Vec;
Vec::iterator it;
Time Z;

Vec vectorMake(int n)
{
    Vec v;
    for (int i = 0; i < n; i++)
    {
        int m = rand() % 60;
        int s = rand() % 60;
        Time a(m, s);
        v.push_back(a);
    }
    return v;
}
void vectorPrint(Vec v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " | ";
    cout << "\n";
}
Time Average(Vec v)
{
    Time a;
    int n = v.size();
    for (int i = 0; i < v.size(); i++)
        a = a + v[i];
    return a / n;
}
void averageAdd(Time& t)
{
    t = t + Z;
}
struct EqualToZ
{
    bool operator()(Time t)
    {
        return (t == Z);
    }
};
struct CompareLess
{
    bool operator()(Time t1, Time t2)
    {
        return (t1 > t2);
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Vec v;
    int n;
    cout << "Введите размер вектора: ";
    cin >> n;
    v = vectorMake(n);
    vectorPrint(v);
    it = max_element(v.begin(),v.end());
    Z = *(it);
    Time el1;
    cout << "Введите новый элемент:\n";
    cout << "> ";
    cin >> el1;  
    replace_if(v.begin(), v.end(), EqualToZ(), el1);
    vectorPrint(v);
    it = min_element(v.begin(), v.end());
    Z = *(it);
    remove_copy(v.begin(), v.end(), v.begin(), Z);
    vectorPrint(v);
    cout << "Сортировка по убыванию:\n";
    sort(v.begin(), v.end(), CompareLess());
    vectorPrint(v);
    cout << "Сортировка по возрастанию:\n";
    sort(v.begin(), v.end());
    vectorPrint(v);
    cout << "Введите элемент для поиска:\n";
    cout << "> ";
    cin >> Z;
    it = find(v.begin(), v.end(), Z);
    if (it != v.end())
        cout << "> " << *(it) << "\n";
    else
        cout << "Нет такого элемента\n";
    Z = Average(v);
    cout << "Среднее арифметическое:\n";
    cout << "> "<< Z << "\n";
    for_each(v.begin(), v.end(), averageAdd);
    vectorPrint(v);
    return 0;
}