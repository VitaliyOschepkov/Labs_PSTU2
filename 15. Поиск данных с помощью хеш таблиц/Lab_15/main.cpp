#include <iostream>
#include <string>
#include <locale>
#include "Table.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    MapTable t;
    string key, gr;
    int r, i, c;
    do
    {
        cout << "\n1. Создать и заполнить таблицу";
        cout << "\n2. Просмотр таблицы";
        cout << "\n4. Отредактировать элемент";
        cout << "\n5. Удалить элемент";
        cout << "\n6. Подсчитать колличество коллизий";
        cout << "\n0. Выход";
        cout << "\n> ";
        cin >> c;
        cin.get();  
        switch (c)
        {
        case 1:     
            int s;
            cout << "\nЗадайте размер таблицы";
            cout << "\n> ";
            cin >> s;
            t.Generate(s);
            break;
        case 2:   
            t.Show();
            break;
        case 4:   
            int sm4;
            do
            {
                cout << "\n1. Редактирование элемента по индексу";
                cout << "\n2. Редактирование элемента по ключу";
                cout << "\n0. Назад";
                cout << "\n> ";
                cin >> sm4;
                cin.get();
                switch (sm4)
                {
                case 1:
                    cout << "\nВведите индекс";
                    cout << "\n> ";
                    cin >> i;
                    t.EditByIndex(i);
                    break;
                case 2:
                    cout << "\nВведите ключ";
                    cout << "\n> ";
                    getline(cin, key);
                    t.EditByKey(key);
                    break;
                }
            } while (sm4 != 0);
            break;
        case 5:   
            int sm5;
            do
            {
                cout << "\n1. Удаление элемента по индексу";
                cout << "\n2. Удаление элемента по ключу";
                cout << "\n0. Назад";
                cout << "\n> ";
                cin >> sm5;
                cin.get();
                switch (sm5)
                {
                case 1:
                    cout << "\nВведите индекс";
                    cout << "\n> ";
                    cin >> i;
                    t.DelByIndex(i);
                    break;

                case 2:
                    cout << "\nВведите ключ";
                    cout << "\n> ";
                    getline(cin, key);
                    t.DelByKey(key);
                    break;
                }
            } while (sm5 != 0);
            break;

        case 6:    
            cout << "Колличество коллизий равно: " << t.Collision() << "\n";
            break;
        }
    } while (c != 0);
    return 0;
}