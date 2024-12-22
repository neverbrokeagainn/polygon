#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>

std::vector<int> countOccurrences(const std::vector<std::string>& arr) {
    std::unordered_map<std::string, int> frequency;
    std::vector<int> result;

    // Подсчет частотности каждого элемента
    for (const auto& item : arr) {
        frequency[item]++;
    }

    // Формирование результата
    for (const auto& item : arr) {
        result.push_back(frequency[item]);
    }

    return result;
}

void runTests() {
    // Тест 1: Базовый пример
    {
        std::vector<std::string> input = {"Orange", "Red", "Green", "Orange"};
        std::vector<int> expected = {2, 1, 1, 2};
        assert(countOccurrences(input) == expected);
    }

    // Тест 2: Все элементы уникальны
    {
        std::vector<std::string> input = {"A", "B", "C", "D"};
        std::vector<int> expected = {1, 1, 1, 1};
        assert(countOccurrences(input) == expected);
    }

    // Тест 3: Все элементы одинаковы
    {
        std::vector<std::string> input = {"Same", "Same", "Same", "Same"};
        std::vector<int> expected = {4, 4, 4, 4};
        assert(countOccurrences(input) == expected);
    }

    // Тест 4: Пустой массив
    {
        std::vector<std::string> input = {};
        std::vector<int> expected = {};
        assert(countOccurrences(input) == expected);
    }

    // Тест 5: Смешанные строки
    {
        std::vector<std::string> input = {"Apple", "Banana", "Apple", "Banana", "Apple"};
        std::vector<int> expected = {3, 2, 3, 2, 3};
        assert(countOccurrences(input) == expected);
    }

    std::cout << "All tests passed!\n";
}

int main() {
    // Вызов тестов
    runTests();

    // Входные данные
    int size = 4;
    std::vector<std::string> arr = {"Orange", "Red", "Green", "Orange"};

    // Получение результата
    std::vector<int> result = countOccurrences(arr);

    // Вывод результата
    for (int count : result) {
        std::cout << count << " ";
    }

    return 0;
}
//для массива arr = 152 байта, для std::unordered_map = 162 байта, для result = 16 байт, переменные = 64 байта, общая 152+162+16+64=394 байта