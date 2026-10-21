#include <iostream>

#define INF 2147483647
using namespace std;

const int SUM = 10;
const int coins[3] = {1, 3, 4};
int main() {
    int temp[SUM+1] = {0};
    int path[SUM+1] = {0};

    // Итеративная реализация
    for (int i = 1; i <= SUM; ++i) {
        temp[i] = INF;
        for (int c: coins) {
            if (i - c >= 0 && temp[i - c] < INF && temp[i - c] + 1 < temp[i]) {
                temp[i] = temp[i - c] + 1;
                path[i] = c; // Значение монеты, которой мы пришли в сумму i в оптимальном решении.
            }
        }
    }

    if (temp[SUM] == INF) {
        cout << "No solution";
        return 0;
    }

    int n = SUM;
    while (n > 0) {
        cout << path[n] << ' ';
        n -= path[n];
    }
    

    
}
