#include <iostream>

#define INF 2147483647
using namespace std;

const int SUM = 10;
const int coins[3] = {1, 3, 4};
int main() {
    int temp[SUM+1] = {0};

    // Итеративная реализация
    for (int i = 1; i <= SUM; ++i) {
        temp[i] = INF;
        for (auto c: coins) {
            if (i - c >= 0) {
                temp[i] = temp[i-c] >= temp[i] ? temp[i] : temp[i - c] + 1; 
            }
        }
    }

    cout << (temp[SUM] == INF ? -1 : temp[SUM]); // Проверка на существование решения
}
