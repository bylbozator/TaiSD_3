#include <iostream>  
#include <cstdlib>
#include <ctime>

using namespace std;

class Point 
{ 
public:
    int data; // информационное поле 
    Point* next; // адресное поле 

public:
    Point() // конструктор без параметров 
    { 
        data = 0; 
        next = nullptr; 
    } 

    Point(int d) // конструктор с параметрами 
    { 
        data = d; 
        next = nullptr; 
    } 

    // перегрузка оператора вывода для удобного вывода данных очередного элемента
    friend ostream& operator<<(ostream& out, const Point& p)
    { 
        out << p.data << " ";
        return out;
    } 

    // создание элемента списка 
    static Point* MakePoint(int d) 
    { 
        Point* p = new Point(d); 
        return p; 
    } 

    // добавление в начало однонаправленного списка 
    static Point* MakeList(int size) 
    { 
        srand(time(0)); // инициализация генератора случайных чисел
        int info = rand() % 11; 
        cout << "Элемент " << info << " добавляется..." << endl; 
        Point* beg = MakePoint(info); // создаем первый элемент 

        for (int i = 1; i < size; i++) 
        { 
            info = rand() % 11; 
            cout << "Элемент " << info << " добавляется..." << endl; 
            // создаем элемент и добавляем в начало списка 
            Point* p = MakePoint(info); 
            p->next = beg; 
            beg = p; 
        } 

        return beg; 
    } 

    // добавление в конец списка 
    static Point* MakeListToEnd(int size) 
    { 
        srand(time(0)); // инициализация генератора случайных чисел
        int info = rand() % 11; 
        cout << "Элемент " << info << " добавляется..." << endl;
        Point* beg = MakePoint(info); // первый элемент 
        Point* r = beg; // переменная хранит адрес конца списка  

        for (int i = 1; i < size; i++) 
        { 
            info = rand() % 11; 
            cout << "Элемент " << info << " добавляется..." << endl;
            // создаем элемент и добавляем в конец списка 
            Point* p = MakePoint(info); 
            r->next = p; 
            r = p; 
        } 

        return beg; 
    } 

    static void ShowList(Point* beg) 
    { 
        // проверка наличия элементов в списке 
        if (beg == nullptr) 
        { 
            cout << "Список пуст" << endl; 
            return; 
        } 

        Point* p = beg; 

        while (p != nullptr) 
        { 
            cout << *p; 
            p = p->next; // переход к следующему элементу 
        } 

        cout << endl; 
    } 

    
    void DeleteLastEvenElement(Point*& beg) {
        Point* p = beg;
        Point* lastEvenElement = nullptr;
        Point* previousElement = nullptr;
        Point* previousToLastEvenElement = nullptr;

       
            // Проходимся по всем элементам списка
            while (p != nullptr) {
                if (p->data % 2 == 0) {
                    lastEvenElement = p;
                    previousToLastEvenElement = previousElement;
                }
                previousElement = p;
                p = p->next;
            }

        // Если последний элемент с четным информационным полем найден
        if (lastEvenElement != nullptr) {
            // Удаляем элемент из списка
            if (previousToLastEvenElement == nullptr) {
                // Если последний элемент был первым элементом списка, ничего не делаем
            }
            else {
                previousToLastEvenElement->next = lastEvenElement->next;
                delete lastEvenElement;
            }
            cout << "Последний четный элемент, удаленный из списка." << endl;
        }
        else {
            cout << "В списке не найдено ни одного четного элемента." << endl;
        }
    }

};

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
    setlocale(0, "");
    int size;
    cout << "Введите размер списка: ";
    cin >> size;
    Point* head = Point::MakeList(size); 
    Point::ShowList(head);

    Point p;
    p.DeleteLastEvenElement(head);
    Point::ShowList(head);

    DeleteList(&head); // Передаем адрес указателя на начало списка
    return 0;
}

