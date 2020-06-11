#include <iostream>
#include <locale>
#include <map>

using namespace std;

typedef multimap<int, double> Map;
typedef Map::iterator it;

Map mapMake(int n)
{
    Map m;
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 100 - 50;
        m.insert(make_pair(i, a));
    }
    return m;
}
void mapPrint(Map m)
{
    for (it i = m.begin(); i != m.end(); i++)  
        cout << (*i).first << " : " << (*i).second << " | ";
    
    cout << "\n";
}
void positionDel(Map& m, double p)
{
    m.erase(p);
}
void positionAdd(Map& m, double e, double p)
{
    m.emplace(p, e);
}
void endAdd(Map& m, double e)
{
    it i = m.end();
    --i;
    m.insert(make_pair((*i).first + 1, e));
}
void beginAdd(Map& m, double e)
{
    Map t;
    t.emplace(0, e);
    for (it i = m.begin(); i != m.end(); i++)   
        endAdd(t, (*i).second);
    
    m = t;
}
void multimapBeginAdd(Map& m, double e)
{
    m.emplace(0, e);
}
double Average(Map m)
{
    double a = 0;
    int n = m.size();
    for (it i = m.begin(); i != m.end(); i++)   
        a += (*i).second;
    
    return a / n;
}
void elementAdd(Map& m, double a)
{ 
    for (it i = m.begin(); i != m.end(); i++)   
        (*i).second += a;
    
}
int MaxKey(Map m)
{
    it i = m.begin();
    double max = (*i).second;
    int key = (*i).first;
    while (i != m.end())
    {
        if (max < (*i).second)
        {
            max = (*i).second;
            key = (*i).first;
        }
        i++; 
    }
    cout << "max key: " << key << " : " << max;
    return key;
}
double MaxElement(Map m)
{
    double max = 0;
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
    double MinKey = (*i).second;
    int key = (*i).first;
    while (i != m.end())
    {
        if (MinKey > (*i).second)
        {
            MinKey = (*i).second;
            key = (*i).first;
        }
        i++; 
    }
    return key;
}


int main()
{
    setlocale(LC_ALL, "rus");
    Map m1, m2;
    double max;
    int n;
    cout << "Введите размер контейнера:\n";
    cout << "> ";
    cin >> n;
    m1 = mapMake(n);
    cout << "> | ";
    mapPrint(m1);
    max = MaxElement(m1); 
    cout << "\n> " << max << "\n";
    m2 = m1;
    multimapBeginAdd(m2, max);
    cout << "\n> | ";
    mapPrint(m2);
    beginAdd(m1, max);
    cout << "\n> | ";
    mapPrint(m1);
    return 0;
}