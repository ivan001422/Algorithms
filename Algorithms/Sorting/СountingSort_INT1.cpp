#include <iostream>

using namespace std;

void CSort(int *arr, int max, int size); // Работает только для скалярных данных >= 0(после адаптации)

int main() {
    int arr[3] = { 1, 4, 2 };
    CSort(arr, 4, 3); // указатель, макс элемент, длина массива
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];

    return 0;
}

void CSort(int *arr, int max, int size) { // max можно находить и внутри(не сделано для краткости)
    int *narr = new int[max + 1] {}; // Инициализация нулями (избавляемся от мусора внутри)
    for (int i = 0; i < size; ++i) { // Заполняем новый массив
        narr[arr[i]]++; // лучше алгебра массивов из-за приоритета инкремента
    }
    for (int i = 0, t = 0; i < max + 1; ++i) { // индекс массива-подсчёта(какое число добавляем)
        for (int j = 0; j < narr[i]; ++j) arr[t++] = i; // сколько раз его добавить
    }
    delete[] narr; // удаляем данные из кучи
}
