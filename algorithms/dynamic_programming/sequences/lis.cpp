#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Наибольшая возрастающая подпоследовательность (LIS), O(n²)
 * arr = {6, 2, 5, 1, 7, 4, 8, 3}  ->  ответ 4 (2, 5, 7, 8)
 */

const int SIZE = 8;
int main() {
    int arr[SIZE] = {6, 2, 5, 1, 7, 4, 8, 3};
    int temp[SIZE];

    for (int k = 0; k != SIZE; ++k) {
        temp[k] = 1;
        for (int i = 0; i != k ; ++i) {
            if (arr[i] < arr[k]) {
                temp[k] = max(temp[k], temp[i] + 1);
            }
        }
    }

    cout << *max_element(temp, temp + SIZE) << '\n';
}
