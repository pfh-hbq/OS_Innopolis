#include <stdio.h>

void swap(int *a, int *b) {
	int p = *a;
	*a = *b;
	*b = p;
}

int main(int argc, char const *argv[]) {
	
	int a = 0, b = 0;

	printf("Write first number: ");
	scanf("%d", &a);

	printf("Write second number: ");
	scanf("%d", &b);

	swap(&a, &b);

	printf("First: %d\nSecond: %d\n", a, b);

	return 0;
}