#include <iostream>

using namespace std;

const int w_size = 4;
const int weights[w_size] = {1, 3, 3, 5};

int main() {
    int sm = 0;
    for (int w : weights) sm += w;
    
    bool possible[w_size + 1][sm + 1] = {};
    
    // 2. тривиальный случай
    possible[0][0] = true;

    for (int i = 1; i <= w_size; ++i) {
        for (int j = 0; j <= sm; ++j) {
            
            // (копируем инфу из строки выше)
            possible[i][j] |= possible[i-1][j];
            
            if (j - weights[i-1] >= 0) {
                possible[i][j] |= possible[i-1][j - weights[i-1]];
            }
        }
    }

    // Вывод 
    for (int i = 0; i <= w_size; ++i) {
        for (int j = 0 ; j <= sm ; ++j) {
            cout << possible[i][j] << ' ';
        }
        cout << '\n';
    }
}
