#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pyramid(int n);
void right_triangle(int n);
void half_rhombus(int n);
void rectangle(int n);

int main(int argc, char const *argv[]) {
	
	int n = atoi(argv[1]);
	
	for (;;) {
		int figurID = 0;

		printf("Choose figure:\n1 - Pyramid\n2 - Right Triangle\n3 - Half Rombus\n4 - Rectangle\n0 - Quit\nFigur: ");
		scanf("%d", &figurID);

		if (figurID == 0)
			break;
		else if (figurID == 1)
			pyramid(n);
		else if (figurID == 2)
			right_triangle(n);
		else if (figurID == 3)
			half_rhombus(n);
		else if (figurID == 4)
			rectangle(n);
	}

	return 0;
}

void pyramid(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j)
			printf("%c", ' ');

		for (int j = 0; j <= i; ++j)
			printf("%c", '*');

		for (int j = 0; j < i; ++j)
			printf("%c", '*');

		printf("\n");
	}
}

void right_triangle(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			printf("%c", '*');

		printf("\n");
	}
}

void half_rhombus(int n) {
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j <= i; ++j)
			printf("%c", '*');

		printf("\n");
	}

	if (n % 2 != 0) {
		for (int i = 0; i <= n / 2; ++i)
			printf("%c", '*');
		printf("\n");
	}

	for (int i = n / 2 - 1; i >= 0; --i) {
		for (int j = i; j >= 0; --j)
			printf("%c", '*');

		printf("\n");
	}
}

void rectangle(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%c", '*');

		printf("\n");
	}
}