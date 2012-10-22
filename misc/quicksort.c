#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

#define SWAP(x, y) {int t = x; x = y; y = t;}

void quicksort(int *data, int left, int right) {
	int i = left;
	int j = right + 1;

	if (left >= right)
		return;

	while (1) {
		while (i + 1 < right && data[++i] < data[left])
			;
		while (j - 1 >= left && data[--j] > data[left])
			;
		if (i >= j)
			break;
		//printf("i = %d, j = %d\n", i, j);
		SWAP(data[i], data[j]);
	}

	SWAP(data[j], data[left]);

	printf("sorting\n");
	for (i = 0; i < MAX; ++i) {
		printf("%d  ", data[i]);
	}
	printf("\n");

	quicksort(data, left, j - 1);
	quicksort(data, j + 1, right);
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int number[MAX] = {0};
	srand(time(NULL));

	printf("before sorting\n");

	for (i = 0; i < MAX; ++i) {
		number[i] = rand() % 100;
		printf("%d  ", number[i]);
	}

	printf("\n");

	quicksort(number, 0, MAX - 1);

	printf("after sorting\n");
	for (i = 0; i < MAX; ++i) {
		printf("%d  ", number[i]);
	}
	printf("\n");

	return 0;
}
