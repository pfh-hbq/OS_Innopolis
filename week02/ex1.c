#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;

	printf("Size of integer: %lu\n\n", sizeof(a));
	printf("Size of float: %lu\n\n", sizeof(b));
	printf("Size of double: %lu\n\n", sizeof(c));

	printf("Value of integer: %d\n\n", a);
	printf("Value of float: %f\n\n", b);
	printf("Value of double: %f\n\n", c);

	return 0;
}