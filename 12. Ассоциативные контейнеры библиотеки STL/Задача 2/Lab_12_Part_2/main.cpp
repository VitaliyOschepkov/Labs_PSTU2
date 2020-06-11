#include <iostream>
#include <locale>
#include <map>
#include "Time.h"

using namespace std;

typedef multimap<int, Time> Map;
typedef Map::iterator it;

Map mapMake(int n)
{
    Map t;
    for (int i = 0; i < n; i++)
    {
        int m = rand() % 60;
        int s = rand() % 60;
        Time a(m, s);
        t.insert(make_pair(i, a));
    }
    return t;
}
void mapPrint(Map m)
{
    for (it i = m.begin(); i != m.end(); i++)   
        cout << (*i).first << " | " << (*i).second << " | ";
    
    cout << "\n";
}
void positionDel(Map& m, int p)
{
    m.erase(p);
}
void positionAdd(Map& m, Time e, int p)
{
    m.emplace(p, e);
}
void endAdd(Map& m, Time e)
{
    it i = m.end();
    --i;
    m.insert(make_pair((*i).first + 1, e));
}
void beginAdd(Map& m, Time e)
{
    Map t;
    t.emplace(0, e);
    for (it i = m.begin(); i != m.end(); i++)    
        endAdd(t, (*i).second);
    
    m = t;
}
void multimapBeginAdd(Map& m, Time e)
{
    m.emplace(0, e);
}
Time Average(Map m)
{
    Time a;
    int n = m.size();
    for (it i = m.begin(); i != m.end(); i++)    
        a = a + (*i).second;
    
    return a / n;
}
void elementAdd(Map& m, Time a)
{
    for (it i = m.begin(); i != m.end(); i++)    
        (*i).second = (*i).second + a;
    
}
int MaxKey(Map m)
{
    it i = m.begin();
    Time max = (*i).second;
    int key = (*i).first;
    for (i = m.begin(); i != m.end(); i++)
    {
        if (max < (*i).second)
        {
            max = (*i).second;
            key = (*i).first;
        }
    }
    return key;
}
Time MaxElement(Map m)
{
    Time max;
    for (it i = m.begin(); i != m.end(); i++)
    {
        if (max < (*i).second)
            max = (*i).second;
    }
    return max;
}
int MinKey(Map m)
{
    it i = m.begin();
    Time min = (*i).second;
    int key;
    for (i = m.begin(); i != m.end(); i++)
    {
        if (min > (*i).second)
        {
            min = (*i).second;
            key = (*i).first;
        }
    }
    return key;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Map m1, m2;
    int n;
    cout << "Введите размер контейнера:\n";
    cout << "> ";
    cin >> n;
    m1 = mapMake(n);
    cout << "> | ";
    mapPrint(m1);
    int findMin = MinKey(m1);
    positionDel(m1, findMin);
    cout << "> | ";
    mapPrint(m1);
    return 0;
}