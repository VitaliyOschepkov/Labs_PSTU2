#include <iostream>
#include <locale>
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include "Event.h"
#include "Dialog.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Dialog d;
    d.Execute();
    Person* a = new Person;
    a->Input();
    a->Show();
    Student* b = new Student;
    b->Input();
    b->Show();
    Vector v(10);
    Object* p = a;
    v.Add(p);
    v.Show();
    v.Del();
    v.Add();
    v.Show();
    v.Del();
    cout << "\nРазмер вектора v: " << v();
    return 0;
}