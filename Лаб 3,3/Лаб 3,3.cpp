#include <iostream>
#include <algorithm>
using namespace std;
// Структура для узла дерева
struct Node {
    double data;
    Node* left;
    Node* right;
};
// Функция для создания нового узла дерева
Node* Create_Node(double data) {
    Node* newNode = new Node();
    if (!newNode) {
        cerr << "Ошибка при выделении памяти!" << endl;
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Функция для построения идеально сбалансированного бинарного дерева
Node* Build_Balanced_Tree(double arr[], double start, double end) {
    // Проверка базового случая
    if (start > end) {
        return NULL;
    }
    // Находим середину массива и делаем её корнем нового узла дерева
    int mid = (start + end) / 2;
    Node* root = Create_Node(arr[mid]);
    // Рекурсивно строим левое и правое поддерево
    root->left = Build_Balanced_Tree(arr, start, mid - 1);
    root->right = Build_Balanced_Tree(arr, mid + 1, end);
    return root;
}
// Функция для печати дерева (сверху вниз, справа налево)
void Print_Tree(Node* root, int space) {
    const int INDENTATION = 4;
    if (root == NULL) {
        return;
    }
    space += INDENTATION;
    // Вывод правого поддерева
    Print_Tree(root->right, space);
    // Вывод текущего узла
    for (int i = INDENTATION; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    // Вывод левого поддерева
    Print_Tree(root->left, space);
}
// Функция для вызова из main
void Print_Tree(Node* root) {
    Print_Tree(root, 0);
}

int Height(Node* root) {
    if (root == nullptr) {
        return -1; // Пустое дерево имеет высоту -1
    }
    else {
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        return 1 + max(leftHeight, rightHeight); // Высота текущего узла - это максимальная высота его левого и правого поддеревьев плюс 1
    }
}


int main() {
    setlocale(0, "");
    int n;
    double maxElement = DBL_MIN;
    cout << "Введите количество элементов: ";
    // Запрашиваем у пользователя количество элементов, пока не получим положительное число
    while (!(cin >> n) || n <= 0) {
        cin.clear(); // Сбрасываем флаги ошибок ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер до символа новой строки
        cerr << "Ошибка ввода. Пожалуйста, введите положительное целое число.\n";
    }
    double* arr = new double[n];
    cout << "Введите элементы: ";
    // Запрашиваем у пользователя элементы массива
    for (int i = 0; i < n; i++) {
        while (!(cin >> arr[i])) {
            cin.clear(); // Сбрасываем флаги ошибок ввода
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер до символа новой строки
            cerr << "Ошибка ввода. Пожалуйста, введите число.\n";
        }
        
    }
    sort(arr, arr + n); // Сортируем массив
    // Строим идеально сбалансированное бинарное дерево
    Node* root = Build_Balanced_Tree(arr, 0, n - 1);
    // Выводим построенное дерево
    cout << "Идеально сбалансированное бинарное дерево:\n";
    Print_Tree(root, 0);
 
    int treeHeight = Height(root);
    cout << "Высота дерева: " << treeHeight << endl;

    return 0;
}
