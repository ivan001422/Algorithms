#include <iostream>
using namespace std;

const int n = 4;
bool s[n];              // столбцы (занят/свободен)
bool r[2 * n - 1];      // главные диагонали (row - col)
bool l[2 * n - 1];      // побочные диагонали (row + col)

int cnt = 0;

void f(int k);

int main() {
    // Инициализация не нужна — глобальные массивы уже false
    f(0);
    cout << cnt;
    return 0;
}

void f(int k) {
    if (k == n) {        // Все ферзи расставлены
        cnt += 1;
        return;
    }

    for (int z = 0; z < n; ++z) {
        // Проверяем, свободны ли столбец и обе диагонали
        if (!s[z] and !r[k + z] and !l[k - z + n - 1]) {
            // Ставим ферзя
            s[z] = r[k + z] = l[k - z + n - 1] = true;

            f(k + 1);     // Переходим к следующей строке

            // Убираем ферзя (backtracking)
            s[z] = r[k + z] = l[k - z + n - 1] = false;
        }
    }
}
