#include <iostream>
#include <locale>
using namespace std;

int* arithmeticProgression(int N, int A, int D) {
    int* progression = new int[N];
    for (int i = 0; i < N; i++) {
        progression[i] = A + i * D;
    }
    return progression;
}

int* sumProgression(int N, int A, int B) {
    int* progression = new int[N];
    progression[0] = A;
    progression[1] = B;

    for (int i = 2; i < N; i++) {
        progression[i] = 0;
        for (int j = 0; j < i; j++) {
            progression[i] += progression[j];
        }
    }
    return progression;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // ------------------------------ ЗАДАЧА 1 ------------------------------
    cout << "------------------------------ ЗАДАЧА 1 ------------------------------" << endl;
    cout << "Дано целое число N (N > 1), а также первый член A и разность D арифметической прогрессии." << endl;
    cout << "Сформировать и вывести массив размера N, содержащий N первых членов данной прогрессии." << endl;
    cout << "----------------------------------------------------------------------" << endl;
    int N, A, D;
    cout << "Введите количество элементов N (больше 1): ";
    cin >> N;
    while (N <= 1) {
        cout << "Ошибка: N должно быть больше 1. Повторите ввод: ";
        cin >> N;
    }
    cout << "Введите первый элемент A: ";
    cin >> A;
    cout << "Введите разность D: ";
    cin >> D;

    int* progression1 = arithmeticProgression(N, A, D);
    cout << "Арифметическая прогрессия: ";
    printArray(progression1, N);
    delete[] progression1; // Освобождение памяти

    // ------------------------------ ЗАДАЧА 2 ------------------------------
    cout << "\n------------------------------ ЗАДАЧА 2 ------------------------------" << endl;
    cout << "Дано целое число N (N > 2), а также числа A и B." << endl;
    cout << "Сформировать и вывести целочисленный массив размера N," << endl;
    cout << "первый элемент которого равен A, второй равен B," << endl;
    cout << "а каждый последующий элемент равен сумме всех предыдущих." << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Введите количество элементов N (больше 2): ";
    int B;
    cin >> N;
    while (N <= 2) {
        cout << "Ошибка: N должно быть больше 2. Повторите ввод: ";
        cin >> N;
    }
    cout << "Введите первый элемент A: ";
    cin >> A;
    cout << "Введите второй элемент B: ";
    cin >> B;

    int* progression2 = sumProgression(N, A, B);
    cout << "Сформированный массив: ";
    printArray(progression2, N);
    delete[] progression2; // Освобождение памяти

    return 0;
}
