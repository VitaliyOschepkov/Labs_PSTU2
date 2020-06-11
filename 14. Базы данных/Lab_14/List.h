#pragma once
#include <iostream>
#include <iomanip>
#include <list>
#include "Temperature.h"

using namespace std;

typedef list<Temperature> List;
typedef List::iterator Lit;

List listMake(int n)
{
    List l;
    for (int i = 0; i < n; i++)
    {
        int d = rand() % 30;
        int t = rand() % 60 - 30;
        Temperature a(d, t);
        l.push_back(a);
    }
    return l;
}
void listPrint(List l)
{
    cout << "| Дата      : Температура |\n";
    for (Lit i = l.begin(); i != l.end(); i++)
        cout << (*i);
    cout << "\n";
}
void Reserve(List l, List& r)
{
        r.clear();
        for (Lit i = l.begin(); i != l.end(); i++)
            r.push_back((*i));
}
void Recover(List& l, List r)
{
    l.clear();
    for (Lit i = r.begin(); i != r.end(); i++)
        l.push_back((*i));
}
void positionDel(List& l, int p)
{
    if (p > l.size())
    {
        cout << "Недопустимая позиция\n";
        return;
    }
    Lit i = l.begin();
    while (--p)
        i++;
    (*i).set_del(true);
}
void markedDel(List& l)
{
    List t;
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        if (!(*i).get_del())
            t.push_back((*i));
    }
    l = t;
}
int markedCount(List l)
{
    int c = 0;
    for (Lit i = l.begin(); i != l.end(); i++)
        if ((*i).get_del())
            c++;
    return c;
}
void operationDel(List& l, List& b)
{
    if (markedCount(l) > (l.size() / 2))
    {
        markedDel(l);
        cout << "Помеченые записи удалены\n";
    }
    b.clear();
    b = l;
}
void delByKey(List& l, Temperature k)
{
    Lit i = l.begin();
    while ((*i) != k)
    {
        i++;
        if (i == l.end())
        {
            cout << "Ключ не найден\n";
            return;
        }
    }
    (*i).set_del(true);
}
void positionAdd(List& l, Temperature e, int p)
{
    Lit i = l.begin();
    while (p--)
        i++;
    l.emplace(i, e);
}
void positionCheange(List& l, Temperature e, int p)
{
    Lit i = l.begin();
    while (p--)
        i++;
    (*i) = e;
}
void cheangeByKey(List& l, Temperature e, Temperature k)
{
    for (Lit i = l.begin(); i != l.end(); i++)
        if ((*i) == k) (*i) = e;
}
void endAdd(List& l, Temperature e)
{
    l.push_back(e);
}
void beginAdd(List& l, Temperature e)
{
    l.push_front(e);
}
Temperature Average(List l)
{
    Temperature a;
    int n = l.size() - markedCount(l);
    for (Lit i = l.begin(); i != l.end(); i++)
        a = a + (*i);
    return a / n;
}
void AverageByDay(List l)
{
    List t;
    Temperature a = Average(l);
    cout << "Среднее значение температуры" << a.get_temp() << "\n";
    for (Lit i = l.begin(); i != l.end(); i++)
        if ((*i) > a)
            t.push_back((*i));
    listPrint(t);
}
int minimalTempRange(List l)
{
    list<int> lt;
    list<int>::iterator it;
    int r = 0;
    int mr = 0;
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        if ((*i) > 0)
        {
            if (!(*i).get_del())
                r++;
            lt.push_back(r);
        }
        else
            r = 0;
    }
    for (it = lt.begin(); it != lt.end(); it++)
    {
        if (mr < (*it))
            mr = (*it);
    }
    return mr;
}
void elementAdd(List& l, Temperature e)
{
    for (Lit i = l.begin(); i != l.end(); i++)
        (*i) = (*i) + e;
}