#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>

// Функция для перемешивания массива
void shuffleArray(std::vector<int>& arr) {
    std::random_device rd; // Источник энтропии
    std::mt19937 gen(rd()); // Генератор случайных чисел
    std::shuffle(arr.begin(), arr.end(), gen); // Перемешивание
}

// Тестовая функция для проверки корректности
void runTests() {
    // Тест 1: Пустой массив
    {
        std::vector<int> arr;
        shuffleArray(arr);
        assert(arr.empty());
    }

    // Тест 2: Массив из одного элемента
    {
        std::vector<int> arr = {42};
        shuffleArray(arr);
        assert(arr.size() == 1 && arr[0] == 42);
    }

    // Тест 3: Массив из нескольких элементов
    {
        std::vector<int> arr = {1, 100, 10, 2};
        std::vector<int> original = arr;
        shuffleArray(arr);
        // Убедимся, что массив содержит те же элементы
        std::sort(arr.begin(), arr.end());
        std::sort(original.begin(), original.end());
        assert(arr == original);
    }

    // Тест 4: Большой массив
    {
        const int size = 1e6;
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = i;
        }
        shuffleArray(arr);
        // Проверим, что длина массива осталась неизменной
        assert(arr.size() == size);
        // Проверим, что все элементы присутствуют
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < size; ++i) {
            assert(arr[i] == i);
        }
    }

    std::cout << "All tests passed successfully!\n";
}

int main() {
    // Пример использования
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<int> arr(size);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    shuffleArray(arr);

    std::cout << "Shuffled array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Запуск тестов
    runTests();

    return 0;
}
//Сложность алгоритма:
//0(M log M) M=10^6