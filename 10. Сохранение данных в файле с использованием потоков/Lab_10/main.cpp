#include <iostream>
#include <locale>
#include "Time.h"
#include "FileWork.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Time t1, t2;
    Time constT(1, 30);
    int counter, c;
    char fileName[30];
    do
    {
        cout << "\n1. Создать";
        cout << "\n2. Прочитать";
        cout << "\n3. Удалить элемент";
        cout << "\n4. Добавление элемента";
        cout << "\n5. Изменить элемент";
        cout << "\n6. Удаление элементов соответствующих заданному значению";
        cout << "\n7. Увеличение всех элементов с заданным значением на 1:30";
        cout << "\n8. Добавить K записей после элемента с заданным номером";
        cout << "\n0. Выход";
        cout << "\n> ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Введите имя файла: ";
            cin >> fileName;
            counter = fileMake(fileName);
            if (counter < 0)
                cout << "Невозможно создать файл";
            break;
        case 2:
            cout << "Введите имя файла: ";
            cin >> fileName;
            counter = filePrint(fileName);
            if (counter == 0)
                cout << "Файл пуст\n";
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            break;
        case 3:
            cout << "Введите имя файла: ";
            cin >> fileName;
            int nom;
            cout << "Введите номер элемента для удаления: ";
            cin >> nom;
            counter = fileDel(fileName, nom);
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            counter = filePrint(fileName);
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            break;
        case 4:
            cout << "Введите имя файла: ";
            cin >> fileName;
            int n1;
            cout << "Введите номер элемента для добавления: ";
            cin >> n1;
            cout << "Новый элемент: \n";
            cin >> t1;
            counter = fileAdd(fileName, n1, t1);
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            if (counter == 0)
                counter = addToEnd(fileName, t1);
            break;
        case 5:
            cout << "Введите имя файла: ";
            cin >> fileName;
            int n2;
            cout << "Номер элемента: ";
            cin >> n2;
            cout << "Новый элемент: ";
            cin >> t2;
            counter = fileCheange(fileName, n2, t2);
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            if (counter == 0)
                cout << "Нет такой записи\n";
            break;
        case 6:
            cout << "Введите имя файла: ";
            cin >> fileName;
            counter = delCompare(fileName);
            if (counter == 0)
                cout << "Файл пуст\n";
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            break;
        case 7:
            cout << "Введите имя файла: ";
            cin >> fileName;
            counter = addTime(fileName, constT);
            if (counter == 0)
                cout << "Файл пуст\n";
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            break;
        case 8:
            cout << "Введите имя файла: ";
            cin >> fileName;
            int k2;
            cout << "Номер элемента после которого добавить: ";
            cin >> k2;
            counter = addAfter(fileName, k2);
            if (counter == 0)
                cout << "Нет такой записи\n";
            if (counter < 0)
                cout << "Невозможно прочитать файл\n";
            break;
        }
    } while (c != 0);
    return 0;
}