#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Point
{
public:
    string data;
    Point* next;
    Point* pred;

    Point()
    {
        data = "";
        next = nullptr;
        pred = nullptr;
    }

    Point(string d)
    {
        data = d;
        next = nullptr;
        pred = nullptr;
    }

    string ToString()
    {
        return data + " ";
    }
};

Point* MakePoint(string d)
{
    return new Point(d);
}

void AddElementToPointList(Point** head, string data, int position)
{
    Point* newPoint = MakePoint(data);
    if (position == 1) {
        newPoint->next = *head;
        if (*head != NULL) {
            (*head)->pred = newPoint;
        }
     
        *head = newPoint;
    }
    else {
        Point* temp = *head;
        for (int i = 1; i < position - 1; i++) {
            if (temp != NULL) {
               
                temp = temp->next;
            }
            else {
                cout << "Позиция выходит за границы списка." << endl;
                return;
            }
        }
        if (temp != NULL) {
            newPoint->next = temp->next;
            if (temp->next != NULL) {
                temp->next->pred = newPoint;
            }
            temp->next = newPoint;
            newPoint->pred = temp;
        }
        else {
            cout << "Позиция выходит за границы списка." << endl;
            return;
        }
    }
}

Point* MakeList(int size)
{
    srand(time(0));
    Point* beg = nullptr;

    for (int i = 0; i < size; i++)
    {
        string info =to_string(i + 1); // генерация данных для списка
        Point* p = MakePoint(info);
        p->next = beg;
        if (beg != nullptr)
        {
            beg->pred = p;
        }
        beg = p;
    }
    return beg;
}
void DeleteList(Point** head)
{
    Point* current = *head;
    Point* next;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    *head = nullptr; // Голова списка теперь указывает на nullptr, так как список удален из памяти
}


int main()
{
    Point* listHead = MakeList(5);
    setlocale(0, "");
    cout << "Первоначальный список:" << endl;
    // Вывод всех элементов списка для проверки
    Point* temp1 = listHead;
    while (temp1 != nullptr)
    {
        cout << temp1->data << endl;
        temp1 = temp1->next;
    }
    // Получение данных от пользователя
    string newData;
    int position;

    cout << "Введите новый элемент: ";
    cin >> newData;

    cout << "Введите номер позиции: ";
    cin >> position;
    cout << "Cписок после добавления:" << endl;
    // Пример добавления нового элемента на позицию
    AddElementToPointList(&listHead, newData, position);

    // Вывод всех элементов списка для проверки
    Point* temp = listHead;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    DeleteList(&listHead);

    return 0;
}
