#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <locale>

using namespace std;
const int MAXSIZE = 200;

class TableEntry
{
public:
    string key;
    string group;
    int rating;
    TableEntry(string key, string group, int rating)
    {
        this->key = key;
        this->group = group;
        this->rating = rating;
    }
};
class MapTable
{
private:
    TableEntry** t;
public:
    MapTable();
    int Function(string key);
    void Add(string key, string group, int rating);
    void Generate(int size);
    void SerchByKey(string key);
    void SerchByIndex(int index);
    void EditByIndex(int index);
    void EditByKey(string key);
    void DelByIndex(int index);
    void DelByKey(string key);
    ~MapTable();
    void Show();
    int Collision();
};
MapTable::MapTable()
{
    t = new TableEntry * [MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++)
        t[i] = NULL;
}
int MapTable::Function(string key)
{
    int ascii = 0;
    for (int i = 0, p = 1; i < key.size(); i++, p++)
        ascii += key[i] * p;
    return ascii % MAXSIZE;
}
void MapTable::Add(string key, string group, int rating)
{
    int nom = Function(key);
    while (t[nom] != NULL && t[nom]->key != key)
        nom++;
    if (t[nom] != NULL)
        delete t[nom];
    t[nom] = new TableEntry(key, group, rating);
}
void MapTable::Generate(int size)
{
    if (size > MAXSIZE)
    {
        cout << "�������� ������������ ������\n";
        return;
    }
    if (size < 0)
    {
        cout << "������ ����� �� ���������\n";
        return;
    }
    vector<string> names = {"Oliver", "Jack", "Harry", "Jacob", "Charlie", "Thomas", "George", "Oscar", "James", "William"};
    vector<string> surnames = {"Smith", "Jones", "Taylor", "Davies", "Evans", "Johnson", "Roberts", "Robinson", "Thompson", "Green"};
    vector<string> patronymics = {"Adamson", "Barson", "Hobson", "Wilson", "Fennel", "Coleson", "Jackson", "Iveson", "Tennyson", "Garrison"};
    vector<string> groups = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        string key = { names[rand() % 10] + ' ' + surnames[rand() % 10] + ' ' + patronymics[rand() % 10] };
        string group = { groups[rand() % 9] };
        int rating = rand() % 100;
        Add(key, group, rating);
    }
}
void MapTable::SerchByKey(string key)
{
    int nom = Function(key);
    while (t[nom] != NULL && t[nom]->key != key)
        nom++;
    if (t[nom] != NULL)
    {
        cout << "���: " << t[nom]->key ;
        cout << "\n������: " << t[nom]->group ;
        cout << "\n�������: " << t[nom]->rating << "\n";
    }
    else
        cout << "��� ������ ��������\n";
}
void MapTable::SerchByIndex(int index)
{
    if (t[index] != NULL)
    {
        cout << "���: " << t[index]->key ;
        cout << "\n������: " << t[index]->group ;
        cout << "\n�������: " << t[index]->rating << "\n";
    }
    else
        cout << "��� ������ ��������\n";
}
void MapTable::EditByIndex(int index)
{
    string g;
    int r;
    if (t[index] != NULL)
    {
        cout << "������� ����� �������";
        cout << "\n������ >";
        cin >> g;
        cout << "������� >";
        cin >> r;
        t[index]->group = g;
        t[index]->rating = r;
    }
    else
        cout << "��� �������� � �������� ��������\n";
}
void MapTable::EditByKey(string key)
{
    string new_key;
    string g;
    int r;
    int nom = Function(key);

    while (t[nom] != NULL && t[nom]->key != key)
        nom++;
    if (t[nom] != NULL)
    {
        cout << "������� ����� �������";
        cout << "\n������ >";
        cin >> g;
        cout << "������� >";
        cin >> r;
        t[nom]->group = g;
        t[nom]->rating = r;
    }
    else
        cout << "��� �������� � �������� ������\n";
}
void MapTable::DelByIndex(int index)
{
    if (t[index] != NULL)
    {
        delete t[index];
        t[index] = NULL;
        cout << "������� ������\n";
    }
    else
        cout << "��� �������� � �������� ��������\n";
}
void MapTable::DelByKey(string key)
{
    int nom = Function(key);
    while (t[nom] != NULL && t[nom]->key != key)
        nom++;
    if (t[nom] != NULL)
    {
        delete t[nom];
        t[nom] = NULL;
        cout << "������� ������\n";
    }
    else
        cout << "��� �������� � �������� ������\n";
}
MapTable::~MapTable()
{

}

void MapTable::Show()
{
    cout << "\n" << setw(0) << "���";
    cout << setw(15) << "���";
    cout << setw(23) << "������";
    cout << setw(13) << "�������\n";
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (t[i] != NULL)
        {
            int nom = Function(t[i]->key);
            cout << setw(4) << nom << setw(30);
            cout << t[i]->key << setw(10);
            cout << t[i]->group << setw(10);
            cout << t[i]->rating << "\n";
        }
    }
}
int MapTable::Collision()
{
    int c = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (t[i] != NULL)
        {
            int nom = Function(t[i]->key);
            if (i != nom)
                c++;
        }
    }
    return c;
}