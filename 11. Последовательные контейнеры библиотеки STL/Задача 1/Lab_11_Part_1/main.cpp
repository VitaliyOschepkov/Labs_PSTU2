#include <iostream>
#include <locale>
#include <cstdlib>
#include <vector>

using namespace std;

typedef vector<double> Vec; 

Vec vectorMake(int n)
{
    Vec v;
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 100 - 50;
        v.push_back(a); 
    }
    return v;
}
void vectorPrint(Vec v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}
void positionDel(Vec& v, int p)
{
    v.erase(v.begin() + p);
}
void positionAdd(Vec& v, double e, int p)
{
    v.insert(v.begin() + p - 1, e);
}
void beginAdd(Vec& v, double e)
{
    v.insert(v.begin(), e);
}
double Average(Vec v)
{
    double a = 0;
    int n = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        a += v[i];
        cout << a << "\n";
    }
    return a / n;
}
int MaxNom(Vec v)
{
    double m = v[0];
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
    double m = v[0]; 
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
    vector<double> v;
    vector<double>::iterator vi = v.begin();
    int n;
    cout << "Введите размер: ";
    cin >> n;
    v = vectorMake(n);
    vectorPrint(v);
    double Aver = Average(v);
    cout << "Среднее значение: " << Aver << endl;
    int Pos;
    cout << "Введите позицию: ";
    cin >> Pos;
    if (Pos > v.size())
        exit(1);
    positionAdd(v, Aver, Pos);
    vectorPrint(v);
    beginAdd(v, Aver);
    vectorPrint(v);
    return 0;
}