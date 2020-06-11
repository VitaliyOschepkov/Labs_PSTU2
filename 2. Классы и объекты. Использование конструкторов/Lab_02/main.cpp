#include <iostream>
#include <string>
#include <cstdio>
#include <locale>
#include "student.h"

using namespace std;

Student makeStudent()
{
    string f,g;
    float a;
    cout << "\nВведите ФИО: ";
    getline(cin, f);
    cout << "\nВведите группу: ";
    getline(cin, g);
    cout << "\nВведите средний балл: ";
    cin >> a;
    cout << "\n";
    Student s(f, g, a);
    return s;
}
void printStudent(Student s)
{
    s.Show();
}

int main()
{
    setlocale(LC_ALL, "rus");
    Student s1;
    s1.Show();
    Student s2("Ivanov Ivan Ivanovich", "Alpha", 33);
    s2.Show();
    Student s3 = s2;
    s3.Show();
    s3.setFullname("Petrov Petr Petrovich");
    s3.setGroup("Betta");
    s3.setAveragemark(66);
    printStudent(s3);
    s1 = makeStudent();
    s1.Show();
    string ff;
    string gg;
    float aa;
    ff = s2.getFullname();
    gg = s2.getGroup();
    aa = s2.getAveragemark();
    cout << "ФИО: " << ff;
    cout << "\nГруппа: " << gg;
    cout << "\nСредний балл: " << aa << "\n" << "\n";
    return 0;
}