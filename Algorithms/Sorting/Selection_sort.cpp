#include <iostream>

using namespace std;

void selection_sort(int* start, int* end);
void swap(int* a, int* b);

// Selection sort

int main() {
	int arr[] = { -14, -12 , 15 };
	const int size = sizeof(arr) / sizeof(int);
	selection_sort(arr, arr + size);
	for (int i = 0; i != size; i++) cout << *(arr + i) << "\n";
}

void selection_sort(int* start, int* end) {
	int size = end - start;

	for (int cntr = 0; cntr != size - 1; cntr++) {
		int* inx = start + cntr;
		int* MIN = inx;

		for (; inx != end; inx++) {
			if (*inx < *MIN) MIN = inx;
		}

		if (MIN != start + cntr) {
			swap(MIN , start + cntr);
		}
	}
}

void swap(int* a, int* b) {
	int help = *a;

	*a = *b;
	*b = help;

}
