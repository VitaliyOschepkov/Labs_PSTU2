#include <iostream>
#include <locale>
#include <list>
#include "Temperature.h"
#include "FileWork.h"
#include "List.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    List mList;
    List rList;
    Temperature key, el;
    char file_name[30];
    char a;
    int num, k, c;
    do
    {
        cout << "\n1. Создать новую базу данных";
        cout << "\n2. Открыть сушествующую базу данных";
        cout << "\n3. Просмотр содержимого";
        cout << "\n4. Удаление элемента";
        cout << "\n5. Редактирование элемента";
        cout << "\n6. Добавление нового элемента";
        cout << "\n7. Расчетные действия";
        cout << "\n8. Сохранить изменения";
        cout << "\n0. Выход";
        cout << "\n> ";
        cin >> c;
        switch (c)
        {
        case 1:    
            cout << "Введите имя файла: ";
            cin >> file_name;
            k = fileMake(file_name, mList);
            if (k < 0)
                cout << "Невозможно создать файл";
            break;
        case 2:    
            cout << "Введите имя открываемого файла: ";
            cin >> file_name;
            k = fileOpen(file_name, mList);
            if (k == 0)
                cout << "Файл пуст\n";
            if (k < 0)
                cout << "Невозможно прочитать файл\n";
            break;
        case 3:   
            listPrint(mList);
            break;
        case 4:   
            int sm4;
            do
            {
                cout << "\n1. Удаление элемента по номеру";
                cout << "\n2. Удаление элемента по ключу";
                cout << "\n3. Отменить последнюю операцию удаления";
                cout << "\n0. Назад";
                cout << "\n> ";
                cin >> sm4;
                switch (sm4)
                {
                case 1:
                    Reserve(mList, rList);
                    cout << "\nвведите номер";
                    cout << "\n> ";
                    cin >> num;
                    positionDel(mList, num);
                    break;
                case 2:
                    Reserve(mList, rList);
                    cout << "\nвведите ключ";
                    cout << "\n> ";
                    cin >> key;
                    delByKey(mList, key);
                    break;
                case 3:
                    cout << "\nОтменить последнюю операцию удаления?";
                    cout << "\n> ";
                    cin >> a;
                    if (a == 'Y' || a == 'y')
                    {
                        Recover(mList, rList);
                        cout << "Удаление отменено\n";
                    }
                    break;
                }
            } while (sm4 != 0);

            if (sm4 == 0) operationDel(mList, rList);
            break;
        case 5:   
            int sm5;
            do
            {
                cout << "\n1. Редактирование элемента по номеру";
                cout << "\n2. Редактирование элемента по ключу";
                cout << "\n3. Отменить последнюю операцию редактирования";
                cout << "\n0. Назад";
                cout << "\n> ";
                cin >> sm5;
                switch (sm5)
                {
                case 1:
                    Reserve(mList, rList);
                    cout << "\nвведите номер";
                    cout << "\n> ";
                    cin >> num;
                    cout << "\nвведите новый элемент";
                    cout << "\n> ";
                    cin >> el;
                    positionCheange(mList, el, num);
                    break;
                case 2:
                    Reserve(mList, rList);
                    cout << "\nвведите ключ";
                    cout << "\n> ";
                    cin >> key;
                    cout << "\nвведите новый элемент";
                    cout << "\n> ";
                    cin >> el;
                    cheangeByKey(mList, el, key);
                    break;
                case 3:
                    cout << "\nОтменить последнюю операцию редактирования?";
                    cout << "\n> ";
                    cin >> a;
                    if (a == 'Y' || a == 'y')
                    {
                        Recover(mList, rList);
                        cout << "Редактирование отменено\n";
                    }
                    break;
                }
            } while (sm5 != 0);
            break;

        case 6:    
            int sm6;
            do
            {
                cout << "\n1. Добавление элемента в начало";
                cout << "\n2. Добавление элемента в конец";
                cout << "\n3. Добавление элемента в позицию с указанным номером";
                cout << "\n3. Отменить последнюю операцию добавления";
                cout << "\n0. Назад";
                cout << "\n> ";
                cin >> sm6;
                switch (sm6)
                {
                case 1:
                    Reserve(mList, rList);
                    cout << "\nвведите новый элемент";
                    cout << "\n> ";
                    cin >> el;
                    beginAdd(mList, el);
                    break;
                case 2:
                    Reserve(mList, rList);
                    cout << "\nвведите новый элемент";
                    cout << "\n> ";
                    cin >> el;
                    endAdd(mList, el);
                    break;
                case 3:
                    Reserve(mList, rList);
                    cout << "\nвведите номер";
                    cout << "\n> ";
                    cin >> num;
                    cout << "\nвведите новый элемент";
                    cout << "\n> ";
                    cin >> el;
                    positionAdd(mList, el, num);
                    break;
                case 4:
                    cout << "\nОтменить последнюю операцию добавления?";
                    cout << "\n> ";
                    cin >> a;
                    if (a == 'Y' || a == 'y')
                    {
                        Recover(mList, rList);
                        cout << "Добавление отменено\n";
                    }
                    break;
                }
            } while (sm6 != 0);
            break;
        case 7:   
            int sm7;
            do
            {
                cout << "\n1. Вывести дни в которые температура поднималась выше средней";
                cout << "\n2. Самый длинный отрезок между днями с отрицательной температурой";
                cout << "\n0. Назад";
                cout << "\n> ";
                cin >> sm7;
                switch (sm7)
                {
                case 1:
                    AverageByDay(mList);
                    break;
                case 2:
                    cout << "Самый длинный отрезок: " << minimalTempRange(mList) << "\n";
                    break;
                }
            } while (sm7 != 0);
            break;
        case 8:    
            k = fileSave(file_name, mList);
            break;
        }
    } while (c != 0);
    return 0;
}