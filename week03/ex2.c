#include <stdio.h>
#include <stdlib.h>

// in place Bubble sort algorithm
void bubble_sort(int *data, int length);
// array printing function
void print_array(int *data, int length);

int main(int argc, char const *argv[]) {
	int n;

	// read number of elements
	printf("Enter number of elements: \n");
	scanf("%d", &n);

	// create array size of n
	int *d = (int *)malloc(sizeof(n) * n);

	// read elements
	printf("Enter %d numbers: \n", n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &d[i]);

	// output initial array
	printf("Initial array: ");
	print_array(d, n);

	// sort array
	bubble_sort(d, n);

	// output sorted array
	printf("Sorted array: ");
	print_array(d, n);

	return 0;
}

void bubble_sort(int *data, int length) {
	int sorted = 0;

	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < length - 1; ++i) {
			if (data[i] > data[i + 1]) {
				sorted = 0;
				int tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}

void print_array(int *data, int length) {
	for (int i = 0; i < length; ++i)
		printf("%d ", data[i]);

	printf("\n");
}

/*
void bubble_sort(int *data, int length) {
	for (int i = 0; i < length - 1; ++i) {
		for (int j = 0; j < length - i - 1; ++j) {
			if (data[j] > data[j + 1]) {
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}
*/
