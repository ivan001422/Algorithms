#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

bool Bin_search(const int arr[], int len, int target);

int main(void) {

	int arr[SIZE] = { 1,2,3,4,5 };
	printf("%d\n", Bin_search(arr, SIZE, 3));


	return 0;
}

bool Bin_search(const int arr[], int len, int target) {
	int r = len - 1, l = 0, mid;

	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] > target) r = mid - 1;

		else if (arr[mid] < target) l = mid + 1;

		else return true;
	}

	return false;
			
}
