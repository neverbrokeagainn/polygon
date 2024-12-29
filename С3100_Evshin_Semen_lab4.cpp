#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Функция для поиска всех подмассивов размера K с суммой 0
vector<vector<int>> findSubarraysWithZeroSum(const vector<int>& arr, int K) {
    vector<vector<int>> result;
    int N = arr.size();

    // Проходим по массиву с начала до N-K+1, чтобы сформировать подмассивы размера K
    for (int i = 0; i <= N - K; ++i) {
        int sum = 0;
        vector<int> indices;

        // Формируем подмассив размера K
        for (int j = 0; j < K; ++j) {
            sum += arr[i + j];
            indices.push_back(i + j);
        }

        // Проверяем, равна ли сумма элементов подмассива 0
        if (sum == 0) {
            result.push_back(indices);
        }
    }

    return result;
}

int main() {
    // Тестовые случаи
    vector<int> testCase1 = {1, 1, -1, -1}; // Ожидается вывод: [0, 1], [2, 3]
    int K1 = 2;

    clock_t start = clock();
    cout << "Test Case 1:\n";
    auto result1 = findSubarraysWithZeroSum(testCase1, K1);
    for (const auto& subarray : result1) {
        cout << "[";
        for (size_t i = 0; i < subarray.size(); ++i) {
            cout << subarray[i] << (i < subarray.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    clock_t end = clock();
    cout << "Time taken: " << double(end - start) / CLOCKS_PER_SEC << " seconds.\n\n";

    vector<int> testCase2 = {1, 2, -3, 3, -1}; // Ожидается вывод: [0, 1, 2]
    int K2 = 3;
    start = clock();
    cout << "Test Case 2:\n";
    auto result2 = findSubarraysWithZeroSum(testCase2, K2);
    for (const auto& subarray : result2) {
        cout << "[";
        for (size_t i = 0; i < subarray.size(); ++i) {
            cout << subarray[i] << (i < subarray.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    end = clock();
    cout << "Time taken: " << double(end - start) / CLOCKS_PER_SEC << " seconds.\n\n";

    vector<int> testCase3 = {0, 0, 0, 0}; // Ожидается вывод: [0, 1], [1, 2], [2, 3] и другие
    int K3 = 2;
    start = clock();
    cout << "Test Case 3:\n";
    auto result3 = findSubarraysWithZeroSum(testCase3, K3);
    for (const auto& subarray : result3) {
        cout << "[";
        for (size_t i = 0; i < subarray.size(); ++i) {
            cout << subarray[i] << (i < subarray.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    end = clock();
    cout << "Time taken: " << double(end - start) / CLOCKS_PER_SEC << " seconds.\n\n";

    vector<int> testCase4 = {5, -5, 10, -10}; // Ожидается вывод: [0, 1], [2, 3]
    int K4 = 2;
    start = clock();
    cout << "Test Case 4:\n";
    auto result4 = findSubarraysWithZeroSum(testCase4, K4);
    for (const auto& subarray : result4) {
        cout << "[";
        for (size_t i = 0; i < subarray.size(); ++i) {
            cout << subarray[i] << (i < subarray.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    end = clock();
    cout << "Time taken: " << double(end - start) / CLOCKS_PER_SEC << " seconds.\n\n";

    vector<int> testCase5 = {1, -1, 2, -2, 3, -3}; // Ожидается вывод: [0, 1], [2, 3], [4, 5]
    int K5 = 2;
    start = clock();
    cout << "Test Case 5:\n";
    auto result5 = findSubarraysWithZeroSum(testCase5, K5);
    for (const auto& subarray : result5) {
        cout << "[";
        for (size_t i = 0; i < subarray.size(); ++i) {
            cout << subarray[i] << (i < subarray.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    end = clock();
    cout << "Time taken: " << double(end - start) / CLOCKS_PER_SEC << " seconds.\n";

    return 0;
}
