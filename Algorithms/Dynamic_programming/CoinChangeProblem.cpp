#include <iostream>
#include <vector>
/*
 * Задача о размене монет через ДП
 * Мемоизация: нет
 * Сложность: O(l^n)
 */
using namespace std;

int solve(int x);

vector<int> money = {1, 3, 4}; // Номиналы монет
int main() {
    cout << solve(10) << endl;    
}

int solve(int x) {
    if (x == 0) return 0; // База рекурсии
    else if (x < 0) return 1 << 30; // (1 << 30) = 1073741824

    int mn = solve(x - money[0]);
    for (int i = 1; i < money.size(); ++i) {
        int temp = solve(x - money[i]);
        if (temp < mn) mn = temp;
    }

    return mn + 1;
}
