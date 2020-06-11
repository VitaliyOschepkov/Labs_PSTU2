#include <iostream>
#include <locale>
#include <vector>
#include <stack>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef vector<Time> Vec;
typedef stack<Time> St;
Vec::iterator it;
Time Z;

St stackMake(int n)
{
    St S;
    for (int i = 0; i < n; i++)
    {
        int m = rand() % 60;
        int s = rand() % 60;
        Time a(m, s);
        S.push(a);
    }
    return S;
}
Vec stackToVector(St S)
{
    Vec v;
    while (!S.empty())
    {
        v.push_back(S.top());
        S.pop();
    }
    return v;
}
St vectorToStack(Vec v)
{
    St S;
    for (int i = 0; i < v.size(); i++)
        S.push(v[i]);
    return S;
}
void stackPrint(St& S)
{
    Vec v = stackToVector(S);
    while (!S.empty())
    {
        cout << S.top() << " | ";
        S.pop();
    }
    cout << "\n";
    S = vectorToStack(v);
}
Time Average(St S)
{
    Vec v = stackToVector(S);
    Time a;
    int n = 0;
    do
    {
        a = a + S.top();
        S.pop();
        n++;
    } while (!S.empty());
    S = vectorToStack(v);
    return a / n;
}
void averageAdd(Time& t)
{
    t = t + Z;
}
struct EqualToZ {
    bool operator ()(Time t) {
        if (t == Z) return true;
        else return false;
    }
};

struct Compare_less {
    bool operator ()(Time t1, Time t2) {
        if (t1 > t2) return true;
        else return false;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Vec v;
    St S;
    int n;
    cout << "Введите размер стека: ";
    cin >> n;
    S = stackMake(n);
    stackPrint(S);
    v = stackToVector(S);
    it = max_element(v.begin(), v.end());
    Z = *(it);
    Time el1;
    cout << "Введите новый элемент:\n";
    cout << "> ";
    cin >> el1;
    replace_if(v.begin(), v.end(), EqualToZ(), el1);
    S = vectorToStack(v);
    stackPrint(S);
    Vec vv(v.size() - 1);
    it = min_element(v.begin(), v.end());
    Z = *(it);
    remove_copy(v.begin(), v.end(), vv.begin(), Z);
    S = vectorToStack(vv);
    stackPrint(S);
    cout << "Введите элемент для поиска:\n";
    cout << "> ";
    cin >> Z;
    v = stackToVector(S);
    it = find(v.begin(), v.end(), Z);
    cout << "Найденный элемент: " << (*it) << "\n";
    it = v.begin();
    S = vectorToStack(v);
    stackPrint(S);
    Z = Average(S);
    v = stackToVector(S);
    cout << "Среднее арифметическое:\n";
    cout << "> " << Z << "\n";
    for_each(v.begin(), v.end(), averageAdd);
    S = vectorToStack(v);
    stackPrint(S);
    return 0;
}