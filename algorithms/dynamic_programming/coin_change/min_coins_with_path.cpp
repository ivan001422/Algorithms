#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

/*
 * Задача о размене монет.
 *
 * coins - номиналы монет (отсортированы).
 * SUM - сумма для размена.
 * dp[i] - минимальное количество монет для суммы i.
 * path[i] - последняя выбранная монета для суммы i.
 * Память: O(SUM)
 * Время: O(SUM * size(coins))
 */

constexpr int INF = numeric_limits<int>::max();

const int coins[] = {2, 3, 4};
const int SUM = 1;

int main() {
    int dp[SUM + 1] = {0};
    int path[SUM + 1];

    // Инициализируем путь значением -1 
    fill(path, path + SUM + 1, -1);

    // Вычисляем минимальное количество монет
    for (int i = 1; i <= SUM; ++i) {
        dp[i] = INF;

        for (const int c : coins) {
            if (c > i) break;
            if (dp[i - c] == INF) continue;

            if (dp[i - c] + 1 < dp[i]) {
                dp[i] = dp[i - c] + 1;
                path[i] = c;
            }
        }
    }

    // Проверяем, существует ли решение
    if (dp[SUM] == INF) {
        cout << "No solution\n";
        return 0;
    }

    cout << dp[SUM] << '\n';

    // Восстанавливаем использованные монеты
    for (int sum = SUM; sum > 0; sum -= path[sum]) {
        cout << path[sum] << ' ';
    }

    cout << '\n';
    return 0;
}
