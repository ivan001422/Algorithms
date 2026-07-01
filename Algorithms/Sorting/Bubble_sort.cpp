#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    // Bubble sort

    short int list[10] = { 1, -2, 4, 34, 16, 8, 9, 10, 10, -17 };

    while (true) {
        bool Flag = 1;
        for (short int list_inx = 0; list_inx < 9; list_inx++) {
            if (list[list_inx + 1] < list[list_inx]) { short int sup = list[list_inx]; list[list_inx] = list[list_inx + 1]; list[list_inx + 1] = sup; Flag = 0; }
        }
        if (Flag) break;
    }

    for (int i = 0; i < 10; i++) cout << list[i] << "\n";

}
