#include <stdio.h>

int main() {
	int n;

	printf("Enter number of elements: \n");
	scanf("%d", &n);

	int *array = malloc(n*sizeof(int));

	for (int i = 0; i < n; ++i) {
		array[i] = i;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}

	free(array);

	return 0;
}