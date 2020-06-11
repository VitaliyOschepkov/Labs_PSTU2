#include <iostream>
#include <locale>
#include <set>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef set<Time, less<Time>> Set;
Set::iterator it;
Time Z;
Set tempS;

Set setMake(int n)
{
    Set T;
    for (int i = 0; i < n; i++)
    {
        int m = rand() % 60;
        int s = rand() % 60;
        Time a(m, s);
        T.insert(a);
    }
    return T;
}
void setPrint(Set T)
{
    for (it = T.begin(); it != T.end(); it++)
        cout << (*it) << " | ";
    cout << "\n";
}
Time Average(Set T)
{
    Time a;
    int n = T.size();
    for (it = T.begin(); it != T.end(); it++)
        a = a + (*it);
    return a / n;
}
struct EqualToZ
{
    bool operator()(Time t)
    {
        return (t == Z);
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Set s;
    int n;
    cout << "Введите размер контейнера: ";
    cin >> n;
    s = setMake(n);
    setPrint(s);
    it = max_element(s.begin(), s.end());
    Z = *(it);
    cout << "Максимальный элемент: " << Z << "\n";
    Time el1;
    cout << "Введите новый элемент:\n";
    cout << "> ";
    cin >> el1;
    s.erase(Z);
    s.insert(el1);
    cout << "Замена элемента:\n";
    setPrint(s);
    it = min_element(s.begin(), s.end());
    Z = *(it);
    s.erase(Z);
    setPrint(s);
    cout << "Введите элемент для поиска:\n";
    cout << "> ";
    cin >> Z;
    it = find(s.begin(), s.end(), Z);
    if (it != s.end())
        cout << "> " << *(it) << "\n";
    else
        cout << "Нет такого элемента\n";
    Z = Average(s);
    cout << "Среднее арифметическое:\n";
    cout << "> " << Z << "\n";
    for_each(s.begin(), s.end(), [](const Time& t) {tempS.insert(t + Z); });
    setPrint(tempS);
    return 0;
}