#include <iostream>
#include <locale>
#include "Tree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Tree* root = NULL;
    int c;
    do
    {
        cout << "\n1. Создать новое дерево";
        cout << "\n2. Добавить элемент";
        cout << "\n3. Просмотр дерева";
        cout << "\n4. Подсчет количества элементов с заданным ключем";
        cout << "\n0. Выход";
        cout << "\n> ";
        cin >> c;
        switch (c)
        {
        case 1:
            root = Generate();
            break;
        case 2:
            root = elementAdd(root);
            break;
        case 3:
            Print(root, Height(root));
            break;
        case 4:
            char key;
            int count = 0;
            cout << "\nВведите ключ поиска" ;
            cout << "\n> ";
            cin >> key;
            Count(root, count, key);
            cout << "Количество найденых элементов равно: " << count << "\n";
            break;
        }
    } while (c != 0);
    return 0;
}