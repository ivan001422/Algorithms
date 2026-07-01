#include <iostream>
#include <vector>

using namespace std;

// Вспомогательная функция: максимум в векторе
int max(const vector<int> &vec) {
    int size = vec.size();
    int MAX = -1;
    for (int i = 0; i != size; ++i)  MAX = max(vec[i], MAX);
    return MAX;
}

// Вспомогательная функция: максимум из двух чисел
int max(int a, int b) {
    if (a >= b) return a;
    return b;
}

// Вывод треугольной матрицы на экран
void print(const vector<vector<int>> &matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k <= i; ++k) {
            cout << matrix[i][k] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int size = 7;                     // Размер горы (количество уровней)
    vector<vector<int>> matrix(size, vector<int>{0}); // DP-матрица для хранения максимальных сумм
    vector<vector<int>> hill =              // Гора (треугольник значений)
    {
        { 0 },                              // <-- Позиция кладоискателя (вершина)
        { 5, 8 },
        { 9, 8, 2 },
        { 1, 3, 5, 6 },
        { 6, 2, 4, 4, 5 },
        { 9, 5, 3, 5, 5, 7 },
        { 7, 4, 6, 4, 7, 6, 8 }
    };

    // Подготовка DP-матрицы: каждая строка i должна иметь размер i+1
    for (int i = 1; i != size; ++i) {
        for (int j = 0; j != i; ++j) matrix[i].push_back(0);
    }

    // Обработка базовых случаев: левый и правый край треугольника
    for (int i = 1; i != size; ++i) {
        matrix[i][0] = matrix[i - 1][0] + hill[i][0];        // спуск только вниз по левому краю
        matrix[i][i] = matrix[i - 1][i - 1] + hill[i][i];    // спуск только вниз-вправо по правому краю
    }

    // Заполнение остальных клеток по формуле динамического программирования
    for (int i = 2; i != size; ++i) {
        for (int j = 1; j != i; ++j) {
            // Максимум из двух возможных предыдущих позиций + текущее значение
            matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - 1]) + hill[i][j];
        }
    }

    // Красивый вывод полученной матрицы максимальных сумм
    print(matrix);
    // Ответ: максимальное значение в последней строке DP-матрицы
    cout << "    Answer: " << max(matrix.back());
    return 0;
}
