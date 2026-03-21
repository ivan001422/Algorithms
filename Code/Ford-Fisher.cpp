#include <iostream>

using namespace std;

bool is_different(char x, char y) {
    return not(x == y);
}

int main() {
    char x[] = "hello";
    char y[] = "hel";

    int matrix[6][4] = { 0 };  

    for (int i = 0; i != 6; i++) matrix[i][0] = i;
    for (int i = 0; i != 4; i++) matrix[0][i] = i;

    // Алгоритм Форда-Фишера
    for (int i = 1; i != 6; ++i) {
        for (int j = 1; j != 4; ++j) {
            matrix[i][j] = min(
                min(matrix[i - 1][j], matrix[i][j - 1]) + 1,
                matrix[i - 1][j - 1] + is_different(x[i - 1], y[j - 1])
            );
        }
    }

    // Вывод матрицы
    for (int i = 0; i != 6; ++i) {
        for (int j = 0; j != 4; ++j) {
            cout << matrix[i][j] << " ";  
        }
        cout << '\n';
    }

    return 0;
}
