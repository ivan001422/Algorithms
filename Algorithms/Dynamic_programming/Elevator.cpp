#include <iostream>
#include <algorithm>

using namespace std;

// Задача о лифте
int main() {
    const int n = 5; // кол-во людей всего
    int x = 12; // макс грузоподъемность
    int weight[n] = {2, 3, 4, 5, 9}; // веса людей
    
    // best[mask] = {кол-во поездок, вес последней поездки}
    pair<int, int> best[1 << n]; 

    // Изначально у нас 1 пустая поездка, вес 0
    best[0] = {1, 0}; 

    for (int i = 1; i < (1 << n); ++i) { 
        best[i] = {n + 1, 0}; // (худший вариант)
        
        for (int p = 0; p < n; ++p) { 
            // Если человек p есть в текущей маске
            if (i & (1 << p)) {
                // Состояние БЕЗ этого человека
                auto optional = best[i ^ (1 << p)];
                
                // Пытаемся посадить человека p в последнюю поездку
                if (optional.second + weight[p] <= x) {
                    optional.second += weight[p]; // Влез, просто добавили вес
                } else {
                    optional.first++; // Не влез, нужна новая поездка
                    optional.second = weight[p]; 
                }
                
                // Выбираем лучший вариант (сначала по кол-ву поездок, потом по весу)
                best[i] = min(optional, best[i]); 
            } 
        }
    } 
    
    // Ответ для полного множества (все биты = 1)
    cout << best[(1 << n) - 1].first; 
}
