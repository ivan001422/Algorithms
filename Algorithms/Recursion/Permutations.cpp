#include <iostream>
#include <vector>

using namespace std;

// === Глобальные переменные для рекурсивной генерации ===

int n = 3;                 // Количество элементов в перестановке (можно менять)
vector<int> vec;           // Текущая перестановка (строится постепенно)
vector<bool> arr;          // arr[i] = true, если число i уже использовано

// Прототипы функций
void print(vector<int> vec);
void permutations();

int main() {
    
    arr.assign(n + 1, false); // Инициализируем массив размером n+1 (индексы от 0 до n, 0 не используется)
    permutations(); // Запускаем генерацию всех перестановок
  
    return 0;
}

void permutations() {
    // Базовый случай – перестановка полностью построена
    if (vec.size() == n) { print(vec); return; }  // выводим готовую перестановку

    // Рекурсивный перебор кандидатов для следующей позиции
    for (int i = 1; i <= n; ++i) {
        if (arr[i]) continue;          // число уже использовано – пропускаем

        // Выбираем число i
        arr[i] = true;                 // отмечаем как занятое
        vec.push_back(i);              // добавляем в перестановку

        permutations();                // рекурсивно заполняем оставшиеся позиции

        // Откат (backtrack) – освобождаем число для других перестановок
        arr[i] = false;                // снимаем отметку
        vec.pop_back();                // убираем i из конца вектора
    }
}

void print(vector<int> vec) {
    cout << "{ ";
    for (int i = 0; i != vec.size(); ++i) {
        cout << vec[i] << ' ';
    }
    cout << "}\n";
}
