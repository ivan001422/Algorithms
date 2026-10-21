#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * Задача о размене монет, top-down DP (мемоизация)
 * Сложность: O(n * l), l = money.size()
 * Память:    O(n)
 */
constexpr int INF = 1 << 30; // Value = 1073741824
const vector<int> money = {1, 3, 4};

int solve(int x, vector<int>& memo) {
    if (x == 0) return 0;
    if (x < 0)  return INF;
    if (memo[x] != -1) return memo[x];

    int mn = INF;
    for (int c : money)
        mn = min(mn, solve(x - c, memo));

    if (mn >= INF) return memo[x] = INF;   // недостижимо
    return memo[x] = mn + 1;
}

int main() {
    int n = 10;
    vector<int> memo(n + 1, -1);
    int ans = solve(n, memo);
    cout << (ans >= INF ? -1 : ans) << '\n';   // проверка на существование ответа
}
