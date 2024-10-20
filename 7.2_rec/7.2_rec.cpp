#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Рекурсивно заповнює рядок випадковими значеннями
void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

// Рекурсивно заповнює всю матрицю рядок за рядком
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

// Рекурсивно виводить рядок матриці
void PrintRow(int** a, const int rowNo, const int n, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

// Рекурсивно виводить всю матрицю
void PrintRows(int** a, const int k, const int n, int rowNo) {
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
    else
        cout << endl;
}

// Рекурсивно знаходить індекси мінімального та максимального елементів у рядку
void FindMinMaxInRow(int* row, const int n, int colNo, int& minIdx, int& maxIdx) {
    if (row[colNo] < row[minIdx])
        minIdx = colNo;
    if (row[colNo] > row[maxIdx])
        maxIdx = colNo;

    if (colNo < n - 1)
        FindMinMaxInRow(row, n, colNo + 1, minIdx, maxIdx);
}

// Рекурсивно змінює місцями мінімальний і максимальний елементи в рядку
void SwapMinMaxInRow(int* row, int minIdx, int maxIdx) {
    int temp = row[minIdx];
    row[minIdx] = row[maxIdx];
    row[maxIdx] = temp;
}

// Рекурсивно обробляє кожен рядок: знаходить і змінює місцями мінімальний і максимальний елементи
void ProcessRows(int** a, const int k, const int n, int rowNo) {
    int minIdx = 0, maxIdx = 0;
    FindMinMaxInRow(a[rowNo], n, 1, minIdx, maxIdx);

    if (minIdx != maxIdx)  // Якщо мінімальний і максимальний різні
        SwapMinMaxInRow(a[rowNo], minIdx, maxIdx);

    if (rowNo < k - 1)
        ProcessRows(a, k, n, rowNo + 1);
}

int main() {
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int Low = -90, High = 90;  // Межі для генерації випадкових чисел

    // Створення динамічної матриці
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Створення та виведення початкової матриці
    CreateRows(a, k, n, Low, High, 0);
    cout << "Початкова матриця:" << endl;
    PrintRows(a, k, n, 0);

    // Обробка матриці: зміна місцями мінімальних та максимальних елементів у кожному рядку
    ProcessRows(a, k, n, 0);

    // Виведення модифікованої матриці
    cout << "Модифікована матриця:" << endl;
    PrintRows(a, k, n, 0);

    // Очищення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
