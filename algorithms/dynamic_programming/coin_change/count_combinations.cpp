#include <iostream>

using namespace std;

// Подсчёт кол-ва решений(порядок не важен)
const int SUM = 5;
const int coins[3] = {1, 3, 4};
int main() {
    int temp[SUM+1] = {0};

    temp[0] = 1;
    for (int c: coins) {
        for (int i = 1; i <= SUM ; ++i) {
            if (i - c >= 0) {
                temp[i] += temp[i-c];
            }
        }
    }

    cout << temp[SUM];
}
